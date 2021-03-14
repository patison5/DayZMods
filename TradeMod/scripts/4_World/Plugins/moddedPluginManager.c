modded class PluginManager {
	override void Init ()
	{	

		if (GetGame().IsServer() && GetGame().IsMultiplayer())
		{
			RegisterPlugin(	"PluginPlayersTop", false, true);
			RegisterPlugin( "HHDeadMatchPlugin", false, true);
			RegisterPlugin( "PluginAdminNotification", false, true);
			RegisterPlugin( "PluginSpawnSelection", false, true);
			// RegisterPlugin( "WeeklyKing", false, true);
		}


		if (GetGame().IsClient() && GetGame().IsMultiplayer()) {
			RegisterPlugin( "PluginTopNotification", true, false);
			RegisterPlugin( "HHDeadMatchClientPlugin", true, false);
			RegisterPlugin( "EarPlugs", true, false);
			// RegisterPlugin ("HHUpdateTop", true, false);
		}

		super.Init();
	}
}