class PlayerStatData
{

	ref array<ref PlayerStatisticInfo> _players = new array<ref PlayerStatisticInfo>;
	// PluginPlayersTop ppStatiscic;

	// void addNewPlayer (string steamID64, string playerName) 
	// {
	// 	PlayerStatisticInfo plInfo = new PlayerStatisticInfo(steamID64, playerName);
	// 	_players.Insert(plInfo);
	// }


	ref array<ref PlayerStatisticInfo> getAllPlayers () {
		return _players;
	}
}


class PlayerStatisticInfo
{
	string steamID64 = "";
	string playerName = "";
	int kills = 0;
	int deadth = 0;
	int killstreak = 0;
	float maxRangeKill = 0;

	void PlayerStatisticInfo() {}

	void setSteamId (string steamID64) {
		this.steamID64 = steamID64;
	}

	void setPlayerName (string playerName) {
		this.playerName = playerName;
	}
}