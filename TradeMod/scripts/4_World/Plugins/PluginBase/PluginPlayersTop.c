class PluginPlayersTop extends PluginBase
{
	ref PlayerStatisticInfo _plData;

	private PlayerBase m_Source;
	private bool _isNewPlayer = true;

	private string victimPlayerPrefix;
	private string killerPlayerPrefix;

	private float distance;

	void hello (string str)
	{
		Print("Hello from " + str);
	}

	void PluginPlayersTop()
	{
		if (GetGame().IsMultiplayer())
		{
			Print("Init: PluginPlayersTop");

			_plData = new PlayerStatisticInfo();
		}
	}
	
	void ~PluginPlayersTop()
	{
		if (GetGame().IsMultiplayer())
		{
			Print("~PluginPlayersTop Closed");
		}
	}

	void readPlayerData (PlayerBase player) {
		string steamId = player.GetIdentity().GetPlainId();
		if (!FileExist(S_PLAYERS)) MakeDirectory(S_PLAYERS)

		// check file existance and get setup options
		if (!FileExist(S_PLAYERS + steamId + ".json")) {
			string name = GetAnnouncePlayerPrefix(player.GetIdentity());

			_plData = new PlayerStatisticInfo();
			_plData.setSteamId(steamId);
			_plData.setPlayerName(name);

			JsonFileLoader<ref PlayerStatisticInfo>.JsonSaveFile(S_PLAYERS + steamId + ".json", _plData);	
		} else {
			JsonFileLoader<ref PlayerStatisticInfo>.JsonLoadFile(S_PLAYERS + steamId + ".json", _plData);
		}	
	}


	void updatePlayerData (PlayerBase player) {
		string steamId = player.GetIdentity().GetPlainId();
		JsonFileLoader<ref PlayerStatisticInfo>.JsonSaveFile(S_PLAYERS + steamId + ".json", _plData);

		if (player.GetIdentity()) {
			auto param4 = new Param4<string, string, string, string>(_plData.playerName, _plData.kills.ToString(), _plData.deadth.ToString(), _plData.maxRangeKill.ToString());
			GetGame().RPCSingleParam(player, HHRPCEnum.RPC_CLIENT_UPDATE_TOP, param4, true, player.GetIdentity());
		}
	}

	protected string GetAnnouncePlayerPrefix(PlayerIdentity identity)  // player name prefix for announcements
	{
		string a_PlayerName = "Survivor (AI)";
		if (identity)
		{
			a_PlayerName = identity.GetName();
		}
		identity = NULL;
		
		return trimName(a_PlayerName);
	}

	protected string trimName(string str) {
        string sTest;
        if (str.Length()>13) {
            if (str.Length()<16) {
                return str;
            }
            else {
                sTest = str.Substring(0,13);
                sTest+="...";
                return sTest;
            }
        }
        else {
            return str;
        }
    }
	


	// ***************************************************************************************************
	// Kill Section
	// ***************************************************************************************************
	void PlayerKilled(PlayerBase player, Object source) {

		victimPlayerPrefix = this.GetAnnouncePlayerPrefix(player.GetIdentity());		
		killerPlayerPrefix = "";

		if (player.GetIdentity()) {
			readPlayerData(player);
			_plData.deadth = _plData.deadth + 1;
			_plData.killstreak = 0;
			updatePlayerData(player); //IWASDEAD
		}

		if (player && source) {
			if (player == source) {
				// player killed himself

			} else if (source.IsWeapon() || source.IsMeleeWeapon()) {
				// player killed player

				m_Source = PlayerBase.Cast(EntityAI.Cast(source).GetHierarchyParent());

				if (m_Source) {
					killerPlayerPrefix = this.GetAnnouncePlayerPrefix(m_Source.GetIdentity());
					// Print(TOP_PREFIX + killerPlayerPrefix + " является убийцей");

					readPlayerData(m_Source);
					_plData.kills = _plData.kills + 1;
					_plData.killstreak = _plData.killstreak + 1;

					if (!source.IsMeleeWeapon()) {
						distance = Math.Round(vector.Distance(player.GetPosition(), m_Source.GetPosition()));
						if (_plData.maxRangeKill < distance) _plData.maxRangeKill = distance;
					}
					updatePlayerData(m_Source); //IAMAKILLER
				}
			} else if (source.IsInherited(SurvivorBase)) {

				m_Source = PlayerBase.Cast(source);

				if (!Class.CastTo(m_Source, source)) return;

				if (m_Source.GetIdentity()) {
					//that player killed someone with hands
					readPlayerData(m_Source);
					_plData.kills = _plData.kills + 1;
					_plData.killstreak = _plData.killstreak + 1;
					updatePlayerData(m_Source); //IAMAKILLER
				}
			}
		} else {
			if (!source) Print(TOP_PREFIX + "NO SOURCE FOUND");
			if (!player) Print(TOP_PREFIX + "NO PLAYER FOUND");
		}



	}

	// ***************************************************************************************************
	// Kill Section
	// ***************************************************************************************************
	void PlayerHitBy(int damageType, PlayerBase player, EntityAI source, string ammo) {
		victimPlayerPrefix = this.GetAnnouncePlayerPrefix(player.GetIdentity());
		Print(victimPlayerPrefix + "БЫЛ УБИТ ИЛИ РАНЕН БЛЭТ");
	}

	// ***************************************************************************************************
	// Suicide Section
	// ***************************************************************************************************
	void Suicide(PlayerBase player)  // EmoteManager.c 
	{
		if (player && player.GetIdentity()) {
			Print("Fuck, " + player.GetIdentity().GetName() +  " commited Suicided");

			readPlayerData(m_Source);
			_plData.deadth = _plData.deadth + 1;
			updatePlayerData(m_Source);
		}
	}

	// ***************************************************************************************************
	// Kill Section
	// ***************************************************************************************************
	void BleedingOut(PlayerBase player) {
		if (player && player.GetIdentity()) {
			Print("Fuck, " + player.GetIdentity().GetName() +  " bleeded out");

			EntityAI m_LastSource = player.m_KillerData.m_MurderWeapon;

			if (m_LastSource && m_LastSource.IsWeapon()) {
				// истек от попадания с оружия
				m_Source = PlayerBase.Cast(m_LastSource.GetHierarchyParent());
			}

			if (m_LastSource && m_LastSource.IsPlayer()) {
				// истек от попадания кулаком в морду
			}

			readPlayerData(m_Source);
			_plData.deadth = _plData.deadth + 1;
			updatePlayerData(m_Source);
		}
	}
}