class PluginSpawnSelection extends PluginBase 
{
	ref map<string, ref array<vector>> spawnDots = new map<string, ref array<vector>>();

	ref map<string, ref array<string>> spawnVotingData = new map<string, ref array<string>>();
	
	void PluginSpawnSelection () {		

		Print("создаю PluginSpawnSelection");

		array<vector> places1 = new array<vector>();
		places1.Insert(Vector(2516.596680, 193.394867, 5140.407715));
    	places1.Insert(Vector(2531.264648, 193.549896, 5087.577637));
    	places1.Insert(Vector(2469.913574, 192.669312, 5072.654785));
    	places1.Insert(Vector(2588.320068, 194.510468, 5113.080078));
    	places1.Insert(Vector(2625.109375, 196.029755, 5100.684570));
    	places1.Insert(Vector(2668.590576, 196.794327, 5128.273926));
    	places1.Insert(Vector(2688.285400, 196.112473, 5101.455566));
    	places1.Insert(Vector(2654.471680, 194.158737, 5052.908203));		
    	spawnDots["Zeleno"] = places1;


		array<vector> places2 = new array<vector>();
		places2.Insert(Vector(4580.207520, 318.898407, 8235.764648));
    	places2.Insert(Vector(4583.390625, 318.874390, 8340.412109));
    	places2.Insert(Vector(4534.895020, 316.924164, 8370.986328));
    	places2.Insert(Vector(4434.421875, 313.638092, 8288.986328));
    	places2.Insert(Vector(4448.309570, 313.839783, 8254.834961));
    	places2.Insert(Vector(4439.412598, 317.669586, 8148.401367));
    	places2.Insert(Vector(4436.063965, 313.111816, 8234.270508));
		spawnDots["vybor"] = places2;


		array<vector> places3 = new array<vector>();
		places3.Insert(Vector(4759.235352, 339.175171, 10402.34960));
    	places3.Insert(Vector(4815.115723, 339.659088, 10371.28222));
    	places3.Insert(Vector(4802.574219, 339.002380, 10322.37988));
    	places3.Insert(Vector(4845.842773, 338.962463, 10305.45214));
    	places3.Insert(Vector(4848.176270, 338.932434, 10356.00000));
    	places3.Insert(Vector(4854.617676, 339.490845, 10438.65234));
    	places3.Insert(Vector(4801.229980, 339.132385, 10527.33886));
    	places3.Insert(Vector(4720.517578, 339.162445, 10538.62304));
    	places3.Insert(Vector(4693.757813, 339.198120, 10459.64648));
    	places3.Insert(Vector(4666.294922, 339.012451, 10424.65234));
    	places3.Insert(Vector(4611.094238, 339.185913, 10435.88085));
    	places3.Insert(Vector(4597.382813, 339.015686, 10491.06054));
    	places3.Insert(Vector(4664.059570, 339.691406, 10495.69335));
		spawnDots["csAero"] = places3;

		JsonFileLoader<ref map<string, ref array<vector>>>.JsonSaveFile(S_ROOTFOLDER + "spawnDots.json",  spawnDots);			


		spawnVotingData["Zeleno"] = new array<string>();
		spawnVotingData["vybor"]  = new array<string>();
		spawnVotingData["csAero"] = new array<string>();

		if (GetGame().IsServer()) {
			GetDayZGame().Event_OnRPC.Insert(ServerRPCHandler);
			Print("PluginSpawnSelection был проинициализирован");
		}

		resetMapVotes();
	}

	vector getPosition() {
		// player.SetPosition(Vector(x, y, z));

		ref array<Man> players = new array<Man>;
		GetGame().GetPlayers( players );
		PlayerBase player;

		int counter = Math.RandomInt(0, spawnDots[spawnLocation].Count() - 1);

		vector newPos = spawnDots[spawnLocation].Get(counter);

		bool canSpawn;

		while (true) {
			canSpawn = true;

			foreach (auto pl : players) {
				Class.CastTo(player, pl);

				if (player.IsAlive()) {
					float dis = vector.Distance( spawnDots[spawnLocation].Get(counter), player.GetPosition());
					if (dis < 20) { canSpawn = false; break; }
				}
			}

			if (canSpawn) {
				newPos = spawnDots[spawnLocation].Get(counter);
				break;
			}

			if (counter < spawnDots[spawnLocation].Count() - 1) counter++;
			else counter = Math.RandomInt(0, spawnDots[spawnLocation].Count() - 1);
		}

		newPos[1] = GetGame().SurfaceY(newPos[0], newPos[2]);

		return newPos;
	}


	void resetMapVotes () {
		spawnVotingData["Zeleno"].Clear();
		spawnVotingData["vybor"].Clear();
		spawnVotingData["csAero"].Clear();
	}

	void selectCurrentMap() {
		Print("Выбираем следующую карту!");

		string currentMap = "";
		int max = -1;

		foreach(string key, ref array<string> votes: spawnVotingData) {
			Print("mapa[" + key + "] = " + votes.Count());

			if (max < votes.Count()) {
				currentMap = key;
				max = votes.Count();
			}
		}



		if (currentMap != "")
			spawnLocation = currentMap;

		Print(currentMap);

		resetMapVotes();
	}

	void updateVoteData (string selectedMap, string steamid) {
		// Print("ОБНОВЛЯЕМ ДАТУ ГОЛОСОВАНИЯ!");
		// Print("steamid : " + steamid);
		// Print("selectedMap : " + selectedMap);

		foreach (string mapName, ref array<string> votes: spawnVotingData) {
			// insert
			if (mapName == selectedMap) {
				votes.Insert(steamid);
				continue;
			}

			// remove
			for (int i = 0; i < votes.Count(); i++) {
				if (steamid == votes[i])
					votes.Remove(i);
			}
		}
	}

	ref map<string, int> getVoteData () {
		// Print("Считаем кол-во голосов");

		ref map<string, int> voteData = new map<string, int>();

		voteData["Zeleno"] = 0;
		voteData["vybor"] = 0;
		voteData["csAero"] = 0;

		foreach (string mapName, ref array<string> votes: spawnVotingData) {
			// Print("[" + mapName + "] : " + votes.Count());
			voteData[mapName] = votes.Count();
		}

		return voteData;
	}

	void ServerRPCHandler(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {

		Param1<string> arg;
        if (!ctx.Read(arg)) return;

        string steamid = arg.param1;

        if (GetGame().IsClient()) {
            delete this;
            return;
        }

        switch (rpc_type) {
            case HHRPCEnum.RPC_SELECT_MAP_1: { 
                updateVoteData("Zeleno", steamid);
                break;            
            }

            case HHRPCEnum.RPC_SELECT_MAP_2: { 
                updateVoteData("vybor", steamid);
                break;            
            }

            case HHRPCEnum.RPC_SELECT_MAP_3: { 
                updateVoteData("csAero", steamid);
                break;            
            }
        }
    }




}


ref PluginSpawnSelection spawnPlugin;

ref PluginSpawnSelection GetSpawnPlugin() {
	if (!spawnPlugin)
		spawnPlugin = PluginSpawnSelection.Cast(GetPlugin(PluginSpawnSelection));	

	return spawnPlugin;
}

