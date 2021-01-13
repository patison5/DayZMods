class PlayerStatisticAllInfo
{
	string steamID64 = "";
	string playerName = "";
	int kills = 0;
	int deaths = 0;
	int maxKillstreak = 0;
	float maxRangeKill = 0;
	float maxKD = 0;

	ref map<string, ref WeaponStatistic> weaponsData = new map<string, ref WeaponStatistic>();

	void PlayerStatisticInfo() {}

	void setSteamId (string steamID64) {
		this.steamID64 = steamID64;
	}

	void setPlayerName (string playerName) {
		this.playerName = playerName;
	}

	ref map<string, ref WeaponStatistic> getWeaponsData () {
		return this.weaponsData;
	}
}

class WeaponStatistic
{
	string weaponName = "";

	int kills  = 0;
	int deaths = 0;

	float damageDealt = 0;
	int producedHits = 0;

	float damageTaken = 0;
	int receivedHits = 0;

	float longestKill = 0;
	float longestHit = 0;

	void WeaponStatistic() {
		Print("создаю новый ствол");
		this.kills  = 0;
		this.deaths = 0;
		this.damageDealt = 0;
		this.producedHits = 0;
		this.damageTaken = 0;
		this.receivedHits = 0;
		this.longestKill = 0;
		this.longestHit = 0;
	}
}