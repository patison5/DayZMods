class HeadHunterDMInfo
{
	string kingSteamID64 = "";
	string kingUpdateDate = "";
	string previousKingSteamID64 = "";

	int roundType = 0;

	void updateRoundType() {
		// Print((this.roundType + 1) % 4);
		Print("обновляю тип раунда");

		this.roundType = this.roundType + 1;
		if (this.roundType > 2) this.roundType = 0;

		roundNumber = this.roundType;
		Print(roundNumber);
	}

	void HeadHunterDMInfo() { }

	void updateKingData (string steamid, string kingUpdateDate) {
		this.kingSteamID64 = steamid;
		this.kingUpdateDate = kingUpdateDate;
	}
}