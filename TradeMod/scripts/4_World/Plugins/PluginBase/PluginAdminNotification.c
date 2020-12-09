class PluginAdminNotification extends PluginBase 
{
	ref array<string> notificationMessages	= new array<string>;

	void PluginAdminNotification() {
		notificationMessages = {"не, ну это бан...", "БАААААН!", "Говоришь без наводки бегаешь?..", "Пизда тебе", "Да не не, откисай..", "че, где купил?", "нифига се шары..", "Это было подозрительно..", "0_о", "палишься, друг.."};
	}

	void checkSendingPossibility (PlayerBase player, int killstreak) {
		if (killstreak % 5) {
			if (Math.RandomFloat(0,1) >= 0.75) {
				int randElementIndex = Math.RandomInt(0, notificationMessages.Count() - 1);

				// sending rpc showing not message
				if (player.GetIdentity()) {
	            	auto param = new Param1<string>(notificationMessages.Get(randElementIndex));
					GetGame().RPCSingleParam(player, HHRPCEnum.RPC_SHOW_ADMIN_FUN_MESSAGE, param, true, player.GetIdentity());
				}
			}
		}
	}
}
