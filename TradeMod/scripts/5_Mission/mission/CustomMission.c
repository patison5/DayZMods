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

		Print("CreateCharacter завершил работу");

		return m_player;
	}

	override void OnInit()
	{
		super.OnInit();
		string line_content; 
		EntityAI newObject;
		vector vecPos;
		array<string> strFileParam;
		FileHandle file;
		
		file = OpenFile("$profile:ServerCFG/Object.ini", FileMode.READ);

		if (file != 0)
		{ 
			while ( FGets( file,  line_content ) > 0 )    
			{
				
				strFileParam = new array<string>;
				line_content.Split( "|", strFileParam );
				vecPos = strFileParam.Get(1).ToVector();
				//Print(strFileParam.Get(0));
				
				newObject = GetGame().CreateObject(strFileParam.Get(0),vecPos , false);
				
				if (newObject)
				{
					newObject.SetPosition(vecPos);
					newObject.SetOrientation(strFileParam.Get(2).ToVector());
					if (newObject.IsInherited(Building)) 
					{
						Building building = Building.Cast(newObject);
						for (int m = 0; m < 100; ++m) 
						{
							int doorIndex = building.GetDoorIndex(m);
							if(doorIndex!=-1) 
							{	
								building.CloseDoor(doorIndex);
							} 
						}
						
						if (strFileParam.Count()>3) 
						{	
							if (strFileParam.Get(3) == "L") 
							{
								for (int k = 0; k < 100; ++k)
								{
									int doorIndex1 = building.GetDoorIndex(k);
									if(doorIndex1!=-1) 
									{
										if (!building.IsDoorLocked(doorIndex1))
										{
											building.LockDoor(doorIndex1);
										}
									}
								}
							}	
							if (strFileParam.Get(3) == "DYM") 
							{
								Particle m_ParticleDym = GetGame().CreateObject( "ConvoyParticle2", vecPos, false, true);
								m_ParticleDym.SetPosition(vecPos);
							}							
						}
						

					}
				}
			}
			CloseFile(file);
		}	
	}
};