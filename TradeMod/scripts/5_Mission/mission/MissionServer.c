modded class MissionServer extends MissionBase
{
	protected PluginDeveloper m_Developer;

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

		m_Developer	= PluginDeveloper.Cast( GetPlugin(PluginDeveloper) );
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




		// if (!m_Developer)
		// 	m_Developer = PluginDeveloper.Cast( GetPlugin(PluginDeveloper) );

		// создание оружия и его обвесов
		weapon = player.GetHumanInventory().CreateInHands(playerSet.Weapon);

		SpawnEntityInInventory(player, playerSet.MagType, -1, 1);

		for (int z = 0; z < playerSet.WeaponAttachments.Count(); z++) {
			weapon.GetInventory().CreateAttachment(playerSet.WeaponAttachments[z]);
		}
		player.SetQuickBarEntityShortcut(weapon, 0);
	}



	SpawnEntityInInventory (PlayerBase player, string item_name, float health, float quantity)
	{
		if( player )
		{
			if ( GetGame().IsServer() )

			// полураб
			// {
			// 	EntityAI itemInHands = player.GetHumanInventory().GetEntityInHands();

			// 	InventoryLocation il = new InventoryLocation;
			// 	itemInHands.GetInventory().GetCurrentInventoryLocation(il);

			// 	vector pos = player.GetPosition();
			// 	EntityAI eai_gnd = spwnEntityGrn(player, item_name, health, quantity, pos);
			// 	Magazine mag_gnd = Magazine.Cast(eai_gnd);
			// 	Weapon_Base wpn = Weapon_Base.Cast(itemInHands);

			// 	Print("пытаюсь добавить магазин в оружие");

			// 	if (mag_gnd && player.GetWeaponManager().CanAttachMagazine(wpn, mag_gnd))
			// 	{
			// 		player.GetWeaponManager().AttachMagazine(mag_gnd);
			// 		Print("Вроде как добавил магазин в оружие");
			// 	}

			// 	return eai_gnd;
			// }

			{
				if ( item_name == "" ) return;

				string magazine_type = item_name;

				EntityAI itemInHands = player.GetHumanInventory().GetEntityInHands();

				InventoryLocation il = new InventoryLocation;
				itemInHands.GetInventory().GetCurrentInventoryLocation(il);

				Weapon_Base wpn = Weapon_Base.Cast(itemInHands);


				int stateId = -1;

				if 		( wpn.IsInherited( SKS_Base ) ) 							return;
				else if ( wpn.IsInherited( BoltActionRifle_InnerMagazine_Base ) ) 	return;
				else if ( wpn.IsInherited( DoubleBarrel_Base ) ) 					return;
				else if ( wpn.IsInherited( Repeater_Base ) ) 						return;
				else if ( wpn.IsInherited( Mp133Shotgun_Base ) ) 					return;
				else if ( wpn.IsInherited( Pistol_Base ) )							stateId = PistolStableStateID.CLO_DIS_BU0_MA1;
				else if ( wpn.IsInherited( CZ527_Base ) )							stateId = CZ527StableStateID.CZ527_CLO_BU0_MA1;
				else if ( wpn.IsInherited( RifleBoltFree_Base ) )					stateId = RBFStableStateID.RBF_CLO_BU0_MA1;
				else if ( wpn.IsInherited( RifleBoltLock_Base ) )					stateId = RBLStableStateID.RBL_OPN_BU0_MA1;

				il.SetAttachment( wpn, NULL, InventorySlots.MAGAZINE );

				EntityAI mag = SpawnEntity( magazine_type, il, ECE_IN_INVENTORY, RF_DEFAULT );
				GetGame().RemoteObjectDelete( mag );
				GetGame().RemoteObjectDelete( wpn );

				pushToChamberFromAttachedMagazine( wpn, wpn.GetCurrentMuzzle() );

				ScriptReadWriteContext ctx = new ScriptReadWriteContext;
				ctx.GetWriteContext().Write( stateId );
				wpn.LoadCurrentFSMState( ctx.GetReadContext(), GetGame().SaveVersion() );

				GetGame().RemoteObjectCreate( wpn );
				GetGame().RemoteObjectCreate( mag );
			}
		}
	}

	// EntityAI spwnEntityGrn (PlayerBase player, string item_name, float health, float quantity, vector pos)
	// {
	// 	if ( GetGame().IsServer() )
	// 	{		
	// 		EntityAI entity = player.SpawnEntityOnGroundPos(item_name, pos);
	// 		if (entity) {
	// 			health = entity.GetMaxHealth();
	// 			SetupSpawnedEntity(entity, health, quantity);
	// 		}

	// 		return entity;
	// 	}

	// 	return NULL;
	// }

	// void SetupSpawnedEntity (EntityAI entity, float health, float quantity, bool special = false)
	// {

	// 	if ( entity.IsInherited( PlayerBase ) ) 
	// 	{
	// 		PlayerBase plr = PlayerBase.Cast( entity );
	// 		plr.OnSpawnedFromConsole();
	// 	}
	// 	else if ( entity.IsInherited(ItemBase) )
	// 	{
	// 		ItemBase item = ItemBase.Cast( entity );
	// 		SetupSpawnedItem(item, health, quantity);
	// 	}
	// }

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{	
		Print("InvokeOnConnect:" + this.ToString());

		PluginPlayersTop m_PlStat = PluginPlayersTop.Cast(GetPlugin(PluginPlayersTop));

		if (player.GetIdentity()) {
			ref PlayerStatisticInfo _plData;
			string steamId = player.GetIdentity().GetPlainId();

			SendMessage(player.GetIdentity().GetName() + " присоединился на сервер!")

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