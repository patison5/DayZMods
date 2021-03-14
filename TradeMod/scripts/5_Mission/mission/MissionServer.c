modded class MissionServer extends MissionBase
{
	static const string PREFIX = "[MY_MISSION_SERVER]: ";

	ref SetupPlayerOptions SPOptions;
	ref PlayerClothesVip vipClient;
	// ref WeeklyKing weeklyKing;
	
	void MissionServer () {
		if (GetGame().IsServer()) {
			// check folder existance
			if (!FileExist(S_ROOTFOLDER)) MakeDirectory(S_ROOTFOLDER);
			if (!FileExist(S_PLAYERS)) MakeDirectory(S_PLAYERS);
			if (!FileExist(S_COMMON)) MakeDirectory(S_COMMON);

			// check file existance and get setup options
			if (!FileExist(S_ROOTFOLDER + "SetupPlayerOptions.json")) {
				SPOptions = new SetupPlayerOptions();
				SPOptions.InitPlayerSetups();
			} else {
				JsonFileLoader<ref SetupPlayerOptions>.JsonLoadFile(S_ROOTFOLDER + "SetupPlayerOptions.json", SPOptions );	
			}
			JsonFileLoader<ref SetupPlayerOptions>.JsonSaveFile(S_ROOTFOLDER + "SetupPlayerOptions.json",  SPOptions);	
		}

		// if (!weeklyKing) {
			// weeklyKing = WeeklyKing();
		// }

		// weeklyKing.test();
	}

	ref PlayerClothesVip findVip (string steamId) {
		for (int v = 0; v < SPOptions.clothesVip.Count(); v++) {
			if (SPOptions.clothesVip[v].steamId64 == steamId)
				return SPOptions.clothesVip[v];
		}
		return NULL;
	}

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


		PlayerClothes playerClothes = SPOptions.heavyClothes.GetRandomElement();;
		PlayerWeapon playerWeapons = SPOptions.heavyWeapons.GetRandomElement();

		if (roundNumber == 0) {
			playerClothes = SPOptions.heavyClothes.GetRandomElement();
			playerWeapons = SPOptions.heavyWeapons.GetRandomElement();
		} else if (roundNumber == 1) {
			playerClothes = SPOptions.lightClothes.GetRandomElement();
			playerWeapons = SPOptions.lightWeapons.GetRandomElement();
		} else if (roundNumber == 2) {
			playerClothes = SPOptions.lightClothes.GetRandomElement();
			playerWeapons = SPOptions.snipingWeapons.GetRandomElement();
		}

		

		// создание шлема и его обвесов
		helmet = player.GetInventory().CreateInInventory(playerClothes.Helmet);
		for (int j = 0; j < playerClothes.HelmetAttachments.Count(); j++)
			helmet.GetInventory().CreateAttachment(playerClothes.HelmetAttachments[j]);

		// оздание броника и его обвесов
		vest = player.GetInventory().CreateInInventory(playerClothes.Vest);
		for (int m = 0; m < playerClothes.VestAttachments.Count(); m++)
			vest.GetInventory().CreateAttachment(playerClothes.VestAttachments[m]);



		vipClient = findVip( player.GetIdentity().GetPlainId() );

		if (vipClient) {
			// создание vip одежды
			for (int i = 0; i < vipClient.Clothes.Count(); i++)
				player.GetInventory().CreateInInventory(vipClient.Clothes[i]);
		} else {
			// создание одежды
			for (int b = 0; b < playerClothes.Clothes.Count(); b++)
				player.GetInventory().CreateInInventory(playerClothes.Clothes[b]);
		}

		itemClothing = player.FindAttachmentBySlotName( "Body" );



		// создание внутренней экипировки
		if ( itemClothing )
		{
			// itemEnt = itemClothing.GetInventory().CreateInInventory( "Rag" );
			// if (Class.CastTo( itemBs, itemEnt )) itemBs.SetQuantity( 6 );
			
			for (int k = 0; k < playerWeapons.Equipment.Count(); k++) {
				player.GetInventory().CreateInInventory(playerWeapons.Equipment[k]);
			}
		}

		// создание оружия и его обвесов
		weapon = player.GetHumanInventory().CreateInHands(playerWeapons.Weapon);
		// spawnMagazineInWeapon(player, weapon, playerWeapons.MagType);
		

		for (int z = 0; z < playerWeapons.WeaponAttachments.Count(); z++) {
			itemEnt = weapon.GetInventory().CreateAttachment(playerWeapons.WeaponAttachments[z]);

			switch (playerWeapons.WeaponAttachments[z]) {
				case "KobraOptic":
				case "M68Optic":
				case "M4_T3NRDSOptic":
				case "HH_OKP7Optic":
				case "FN45_MRDSOptic":
					itemEnt.GetInventory().CreateAttachment("Battery9V");
					break;
			}
		}
		player.SetQuickBarEntityShortcut(weapon, 0);

		if (playerWeapons.Weapon2 != "") {
			// создание оружия и его обвесов
			weapon = player.GetHumanInventory().CreateInInventory(playerWeapons.Weapon2);
			// spawnMagazineInWeapon(player, weapon, playerWeapons.MagType2);

			for (int q = 0; q < playerWeapons.WeaponAttachments2.Count(); q++) {
				itemEnt = weapon.GetInventory().CreateAttachment(playerWeapons.WeaponAttachments2[q]);

				switch (playerWeapons.WeaponAttachments2[q]) {
					case "KobraOptic":
					case "M68Optic":
					case "M4_T3NRDSOptic":
					case "HH_OKP7Optic":
					case "FN45_MRDSOptic":
						itemEnt.GetInventory().CreateAttachment("Battery9V");
						break;
				}
			}

			player.SetQuickBarEntityShortcut(weapon, 1);
		}


		// EntityAI belt = player.GetInventory().CreateInInventory("HH_BeltMilitary_Havvy_Black");
		// belt.GetInventory().CreateInInventory("HH_BeltMilitary_Bag_Black");
		// belt.GetInventory().CreateInInventory("HH_BeltMilitary_Holster_Black");
		// belt.GetInventory().CreateInInventory("HH_BeltTactical_Bag_black");

		// EntityAI knifeHolster = belt.GetInventory().CreateInInventory("NylonKnifeSheath");
		// knifeHolster.GetInventory().CreateInInventory("CombatKnife");

		// float dmg;
		// string ammoType;
		// if ( !mag.ServerAcquireCartridge(dmg,ammoType) )
		// 	return;
		// DayZPlayerUtils.HandleStoreCartridge(action_data.m_Player, NULL, -1, dmg, ammoType, magazineTypeName, false)
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

				weaponEAI.GetInventory().GetCurrentInventoryLocation(il);
				wpn = Weapon_Base.Cast(weaponEAI);

				il.SetAttachment( wpn, NULL, InventorySlots.MAGAZINE );
				mag = SpawnEntity( magazine_type, il, ECE_IN_INVENTORY, RF_DEFAULT );

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

		Print("InvokeOnConnect");

		PluginPlayersTop m_PlStat = PluginPlayersTop.Cast(GetPlugin(PluginPlayersTop));

		if (player.GetIdentity()) {
			ref PlayerStatisticInfo _plData;
			ref PlayerStatisticAllInfo _plAllInfo;

			string steamId = player.GetIdentity().GetPlainId();

			if (FileExist(S_PLAYERS) && FileExist(S_PLAYERS + steamId + ".json")) {
				JsonFileLoader<ref PlayerStatisticInfo>.JsonLoadFile(S_PLAYERS + steamId + ".json", _plData);
				_plData.setPlayerName(player.GetIdentity().GetName());
			} else { 
				_plData = new PlayerStatisticInfo(); 
				_plData.setSteamId(player.GetIdentity().GetPlainId());
				_plData.setPlayerName(player.GetIdentity().GetName());
				JsonFileLoader<ref PlayerStatisticInfo>.JsonSaveFile(S_PLAYERS + steamId + ".json", _plData);
			}
			
			auto param4 = new Param4<string, string, string, string>(_plData.playerName, _plData.kills.ToString(), _plData.deadth.ToString(), _plData.maxRangeKill.ToString());
			GetGame().RPCSingleParam(player, HHRPCEnum.RPC_CLIENT_UPDATE_TOP, param4, true, player.GetIdentity());

			if (!(FileExist(S_COMMON) && FileExist(S_COMMON + steamId + ".json"))) {
				// если нет пришедшего человека
				_plAllInfo = new PlayerStatisticAllInfo(); 
				_plAllInfo.setSteamId(player.GetIdentity().GetPlainId());
				_plAllInfo.setPlayerName(player.GetIdentity().GetName());
				JsonFileLoader<ref PlayerStatisticAllInfo>.JsonSaveFile(S_COMMON + steamId + ".json", _plAllInfo);
			} else {
				// если уже есть в базе, обновить имя на текущее
				JsonFileLoader<ref PlayerStatisticAllInfo>.JsonLoadFile(S_COMMON + steamId + ".json", _plAllInfo);
				_plAllInfo.setSteamId(player.GetIdentity().GetPlainId());
				_plAllInfo.setPlayerName(player.GetIdentity().GetName());
				JsonFileLoader<ref PlayerStatisticAllInfo>.JsonSaveFile(S_COMMON + steamId + ".json", _plAllInfo);
			}
		}

		vector vybor = "4553.53906 317.744019 8312.951172";

		super.InvokeOnConnect(player, identity);

		// if (vector.Distance(player.GetPosition(), vybor) >= 1200) {
		// 	Print("Чувак слишком далеко от точки файта, уебем-ка его нахуй");
		// 	player.SetHealth("","",-100);
		// } else {
		// 	Print("Хорош прохлаждаться, в бой ебанарот!");
		// }

		// Print("Выбираем точку центра спавна: ");
		// Print(spawnDotLocations);
		// Print(spawnDotLocations[spawnLocation]);
		// Print(spawnLocation);
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
}


// M/iMwr9LPDyXE0NEjIq+2m5ZtcbF0U2VBu3A0IASb68=

// ApplicationID: 603e67eef3448ec620a18e09
// Client-ID: O0TWD731GNP6BVZHEL5RM8IQ