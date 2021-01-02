modded class MissionServer extends MissionBase
{
	
	static const string PREFIX = "[MY_MISSION_SERVER]: ";

	ref SetupPlayerOptions SPOptions;

	// ref HHWeaponDeletion hh_weaponDeletion;
	
	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			float rndHlt = Math.RandomFloat( 0.45, 0.65 );
			itemEnt.SetHealth01( "", "", rndHlt );
		}
	}

	void MissionServer () {
		if (GetGame().IsServer()) {
			// check folder existance
			if (!FileExist(S_ROOTFOLDER)) MakeDirectory(S_ROOTFOLDER);

			// check file existance and get setup options
			if (!FileExist(S_ROOTFOLDER + "SetupPlayerOptions.json")) {
				SPOptions = new SetupPlayerOptions();
				SPOptions.InitPlayerSetups();
			} else {
				JsonFileLoader<ref SetupPlayerOptions>.JsonLoadFile(S_ROOTFOLDER + "SetupPlayerOptions.json", SPOptions );	
			}
			JsonFileLoader<ref SetupPlayerOptions>.JsonSaveFile(S_ROOTFOLDER + "SetupPlayerOptions.json",  SPOptions);			
		}
	}

	// override void OnInit() {
	// 	super.OnInit();


	// 	ref array<Object> proche_objects = new array<Object>;
 //        ref array<CargoBase> proxy_cargos = new array<CargoBase>;

 //        vector pos = "8294.81 0 2915.43";

 //        pos[1] = GetGame().SurfaceY(pos[0], pos[2]);

 //        GetGame().GetObjectsAtPosition(pos, 10000, proche_objects, proxy_cargos);

 //        // foreach (auto el : proche_objects) {
 //        // 	if (!el.IsInherited( ItemBase ))
 //        // 		continue;

 //        // 	GetGame().ObjectDelete(el);
 //        // 	Print("deleting : " + el.GetType() + " : ");
 //        // }	

 //        for (int i = 0; i < proche_objects.Count(); i++) 
 //        {
 //            if ( proche_objects.Get( i ).IsInherited(Object) )
 //            {
 //                Object actor_in_radius = proche_objects.Get(i);
 //                if ( (actor_in_radius.IsInherited( ItemBase ) ) )
 //                {
 //                	Print("im deleting that fucking shit" + actor_in_radius.GetType());
 //                  GetGame().ObjectDelete(actor_in_radius);
 //                }
 //            }
 //        }

	// }


	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		EntityAI itemClothing;
		EntityAI itemEnt;
		EntityAI weapon;
		EntityAI helmet;
		EntityAI vest;
		ItemBase itemBs;
		float rand;

		player.RemoveAllItems();

		JsonFileLoader<ref SetupPlayerOptions>.JsonLoadFile(S_ROOTFOLDER + "SetupPlayerOptions.json", SPOptions );
		PlayerSet playerSet = SPOptions.PlayerSetups.GetRandomElement();

		// создание шлема и его обвесов
		helmet = player.GetInventory().CreateInInventory(playerSet.Helmet);
		for (int j = 0; j < playerSet.HelmetAttachments.Count(); j++) {
			helmet.GetInventory().CreateAttachment(playerSet.HelmetAttachments[j]);
		}

		vest = player.GetInventory().CreateInInventory(playerSet.Vest);
		for (int m = 0; m < playerSet.VestAttachments.Count(); m++) {
			vest.GetInventory().CreateAttachment(playerSet.VestAttachments[m]);
		}

			// создание одежды
		for (int i = 0; i < playerSet.Clothes.Count(); i++) {
			player.GetInventory().CreateInInventory(playerSet.Clothes[i]);
		}


		// // создание оружия и его обвесов
		// weapon = player.GetHumanInventory().CreateInHands(playerSet.Weapon);
		// player.SetQuickBarEntityShortcut(weapon, 0);


		// for (int z = 0; z < playerSet.WeaponAttachments.Count(); z++) {
		// 	weapon.GetInventory().CreateAttachment(playerSet.WeaponAttachments[z]);
		// }

		itemClothing = player.FindAttachmentBySlotName( "Body" );

		// создание внутренней экипировки
		if ( itemClothing )
		{
			// itemEnt = itemClothing.GetInventory().CreateInInventory( "Rag" );
			// if (Class.CastTo( itemBs, itemEnt )) itemBs.SetQuantity( 6 );
			
			for (int k = 0; k < playerSet.Equipment.Count(); k++) {
				player.GetInventory().CreateInInventory(playerSet.Equipment[k]);
			}
		}

		// ReloadWeapon( EntityAI weapon, EntityAI magazine )
		// player.QuickReloadWeapon(weapon);






		// создание оружия и его обвесов
		weapon = player.GetHumanInventory().CreateInHands(playerSet.Weapon);
		player.SetQuickBarEntityShortcut(weapon, 0);


		for (int z = 0; z < playerSet.WeaponAttachments.Count(); z++) {
			weapon.GetInventory().CreateAttachment(playerSet.WeaponAttachments[z]);
		}



		Weapon_Base wp = Weapon_Base.Cast(weapon);
		string magazine_type = playerSet.MagType;

		int stateId = -1;

		if ( wp.IsInherited( SKS_Base ) )
		{
			return;
		} else if ( wp.IsInherited( BoltActionRifle_InnerMagazine_Base ) )
		{
			return;
		} else if ( wp.IsInherited( DoubleBarrel_Base ) )
		{
			return;
		} else if ( wp.IsInherited( Pistol_Base ) )
		{
			stateId = PistolStableStateID.CLO_DIS_BU0_MA1;
		} else if ( wp.IsInherited( CZ527_Base ) )
		{
			stateId = CZ527StableStateID.CZ527_CLO_BU0_MA1;
		} else if ( wp.IsInherited( Repeater_Base ) )
		{
			return;
		} else if ( wp.IsInherited( RifleBoltFree_Base ) )
		{
			stateId = RBFStableStateID.RBF_CLO_BU0_MA1;
		} else if ( wp.IsInherited( RifleBoltLock_Base ) )
		{
			stateId = RBLStableStateID.RBL_OPN_BU0_MA1;
		} else if ( wp.IsInherited( Mp133Shotgun_Base ) )
		{
			return;
		}

		InventoryLocation il = new InventoryLocation;
		il.SetAttachment( wp, NULL, InventorySlots.MAGAZINE );

		// using any of the inventory sync for existing spawning magazines also works
		// e.g. GameInventory.LocationSyncMoveEntity

		EntityAI mag = SpawnEntity( magazine_type, il, ECE_IN_INVENTORY, RF_DEFAULT );
		GetGame().RemoteObjectDelete( mag );
		GetGame().RemoteObjectDelete( wp );

		pushToChamberFromAttachedMagazine( wp, wp.GetCurrentMuzzle() );

		ScriptReadWriteContext ctx = new ScriptReadWriteContext;
		ctx.GetWriteContext().Write( stateId );
		wp.LoadCurrentFSMState( ctx.GetReadContext(), GetGame().SaveVersion() );

		GetGame().RemoteObjectCreate( wp );
		GetGame().RemoteObjectCreate( mag );
	}

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{	
		Print("InvokeOnConnect:" + this.ToString());

		PluginPlayersTop m_PlStat = PluginPlayersTop.Cast(GetPlugin(PluginPlayersTop));

		if (player.GetIdentity()) {
			ref PlayerStatisticInfo _plData;
			string steamId = player.GetIdentity().GetPlainId();

			if (FileExist(S_PLAYERS) && FileExist(S_PLAYERS + steamId + ".json")) {
				JsonFileLoader<ref PlayerStatisticInfo>.JsonLoadFile(S_PLAYERS + steamId + ".json", _plData);
				_plData.setPlayerName(player.GetIdentity().GetName());
				
				Print("Player " + player.GetIdentity().GetName() + " ("+ steamId + ")" + " connected to the server!");
			} else { 
				_plData = new PlayerStatisticInfo(); 
				_plData.setSteamId(player.GetIdentity().GetPlainId());
				_plData.setPlayerName(player.GetIdentity().GetName());
				JsonFileLoader<ref PlayerStatisticInfo>.JsonSaveFile(S_PLAYERS + steamId + ".json", _plData);
			}
			
			auto param4 = new Param4<string, string, string, string>(_plData.playerName, _plData.kills.ToString(), _plData.deadth.ToString(), _plData.maxRangeKill.ToString());
			GetGame().RPCSingleParam(player, HHRPCEnum.RPC_CLIENT_UPDATE_TOP, param4, true, player.GetIdentity());

		}


		super.InvokeOnConnect(player, identity);
	}


	void SendMessage(string message)
    {
        if (GetGame().IsServer())
        {
            ref array<Man> players = new array<Man>;
            GetGame().GetPlayers( players );
            foreach( auto player : players  )
            {
                Param1<string> m_MessageParam = new Param1<string>(message);
                GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, m_MessageParam, true, player.GetIdentity());
            }
        }
    }
}