class CustomMission: MissionServer
{

	ref PluginSpawnSelection spawnPlugin;

	void CustomMission () {
		spawnPlugin = GetSpawnPlugin();
	}


	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
			
		Print("CreateCharacter был вызван!");
		
		vector newPos = Vector(0, 0, 0);
		Entity playerEnt;

		if (spawnPlugin)
			newPos = spawnPlugin.getPosition();
		else {
			Print("spawnPlugin не был создан блять")
		}

		playerEnt = GetGame().CreatePlayer(identity, characterName, newPos, 0, "NONE"); //Creates random player
		Class.CastTo(m_player, playerEnt);
		
		GetGame().SelectPlayer(identity, m_player);

		m_player.SetHealth("","Health", 100);
		m_player.SetHealth("","Blood", 5000);
		m_player.GetStatEnergy().Add(m_player.GetStatEnergy().GetMax());
		m_player.GetStatWater().Add(m_player.GetStatWater().GetMax());

		return m_player;
	}
};