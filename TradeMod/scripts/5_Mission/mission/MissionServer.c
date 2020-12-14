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
		ItemBase itemBs;
		float rand;

		player.RemoveAllItems();

		PlayerSet playerSet = SPOptions.PlayerSetups.GetRandomElement();

		// создание одежды
		for (int i = 0; i < playerSet.Clothes.Count(); i++) {
			player.GetInventory().CreateInInventory(playerSet.Clothes[i]);
		}


		// создание оружия и его обвесов
		weapon = player.GetHumanInventory().CreateInHands(playerSet.Weapon);
		player.SetQuickBarEntityShortcut(weapon, 0);

		// hh_weaponDeletion = GetWeaponDeletion();
		// hh_weaponDeletion.addEntity(itemEnt);


		for (int j = 0; j < playerSet.WeaponAttachments.Count(); j++) {
			weapon.GetInventory().CreateAttachment(playerSet.WeaponAttachments[j]);
		}

		itemClothing = player.FindAttachmentBySlotName( "Body" );

		// создание внутренней экипировки
		if ( itemClothing )
		{
			itemEnt = itemClothing.GetInventory().CreateInInventory( "Rag" );
			if (Class.CastTo( itemBs, itemEnt )) itemBs.SetQuantity( 6 );
			
			for (int k = 0; k < playerSet.Equipment.Count(); k++) {
				player.GetInventory().CreateInInventory(playerSet.Equipment[k]);
			}
		}

		// ReloadWeapon( EntityAI weapon, EntityAI magazine )
		player.QuickReloadWeapon(weapon);
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