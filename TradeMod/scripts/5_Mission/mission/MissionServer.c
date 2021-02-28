modded class MissionServer extends MissionBase
{
	protected PluginDeveloper m_Developer;

	static const string PREFIX = "[MY_MISSION_SERVER]: ";

	ref SetupPlayerOptions SPOptions;
	ref HeadHunterDMInfo HHDMInfo;
	
	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			float rndHlt = Math.RandomFloat( 0.45, 0.65 );
			itemEnt.SetHealth01( "", "", rndHlt );
		}
	}

	int DateHH( int D, int M, int Y )
    {

        int a, y, m, R;
        a = ( 14 - M ) / 12;
        y = Y - a;
        m = M + 12 * a - 2;
        R = 7000 + ( D + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12 );
        int l  = R % 7;
        int s = l;
        return s;
    }

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


			if (!FileExist(S_ROOTFOLDER + "HeadHunterDMInfo.json")) {
				HHDMInfo = new HeadHunterDMInfo();
				JsonFileLoader<ref HeadHunterDMInfo>.JsonSaveFile(S_ROOTFOLDER + "HeadHunterDMInfo.json",  HHDMInfo);		
			} else {
				JsonFileLoader<ref HeadHunterDMInfo>.JsonLoadFile(S_ROOTFOLDER + "HeadHunterDMInfo.json", HHDMInfo );	
			}	
		}

		m_Developer	= PluginDeveloper.Cast( GetPlugin(PluginDeveloper) );

		int f_hour;
        int f_minute;
        int f_second;
        int f_year;
        int f_month;
        int f_day;    
        GetYearMonthDay(f_year, f_month, f_day);
        GetHourMinuteSecond(f_hour, f_minute, f_second);

        Print("Дата запуска: " + f_year.ToString() + ":" + f_month.ToString() + ":" + f_day.ToString());
        Print("Время запуска: " + f_hour.ToString() + ":" + f_minute.ToString() + ":" + f_second.ToString());

        string f_date = f_month.ToStringLen(2) + "-" + f_day.ToStringLen(2) + " " + f_hour.ToStringLen(2) + ":" + f_minute.ToStringLen(2) + ":" + f_second.ToStringLen(2);
        Print("Date: " + f_date);

        Print("номер дня недели равен: " + DateHH(f_day, f_month, f_year));

        // если воскресение
        if (DateHH(f_day, f_month, f_year) == 6) {
        	string checkDate = f_month.ToStringLen(2) + "-" + f_day.ToStringLen(2) + "-" + f_year;

        	Print("День недели сейчас вроде суббота");

        	if (checkDate != HHDMInfo.kingUpdateDate) {
        		HHDMInfo.kingUpdateDate = checkDate;

        		Print("Вроде как не совпадает - обновим!");
        		JsonFileLoader<ref HeadHunterDMInfo>.JsonSaveFile(S_ROOTFOLDER + "HeadHunterDMInfo.json",  HHDMInfo);
        	} else {
	        	Print("А все уже все, дата совпадает, новый лидер уже выбран!");
        	}
        }
	}

	//  вот тут блэт могут быть косяки!
	void summurizePlayersStatistic () {
    	// собираем всю информацию по игрокам
        TStringArray fileNamesList = this.getAllPlayersList();
        PlayerStatisticAllInfo _bestPlayerData = new PlayerStatisticAllInfo();
        
        for ( int k = 0; k < fileNamesList.Count(); ++k ) {
            string fileName = fileNamesList.Get(k);

            if (!FileExist(S_COMMON + fileName + ".json"))
                continue; 

            PlayerStatisticAllInfo _tmpBestPlayerData = new PlayerStatisticAllInfo();
            JsonFileLoader<ref PlayerStatisticAllInfo>.JsonLoadFile(S_COMMON + fileName + ".json", _tmpBestPlayerData);

            if (_bestPlayerData.matchesWon <= _tmpBestPlayerData.matchesWon) {
            	if (_bestPlayerData.matchesWon == _tmpBestPlayerData.matchesWon) {
            		// посмотреть по килам
            	} else {
            		_bestPlayerData = _tmpBestPlayerData;
            	}
            }
        }
    }

	TStringArray getAllPlayersList()
    {
        if ( !FileExist( S_COMMON ) )
            MakeDirectory( S_COMMON );

        string  file_name;
        int     file_attr;
        int     flags;
        TStringArray list = new TStringArray;
        
        string path_find_pattern = S_COMMON + "/*.json";
        FindFileHandle file_handler = FindFile(path_find_pattern, file_name, file_attr, flags);
        
        bool found = true;
        while ( found )
        {
            int pos = file_name.IndexOf(".");
            
            if ( pos > -1 )
                list.Insert( file_name.Substring(0, pos) );
            
            found = FindNextFile(file_handler, file_name, file_attr);
        }

        return list;
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
			// spawnMagazineInWeapon(player, weapon, playerSet.MagType2);

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


		EntityAI belt = player.GetInventory().CreateInInventory("HH_BeltMilitary_Havvy_Black");
		belt.GetInventory().CreateInInventory("HH_BeltMilitary_Bag_Black");
		belt.GetInventory().CreateInInventory("HH_BeltMilitary_Holster_Black");
		belt.GetInventory().CreateInInventory("HH_BeltTactical_Bag_black");

		EntityAI knifeHolster = belt.GetInventory().CreateInInventory("NylonKnifeSheath");
		knifeHolster.GetInventory().CreateInInventory("CombatKnife");

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