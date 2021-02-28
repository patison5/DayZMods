class PluginPlayersTop extends PluginBase
{
	ref PlayerStatisticInfo _plData;
	ref PlayerStatisticAllInfo _KillerAllInfo;
	ref PlayerStatisticAllInfo _VictimAllInfo;

	ref map<string, ref WeaponStatistic> weaponsData;

	private PlayerBase m_Source;
	private bool _isNewPlayer = true;

	private string victimPlayerPrefix;
	private string killerPlayerPrefix;

	private float distance;

	ref private PluginAdminNotification sindicatNotify;
	
	void PluginPlayersTop()
	{
		if (GetGame().IsMultiplayer())
		{
			Print("Init: PluginPlayersTop");

			_plData = new PlayerStatisticInfo();
			sindicatNotify = new PluginAdminNotification();
		}
	}

	void readPlayerData (PlayerBase player) {
		string steamId = player.GetIdentity().GetPlainId();
		
		JsonFileLoader<ref PlayerStatisticInfo>.JsonLoadFile(S_PLAYERS + steamId + ".json", _plData);
		JsonFileLoader<ref PlayerStatisticAllInfo>.JsonLoadFile(S_COMMON + steamId + ".json", _KillerAllInfo);
	}


	void updatePlayerData (PlayerBase player) {
		string steamId = player.GetIdentity().GetPlainId();

		JsonFileLoader<ref PlayerStatisticInfo>.JsonSaveFile(S_PLAYERS + steamId + ".json", _plData);

		if (player.GetIdentity()) {
			auto param4 = new Param4<string, string, string, string>(_plData.playerName, _plData.kills.ToString(), _plData.deadth.ToString(), _plData.maxRangeKill.ToString());
			GetGame().RPCSingleParam(player, HHRPCEnum.RPC_CLIENT_UPDATE_TOP, param4, true, player.GetIdentity());
		}
		
		// sindicatNotify.checkSendingPossibility(player, _plData.killstreak);
	}


    void checkKillstrike (PlayerBase player) {

    }
	

	void updateKills (PlayerBase killer, PlayerBase victim, Object weapon) {
		string KillerSteamId = killer.GetIdentity().GetPlainId();
		string wpName = weapon.GetDisplayName();

		// читаем последнюю инфу		
		JsonFileLoader<ref PlayerStatisticInfo>.JsonLoadFile(S_PLAYERS + KillerSteamId + ".json", _plData);
		JsonFileLoader<ref PlayerStatisticAllInfo>.JsonLoadFile(S_COMMON + KillerSteamId + ".json", _KillerAllInfo);


		// обновляем килы и киллстрайк
		_plData.kills = _plData.kills + 1;
		_plData.killstreak = _plData.killstreak + 1;


		//-----------------------------------------
		// обновляем килы в долгосрочном файле
		_KillerAllInfo.kills = _KillerAllInfo.kills + 1;

		// обновляем киллстрайк в долгосрочом файле
		if (_KillerAllInfo.maxKillstreak < _plData.killstreak)
			_KillerAllInfo.maxKillstreak = _plData.killstreak;


		if (!weapon.IsMeleeWeapon()) {
			distance = Math.Round(vector.Distance(victim.GetPosition(), killer.GetPosition()));
			if (_plData.maxRangeKill < distance) _plData.maxRangeKill = distance;
			if (_KillerAllInfo.maxRangeKill < distance) _KillerAllInfo.maxRangeKill = distance;
		} else distance = 0;

		// обновление данных оружия в долгосрочном файле
		weaponsData = _KillerAllInfo.getWeaponsData();

		if (!weaponsData)
			return;

		ref WeaponStatistic wpStats = NULL;

		if (weaponsData.Find(wpName, wpStats)) {
			wpStats.kills = wpStats.kills + 1;
			wpStats.producedHits = wpStats.producedHits + 1;

			if (wpStats.longestKill < distance) wpStats.longestKill = distance;
		} else {
			wpStats = new WeaponStatistic();
			wpStats.weaponName = wpName;
			wpStats.kills = 1;
			wpStats.producedHits = 1;
			wpStats.longestKill = distance;

			_KillerAllInfo.weaponsData.Insert(wpName, wpStats);
		}

		// проверка килстрайка
		if (_plData.killstreak % 5 == 0) {
			Print("ДОМИНИРОВАНИЕ!");

			if (killer && killer.IsAlive()) {
				EntityAI v_SoundSource = killer;
				v_SoundSource.PlaySound( "Dominating", 50 );
			}
		}

		JsonFileLoader<ref PlayerStatisticAllInfo>.JsonSaveFile(S_COMMON + KillerSteamId + ".json",   _KillerAllInfo);
	}

	void updateDistance (PlayerBase player, PlayerBase killer, Object source) {
		if (!source.IsMeleeWeapon()) {
			distance = Math.Round(vector.Distance(player.GetPosition(), killer.GetPosition()));
			if (_plData.maxRangeKill < distance) _plData.maxRangeKill = distance;

			if (_KillerAllInfo.maxRangeKill < distance) {
				string steamId = player.GetIdentity().GetPlainId();

				JsonFileLoader<ref PlayerStatisticAllInfo>.JsonLoadFile(S_COMMON + steamId + ".json", _KillerAllInfo);
				_KillerAllInfo.maxRangeKill = distance;
				JsonFileLoader<ref PlayerStatisticAllInfo>.JsonSaveFile(S_COMMON + steamId + ".json",   _KillerAllInfo);
			}
		}
	}

	void updateFinishedMatches (PlayerBase player) {
		string steamId = player.GetIdentity().GetPlainId();
		JsonFileLoader<ref PlayerStatisticAllInfo>.JsonLoadFile(S_COMMON + steamId + ".json", _KillerAllInfo);
		_KillerAllInfo.matchesPlayed = _KillerAllInfo.matchesPlayed + 1; 
		JsonFileLoader<ref PlayerStatisticAllInfo>.JsonSaveFile(S_COMMON + steamId + ".json", _KillerAllInfo);
	}

	void updateWonMatchesCount (PlayerBase player) {
		string steamId = player.GetIdentity().GetPlainId();
		JsonFileLoader<ref PlayerStatisticAllInfo>.JsonLoadFile(S_COMMON + steamId + ".json", _KillerAllInfo);
		_KillerAllInfo.matchesWon = _KillerAllInfo.matchesWon + 1;
		JsonFileLoader<ref PlayerStatisticAllInfo>.JsonSaveFile(S_COMMON + steamId + ".json", _KillerAllInfo);
	}

	void updateDeaths (PlayerBase player, Object weapon) {
		readPlayerData(player);
		_plData.deadth = _plData.deadth + 1;
		_plData.killstreak = 0;


		//-----------------------------------------
		// обновление долгосрочной статистики
		string steamId = player.GetIdentity().GetPlainId();
		string wpName = weapon.GetDisplayName();

		// обновляем килы в долгосрочном файле
		_KillerAllInfo.deaths = _KillerAllInfo.deaths + 1;

		if (weapon.IsWeapon() || weapon.IsMeleeWeapon()) {
			// обновление данных оружия в долгосрочном файле
			weaponsData = _KillerAllInfo.getWeaponsData();

			if (!weaponsData)
				return;

			ref WeaponStatistic wpStats = NULL;

			if (weaponsData.Find(wpName, wpStats)) {
				wpStats.deaths = wpStats.deaths + 1;
				wpStats.receivedHits = wpStats.receivedHits + 1;
			} else {
				wpStats = new WeaponStatistic();
				wpStats.weaponName = wpName;
				wpStats.deaths = 1;
				wpStats.receivedHits = 1;

				_KillerAllInfo.weaponsData.Insert(wpName, wpStats);
			}

			JsonFileLoader<ref PlayerStatisticAllInfo>.JsonSaveFile(S_COMMON + steamId + ".json",   _KillerAllInfo);
		}



		updatePlayerData(player); //IWASDEAD
	}


	// ***************************************************************************************************
	// Kill Section
	// ***************************************************************************************************
	void PlayerKilled(PlayerBase player, Object source) {

		if (!player || !source) return;
		if (player == source)   return;

		if (player.GetIdentity())
			updateDeaths(player, source);

		if (source.IsWeapon() || source.IsMeleeWeapon()) {
			// player killed player
			PlayerBase killer = PlayerBase.Cast(EntityAI.Cast(source).GetHierarchyParent());

			if (killer) {
				updateKills(killer, player, source);
				// updateDistance(player, killer, source);
				updatePlayerData(killer); //IAMAKILLER
			}
		} else if (source.IsInherited(SurvivorBase)) {

			killer = PlayerBase.Cast(source);
			if (!Class.CastTo(killer, source)) return;

			if (killer.GetIdentity()) {
				updateKills(killer, player, source);
				updatePlayerData(killer); //IAMAKILLER
			}
		}
	}

	// ***************************************************************************************************
	// Kill Section
	// ***************************************************************************************************
	void EEHitBy(PlayerBase player, PlayerBase victim, TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		// float distance = vector.Distance(player.GetPosition(), GetPosition());

		Print("Дата : [dmgZone] 		: " + dmgZone);
		Print("Дата : [damageResult] 	: " + damageResult.GetDamage(dmgZone, "Health"));
		Print("Дата : [damageType]      : " + damageType.ToString());
		Print("Дата : [GetDisplayName]  : " + source.GetDisplayName());

		//-----------------------------------------
		// обновление долгосрочной статистики
		string killerSteamId 	 = player.GetIdentity().GetPlainId();
		string victimSteamId 	 = victim.GetIdentity().GetPlainId();

		Print("victimSteamId : " + victimSteamId);
		Print("killerSteamId : " + killerSteamId);

		string wpName = source.GetDisplayName();

		JsonFileLoader<ref PlayerStatisticAllInfo>.JsonLoadFile(S_COMMON + killerSteamId + ".json", _KillerAllInfo);
		JsonFileLoader<ref PlayerStatisticAllInfo>.JsonLoadFile(S_COMMON + victimSteamId + ".json", _VictimAllInfo);
		JsonFileLoader<ref PlayerStatisticInfo>.JsonLoadFile(S_PLAYERS + killerSteamId + ".json", _plData);

		switch (dmgZone) {
			case "LeftFoot": { 
				_plData.leftFoot = _plData.leftFoot + 1;
				break;            
			}
			case "RightFoot": { 
				_plData.rightFoot = _plData.rightFoot + 1;
				break;            
			}
			case "LeftLeg": { 
				_plData.leftLeg = _plData.leftLeg + 1;
				break;            
			}
			case "RightLeg": { 
				_plData.rightLeg = _plData.rightLeg + 1;
				break;            
			}
			case "Torso": { 
				_plData.torso = _plData.torso + 1;
				break;            
			}
			case "Head": { 
				_plData.head = _plData.head + 1;
				break;            
			}
			case "LeftHand": { 
				_plData.leftHand = _plData.leftHand + 1;
				break;            
			}
			case "RightHand": { 
				_plData.rightHand = _plData.rightHand + 1;
				break;            
			}
			case "LeftArm": { 
				_plData.leftArm = _plData.leftArm + 1;
				break;            
			}
			case "RightArm": { 
				_plData.rightArm = _plData.rightArm + 1;
				break;            
			}
		}


		// обновляем килы в долгосрочном файле
		if (source.IsWeapon() || source.IsMeleeWeapon()) {

			if (!source.IsMeleeWeapon())
				distance = Math.Round(vector.Distance(player.GetPosition(), victim.GetPosition()));
			else distance = 0;

			// обновление данных оружия в долгосрочном файле
			weaponsData = _KillerAllInfo.getWeaponsData();

			if (!weaponsData)
				return;

			ref WeaponStatistic killerWPStat = NULL;
			ref WeaponStatistic victimWPStat = NULL;

			if (weaponsData.Find(wpName, killerWPStat)) {
				killerWPStat.producedHits = killerWPStat.producedHits + 1;
				killerWPStat.damageDealt = killerWPStat.damageDealt + damageResult.GetDamage(dmgZone, "Health");
				if (killerWPStat.longestHit < distance) killerWPStat.longestHit = distance;
			} else {
				killerWPStat = new WeaponStatistic();
				killerWPStat.weaponName = wpName;
				killerWPStat.producedHits = 1;
				killerWPStat.longestHit = distance;
				killerWPStat.damageDealt = damageResult.GetDamage(dmgZone, "Health");
				_KillerAllInfo.weaponsData.Insert(wpName, killerWPStat);
			}

			weaponsData = _VictimAllInfo.getWeaponsData();
			
			if (!weaponsData)
				return;

			if (weaponsData.Find(wpName, victimWPStat)) {
				// статистика оружия жертвы
				victimWPStat.receivedHits = victimWPStat.receivedHits + 1;
				victimWPStat.damageTaken = victimWPStat.damageTaken + damageResult.GetDamage(dmgZone, "Health");
			} else {
				// статистика оружия жертвы
				victimWPStat = new WeaponStatistic();
				victimWPStat.weaponName = wpName;
				victimWPStat.receivedHits = 1;
				victimWPStat.damageTaken = damageResult.GetDamage(dmgZone, "Health");
				_VictimAllInfo.weaponsData.Insert(wpName, victimWPStat);
			}

			JsonFileLoader<ref PlayerStatisticAllInfo>.JsonSaveFile(S_COMMON + killerSteamId + ".json",   _KillerAllInfo);
			JsonFileLoader<ref PlayerStatisticAllInfo>.JsonSaveFile(S_COMMON + victimSteamId + ".json",   _VictimAllInfo);
			JsonFileLoader<ref PlayerStatisticInfo>.JsonSaveFile(S_PLAYERS + killerSteamId + ".json", _plData);
		}

		// Print("Дата : [distance]  : " 		+ distance.ToString());
	}

	// ***************************************************************************************************
	// Suicide Section
	// ***************************************************************************************************
	void Suicide(PlayerBase player)  // EmoteManager.c 
	{
		if (player && player.GetIdentity()) {
			Print("Fuck, " + player.GetIdentity().GetName() +  " commited Suicided");
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

	protected string GetAnnouncePlayerPrefix(PlayerIdentity identity)  // player name prefix for announcements
	{
		string a_PlayerName = "Survivor (AI)";
		if (identity)
			a_PlayerName = identity.GetName();

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

}