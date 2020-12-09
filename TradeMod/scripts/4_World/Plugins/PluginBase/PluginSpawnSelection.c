class PluginSpawnSelection extends PluginBase 
{

	ref map<string, array<vector>> spawnDots = new map<string, array<vector>>();

	void PluginSpawnSelection () {
		spawnDots["Zeleno"] = {
			"0 1 0",
			"1 1 0",
			"0 1 1"
			"1 1 1"
		};

		spawnDots["cherno"] = {
			"0 1 0",
			"1 1 0",
			"0 1 1"
			"1 1 1"
		};
	}


	void TeleportToPoint(array<string> args, PlayerBase player)
	{
		if(args.Count() == 3)
		{
			float x = args[0].ToFloat();
			float y = args[1].ToFloat();
			float z = args[2].ToFloat();
			
			if (y <= 0)
				y = GetGame().SurfaceY(x, z);
			
			
			if(player != null)
			{
				player.SetPosition(Vector(x, y, z));
			}
		}
	}

}