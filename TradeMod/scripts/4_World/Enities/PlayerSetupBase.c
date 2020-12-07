class PlayerSetupBase
{
	private PlayerBase player;

	void PlayerSetupBase() {}

	void setupPlayer (PlayerBase player) {
		this.player = player;

		player.SetHealth("","",20);
		addGranade(player);
	}

	void addGranade (PlayerBase player) {
		player.GetHumanInventory().CreateInHands("RGD5Grenade");
	}
}