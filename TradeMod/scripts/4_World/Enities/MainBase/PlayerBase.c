modded class PlayerBase
{

	ref PluginPlayersTop m_playerTop;


	void Init () {
		m_playerTop = new PluginPlayersTop();
		super.Init();
	}

    override void OnPlayerLoaded()
	{
		super.OnPlayerLoaded();			
		GetHumanInventory().CreateInInventory("RGD5Grenade");
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

    	string message = "Привет, " + GetAnnouncePlayerPrefix(this.GetIdentity()) + " (" + this.GetIdentity().GetPlainId() + ")";

		SendMessage(message);
    }

    override void EEKilled(Object killer)
	{
		Print("PlayerBase.c EEKilled()");

		if (m_playerTop) {
			m_playerTop.PlayerKilled(PlayerBase.Cast(this), killer);
		}
		
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