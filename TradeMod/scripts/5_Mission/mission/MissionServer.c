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

		// IngameHud hud = GetHud();

		player.RemoveAllItems();

		// check file existance and get setup options
		if (!FileExist(S_ROOTFOLDER + "SetupPlayerOptions.json")) {
			SPOptions = new SetupPlayerOptions();
			SPOptions.InitPlayerSetups();
			JsonFileLoader<ref SetupPlayerOptions>.JsonSaveFile(S_ROOTFOLDER + "SetupPlayerOptions.json",  SPOptions);	
		} else {
			JsonFileLoader<ref SetupPlayerOptions>.JsonLoadFile(S_ROOTFOLDER + "SetupPlayerOptions.json", SPOptions );	
		}		

		PlayerSet playerSet = SPOptions.PlayerSetups.GetRandomElement();

		// создание шлема и его обвесов
		helmet = player.GetInventory().CreateInInventory(playerSet.Helmet);
		for (int j = 0; j < playerSet.HelmetAttachments.Count(); j++)
			helmet.GetInventory().CreateAttachment(playerSet.HelmetAttachments[j]);

		// оздание броника и его обвесов
		vest = player.GetInventory().CreateInInventory(playerSet.Vest);
		for (int m = 0; m < playerSet.VestAttachments.Count(); m++)
			vest.GetInventory().CreateAttachment(playerSet.VestAttachments[m]);

		// создание одежды
		for (int i = 0; i < playerSet.Clothes.Count(); i++)
			player.GetInventory().CreateInInventory(playerSet.Clothes[i]);

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

		// создание оружия и его обвесов
		weapon = player.GetHumanInventory().CreateInHands(playerSet.Weapon);
		// spawnMagazineInWeapon(player, weapon, playerSet.MagType);
		


		for (int z = 0; z < playerSet.WeaponAttachments.Count(); z++) {
			itemEnt = weapon.GetInventory().CreateAttachment(playerSet.WeaponAttachments[z]);

			switch (playerSet.WeaponAttachments[z]) {
				case "KobraOptic":
				case "M680Optic":
				case "M4_T3NRDSOptic":
				case "HH_OKP7Optic":
				case "FN45_MRDSOptic":
					itemEnt.GetInventory().CreateAttachment("Battery9V");
					break;
			}
		}
		player.SetQuickBarEntityShortcut(weapon, 0);

		if (playerSet.Weapon2 != "") {
			// создание оружия и его обвесов
			weapon = player.GetHumanInventory().CreateInInventory(playerSet.Weapon2);
			spawnMagazineInWeapon(player, weapon, playerSet.MagType2);

			for (int q = 0; q < playerSet.WeaponAttachments2.Count(); q++) {
				itemEnt = weapon.GetInventory().CreateAttachment(playerSet.WeaponAttachments2[q]);

				switch (playerSet.WeaponAttachments2[q]) {
					case "KobraOptic":
					case "M680Optic":
					case "M4_T3NRDSOptic":
					case "HH_OKP7Optic":
					case "FN45_MRDSOptic":
						itemEnt.GetInventory().CreateAttachment("Battery9V");
						break;
				}
			}

			player.SetQuickBarEntityShortcut(weapon, 1);
		}
	}



	void spawnMagazineInWeapon (PlayerBase player, EntityAI wpEAI, string item_name)
	{
		if( player )
		{
			if ( GetGame().IsServer() )
			{
				if ( item_name == "" ) return;

				string magazine_type = item_name;

				EntityAI weaponEAI = wpEAI;
				Weapon_Base wpn;
				InventoryLocation il = new InventoryLocation;;
				EntityAI mag;

				// if (inHands) {
					// weaponEAI = player.GetHumanInventory().GetEntityInHands();
					// il = 
					
				weaponEAI.GetInventory().GetCurrentInventoryLocation(il);
				wpn = Weapon_Base.Cast(weaponEAI);

				il.SetAttachment( wpn, NULL, InventorySlots.MAGAZINE );
				mag = SpawnEntity( magazine_type, il, ECE_IN_INVENTORY, RF_DEFAULT );

				// } else {
				// 	il = new InventoryLocation;
				// 	wpn = Weapon_Base.Cast(GetGame().CreateObject( sWeapon , "0 0 0" ));

				// 	il.SetAttachment( wpn, NULL, InventorySlots.MAGAZINE );
				// 	mag = SpawnEntity( magazine_type, il, ECE_IN_INVENTORY, RF_DEFAULT );

				// 	player.GetInventory().AddEntityToInventory(wpn);
				// }

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

				if ( !mag ) return;

				// GetGame().RemoteObjectDelete( mag );
				// GetGame().RemoteObjectDelete( wpn ); 

				// pushToChamberFromAttachedMagazine( wpn, wpn.GetCurrentMuzzle() );

				ScriptReadWriteContext ctx = new ScriptReadWriteContext;
				ctx.GetWriteContext().Write( stateId );
				wpn.LoadCurrentFSMState( ctx.GetReadContext(), GetGame().SaveVersion() );

				GetGame().RemoteObjectCreate( wpn );
				GetGame().RemoteObjectCreate( mag );
			}
		}
	}

	
	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{	
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
			
			auto param4 = new Param4<string, string, string, string>(_plData.playerName, _plData.kills.ToString(), _plData.deadth.ToString(), _plData.killstreak.ToString());
			GetGame().RPCSingleParam(player, HHRPCEnum.RPC_CLIENT_UPDATE_TOP, param4, true, player.GetIdentity());
		}

		super.InvokeOnConnect(player, identity);
	}


	void SendMessageToAll(string message)
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

    void sendMessageToCurrentPlayer (PlayerBase player, string message) {
    	Param1<string> m_MessageParam = new Param1<string>(TOP_PREFIX + message);
	    GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, m_MessageParam, true, player.GetIdentity());
    }

    // ref array<ref CorpseData> getDeadPlayers () {
    // 	return m_DeadPlayersArray;
    // }
}