modded class PlayerBase
{

	ref PluginPlayersTop m_playerTop;
	// ref HHWeaponDeletion hh_weaponDeletion;
	ref array<EntityAI> entities;

	ref array <string> spawnPoings = new array<string>();


	void Init () {
		m_playerTop = new PluginPlayersTop();
		super.Init();
	}

    override void OnPlayerLoaded()
	{
		super.OnPlayerLoaded();			
		// GetHumanInventory().CreateInInventory("RGD5Grenade");
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


    override void OnJumpStart () {
    	super.OnJumpStart();


    	JsonFileLoader<ref array <string>>.JsonLoadFile(S_ROOTFOLDER + "spawnPoings.json",  spawnPoings);
    	spawnPoings.Insert(this.GetPosition().ToString());
    	JsonFileLoader<ref array <string>>.JsonSaveFile(S_ROOTFOLDER + "spawnPoings.json",  spawnPoings);

    	string message = "Привет, " + GetAnnouncePlayerPrefix(this.GetIdentity()) + " (" + this.GetIdentity().GetPlainId() + ")";

		SendMessage(this.GetPosition().ToString());
    }

    override void EEKilled(Object killer)
	{
		Print("PlayerBase.c EEKilled()");

		if (m_playerTop) {
			m_playerTop.PlayerKilled(PlayerBase.Cast(this), killer);
		}

		// Remove entity in hands
        // EntityAI inHandsItem = this.GetHumanInventory().GetEntityInHands();

        // if (inHandsItem != null) {
        //     // GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(removeItem, 1500, false, inHandsItem);
        //     // Print("В руках есть оружие, ща удалим чувак");
        // } else {
        // 	Print(TOP_PREFIX + "NO WEAPON IN HANDS");
        // }

        // hh_weaponDeletion = GetWeaponDeletion();
        // entities = hh_weaponDeletion.GetEntities();
        // hh_weaponDeletion.checkAndRemove();

        // Remove body
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().ObjectDelete, 10000, false, this);
		
		super.EEKilled(killer);
	}
	
	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
		
		Print("[FUCK] : PlayerBase.c EEHitBy()" + dmgZone);
		//m_KillFeed.PlayerHitBy(damageType, PlayerBase.Cast(this), source, ammo);
	}


    protected string GetAnnouncePlayerPrefix(PlayerIdentity identity)  // player name prefix for announcements
	{
		string a_PlayerName = "Survivor (AI)";
		if (identity)
		{
			a_PlayerName = identity.GetName();
		}
		identity = NULL;
		
		return a_PlayerName;
	}




	override void ReloadWeapon( EntityAI weapon, EntityAI magazine ) {
		super.ReloadWeapon(weapon, magazine);
	}
}