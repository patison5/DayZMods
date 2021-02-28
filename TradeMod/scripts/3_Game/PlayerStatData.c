class PlayerStatisticInfo
{
	string steamID64 = "";
	string playerName = "";
	int kills = 0;
	int deadth = 0;
	int killstreak = 0;
	float maxRangeKill = 0;

	int leftFoot = 0;
	int rightFoot = 0;
	int leftLeg = 0;
	int rightLeg = 0;
	int torso = 0;
	int head = 0;
	int leftHand = 0;
	int rightHand = 0;
	int leftArm = 0;
	int rightArm = 0;

	void PlayerStatisticInfo() {}

	void setSteamId (string steamID64) {
		this.steamID64 = steamID64;
	}

	void setPlayerName (string playerName) {
		this.playerName = playerName;
	}
}