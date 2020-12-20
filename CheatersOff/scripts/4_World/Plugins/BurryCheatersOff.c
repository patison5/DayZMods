ref BurryCheatersOff hh_burryCheatersOff;

ref BurryCheatersOff GetBurryCheatersOff() {
	if (!hh_burryCheatersOff)
		hh_burryCheatersOff = new ref BurryCheatersOff();	

	return hh_burryCheatersOff;
}



class BurryCheatersOff extends PluginBase 
{

	ref PlayersData _plData;

	void BurryCheatersOff () {
		Print("BurryCheatersOff был создан");
		_plData = new PlayersData();
	}


	void readPlayerData (PlayerBase player) {
		string steamId = player.GetIdentity().GetPlainId();

		if (!FileExist(S_ROOTFOLDER)) MakeDirectory(S_ROOTFOLDER)

		// check file existance and get setup options
		if (!FileExist(S_ROOTFOLDER + steamId + ".json")) {
			string name = GetAnnouncePlayerPrefix(player.GetIdentity());

			_plData = new PlayersData();
			_plData.setSteamId(steamId);
			_plData.setPlayerName(name);

			JsonFileLoader<ref PlayersData>.JsonSaveFile(S_ROOTFOLDER + steamId + ".json", _plData);	
		} else {
			JsonFileLoader<ref PlayersData>.JsonLoadFile(S_ROOTFOLDER + steamId + ".json", _plData);
		}	
	}

	void updateData (PlayerBase player, int burryCount, int digOutCount) {

		string steamId = player.GetIdentity().GetPlainId();

		readPlayerData(player);

		_plData.burryCount  = _plData.burryCount  + burryCount;
		_plData.digOutCount = _plData.digOutCount + digOutCount;

		JsonFileLoader<ref PlayersData>.JsonSaveFile(S_ROOTFOLDER + steamId + ".json", _plData);

		// сюда уже можно писать обращение в админку (если я верно понял)
		if (burryCount == 1)  {} // закапываем
		if (digOutCount == 1) {} // раскапываем
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
}


class PlayersData
{
	string playerName;
	string steamID64;
	int burryCount = 0;
	int digOutCount = 0;

	void setSteamId (string steamID64) {
		this.steamID64 = steamID64;
	}

	void setPlayerName (string playerName) {
		this.playerName = playerName;
	}
}