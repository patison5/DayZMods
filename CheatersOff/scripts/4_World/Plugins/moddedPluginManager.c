modded class PluginManager {
	override void Init ()
	{	

		if (GetGame().IsServer() && GetGame().IsMultiplayer())
		{
			RegisterPlugin(	"BurryCheatersOff", false, true);
		}

		super.Init();
	}
}