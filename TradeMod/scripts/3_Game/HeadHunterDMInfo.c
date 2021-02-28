class HeadHunterDMInfo
{
	string kingSteamID64 = "";
	string kingUpdateDate = "";

	void HeadHunterDMInfo() { }

	void updateKingData (string steamid, string kingUpdateDate) {
		this.kingSteamID64 = steamid;
		this.kingUpdateDate = kingUpdateDate;
	}
}