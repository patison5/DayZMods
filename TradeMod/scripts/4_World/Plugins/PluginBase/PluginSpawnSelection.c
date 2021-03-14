class PluginSpawnSelection extends PluginBase 
{
	ref map<string, ref array<vector>> spawnDots = new map<string, ref array<vector>>();
	ref map<string, ref array<string>> spawnVotingData = new map<string, ref array<string>>();
	
	void PluginSpawnSelection () {		

		array<vector> places1 = new array<vector>();
		places1.Insert(Vector(2632.409424, 191.722443, 5006.912109));
		places1.Insert(Vector(2602.832520, 191.198257, 4998.001953));
		places1.Insert(Vector(2558.293213, 191.458527, 4989.467285));
		places1.Insert(Vector(2534.413818, 193.330292, 4995.046387));
		places1.Insert(Vector(2471.960938, 188.377319, 4999.649414));
		places1.Insert(Vector(2452.515625, 187.652145, 5012.435059));
		places1.Insert(Vector(2417.671387, 189.959152, 5050.019043));
		places1.Insert(Vector(2379.700439, 190.255173, 5078.704590));
		places1.Insert(Vector(2373.611816, 188.921600, 5119.500977));
		places1.Insert(Vector(2327.522217, 185.332291, 5188.230469));
		places1.Insert(Vector(2336.676270, 186.117920, 5219.845703));
		places1.Insert(Vector(2361.476074, 189.444641, 5229.435059));
		places1.Insert(Vector(2397.470215, 190.382446, 5250.253906));
		places1.Insert(Vector(2450.811035, 190.365158, 5237.475586));
		places1.Insert(Vector(2469.994873, 190.322067, 5235.270508));
		places1.Insert(Vector(2475.492920, 190.076233, 5285.433594));
		places1.Insert(Vector(2501.857910, 190.142502, 5294.123535));
		places1.Insert(Vector(2584.356934, 191.482483, 5309.045898));
		places1.Insert(Vector(2624.906982, 202.046341, 5365.954590));
		places1.Insert(Vector(2643.390137, 205.388046, 5406.110352));
		places1.Insert(Vector(2656.631592, 206.332825, 5447.166504));
		places1.Insert(Vector(2672.547607, 207.193512, 5475.068848));
		places1.Insert(Vector(2688.712158, 207.487747, 5506.207031));
		places1.Insert(Vector(2720.840576, 207.457474, 5487.750000));
		places1.Insert(Vector(2755.246826, 209.356979, 5462.042969));
		places1.Insert(Vector(2788.396973, 208.677338, 5448.437988));
		places1.Insert(Vector(2853.117432, 212.501053, 5473.542969));
		places1.Insert(Vector(2867.146973, 211.954575, 5427.954102));
		places1.Insert(Vector(2844.134277, 210.699783, 5404.666992));
		places1.Insert(Vector(2832.638184, 207.534164, 5358.731445));
		places1.Insert(Vector(2870.470703, 205.120529, 5300.924316));
		places1.Insert(Vector(2893.415039, 206.729019, 5260.420410));
		places1.Insert(Vector(2803.993164, 204.462463, 5246.951660));
		places1.Insert(Vector(2772.670898, 204.362488, 5255.699707));
		places1.Insert(Vector(2783.275879, 204.366165, 5221.764160));
		places1.Insert(Vector(2723.373535, 200.146286, 5238.054688));
		places1.Insert(Vector(2701.431641, 200.109543, 5240.190918));
		places1.Insert(Vector(2693.275635, 199.293808, 5200.895996));
		places1.Insert(Vector(2715.783203, 199.149216, 5156.690430));
		places1.Insert(Vector(2753.800537, 193.914124, 5075.193359));
		places1.Insert(Vector(2752.460938, 193.926834, 5052.015137));
		places1.Insert(Vector(2691.020508, 194.700089, 5058.791504));
		places1.Insert(Vector(2638.677246, 194.833618, 5069.543945));
		places1.Insert(Vector(2647.735840, 196.005249, 5118.962891));
		places1.Insert(Vector(2585.249512, 193.627045, 5128.844238));
		places1.Insert(Vector(2505.098633, 193.392014, 5145.173828));
		places1.Insert(Vector(2479.906250, 193.223785, 5063.100586));
		places1.Insert(Vector(2486.775391, 193.456100, 5063.300293));
		places1.Insert(Vector(2503.106934, 193.846283, 5021.262207));
		places1.Insert(Vector(2537.154297, 194.303986, 5027.508301));
		places1.Insert(Vector(2535.254395, 193.650024, 5069.390625));
		places1.Insert(Vector(2550.119385, 193.262497, 5115.233887));
		places1.Insert(Vector(2626.631836, 196.379120, 5160.418457));
		places1.Insert(Vector(2654.419678, 198.394608, 5157.628418));
		places1.Insert(Vector(2636.513672, 199.071503, 5196.865723));
		places1.Insert(Vector(2640.278320, 198.878952, 5252.074219));
		places1.Insert(Vector(2651.709473, 204.124893, 5265.248047));
		places1.Insert(Vector(2694.231445, 206.598694, 5331.712402));
		places1.Insert(Vector(2769.902344, 206.522873, 5372.003906));
		places1.Insert(Vector(2801.205566, 206.791840, 5366.99316));	
    	spawnDots["Zeleno"] = places1;


		array<vector> places2 = new array<vector>();
		places2.Insert(Vector(4441.466797, 333.430817, 8046.941406));
		places2.Insert(Vector(4404.048340, 317.501160, 7996.770508));
		places2.Insert(Vector(4438.922363, 314.537201, 7995.993164));
		places2.Insert(Vector(4471.205566, 317.262878, 8016.958008));
		places2.Insert(Vector(4548.137695, 313.702972, 8091.190430));
		places2.Insert(Vector(4617.695313, 316.814819, 8049.725098));
		places2.Insert(Vector(4684.883789, 322.196136, 8075.195313));
		places2.Insert(Vector(4860.405762, 330.399780, 8157.402832));
		places2.Insert(Vector(4801.758301, 327.645325, 8173.951660));
		places2.Insert(Vector(4778.057617, 326.986481, 8232.391602));
		places2.Insert(Vector(4758.390137, 326.252838, 8246.251953));
		places2.Insert(Vector(4748.124023, 325.891541, 8251.452148));
		places2.Insert(Vector(4743.806152, 325.817078, 8274.195313));
		places2.Insert(Vector(4718.043457, 324.641907, 8233.906250));
		places2.Insert(Vector(4710.915527, 324.555145, 8253.857422));
		places2.Insert(Vector(4708.014160, 324.801483, 8308.031250));
		places2.Insert(Vector(4675.955566, 323.246246, 8338.751953));
		places2.Insert(Vector(4571.043945, 315.219116, 8515.541016));
		places2.Insert(Vector(4563.257324, 316.191498, 8463.403320));
		places2.Insert(Vector(4514.881348, 316.972473, 8417.991211));
		places2.Insert(Vector(4491.665039, 316.508484, 8414.923828));
		places2.Insert(Vector(4465.499023, 315.141785, 8389.846680));
		places2.Insert(Vector(4440.750977, 315.902771, 8397.385742));
		places2.Insert(Vector(4428.910156, 314.843262, 8382.034180));
		places2.Insert(Vector(4421.064941, 314.234436, 8358.153320));
		places2.Insert(Vector(4410.333008, 313.645721, 8319.722656));
		places2.Insert(Vector(4412.641113, 313.513641, 8264.697266));
		places2.Insert(Vector(4398.900879, 313.117920, 8252.110352));
		places2.Insert(Vector(4398.907227, 311.616821, 8194.738281));
		places2.Insert(Vector(4392.868652, 317.174652, 8130.150391));
		places2.Insert(Vector(4408.417480, 323.769897, 8116.099609));
		places2.Insert(Vector(4423.407715, 322.373505, 8128.585449));
		places2.Insert(Vector(4468.223633, 316.881317, 8139.999023));
		places2.Insert(Vector(4502.354980, 315.529144, 8258.392578));
		places2.Insert(Vector(4520.691406, 316.657379, 8353.495117));
		places2.Insert(Vector(4425.158691, 313.394958, 8278.940430));
		places2.Insert(Vector(4569.800781, 318.034119, 8372.633789));
		places2.Insert(Vector(4555.932129, 316.537903, 8397.320313));
		places2.Insert(Vector(4266.012695, 307.302673, 8195.20019));
		places2.Insert(Vector(4644.732422, 322.085999, 8266.701172));
		places2.Insert(Vector(4686.069824, 323.997589, 8291.224609));
		places2.Insert(Vector(4704.114746, 324.139679, 8229.900391));
		places2.Insert(Vector(4689.158203, 325.283966, 8259.18945));
		places2.Insert(Vector(4588.319336, 314.131042, 7981.230469));
		places2.Insert(Vector(4516.711426, 309.641235, 8016.203613));
		places2.Insert(Vector(4568.830078, 313.909973, 8099.043945));
		places2.Insert(Vector(4738.888184, 325.231415, 8064.002930));
		places2.Insert(Vector(4797.801758, 327.629578, 8075.729492));
		places2.Insert(Vector(4896.115723, 332.628265, 8146.889648));
		places2.Insert(Vector(4888.265625, 332.316437, 8168.509766));
		places2.Insert(Vector(4614.845703, 320.012054, 8361.622070));
		places2.Insert(Vector(4675.501465, 323.225922, 8338.94043));
		spawnDots["vybor"] = places2;


		array<vector> places3 = new array<vector>();
		places3.Insert(Vector(12224.646484, 140.012421, 12519.698242));
		places3.Insert(Vector(12300.317383, 140.012482, 12518.695313));
		places3.Insert(Vector(12332.761719, 140.012405, 12499.563477));
		places3.Insert(Vector(12452.063477, 140.012390, 12455.317383));
		places3.Insert(Vector(12459.202148, 140.012451, 12454.411133));
		places3.Insert(Vector(12486.811523, 140.012482, 12471.421875));
		places3.Insert(Vector(12484.000977, 140.379929, 12485.321289));
		places3.Insert(Vector(12521.222656, 142.853394, 12514.738281));
		places3.Insert(Vector(12514.176758, 141.432541, 12526.303711));
		places3.Insert(Vector(12537.041992, 154.279785, 12604.005859));
		places3.Insert(Vector(12517.719727, 152.362106, 12639.277344));
		places3.Insert(Vector(12444.221680, 152.133743, 12745.134766));
		places3.Insert(Vector(12420.805664, 144.822250, 12697.681641));
		places3.Insert(Vector(12320.655273, 143.051453, 12761.553711));
		places3.Insert(Vector(12296.920898, 143.916489, 12813.797852));
		places3.Insert(Vector(11934.445313, 139.845718, 12866.604492));
		places3.Insert(Vector(11828.623047, 140.319153, 12769.699219));
		places3.Insert(Vector(11708.390625, 140.263062, 12616.458984));
		places3.Insert(Vector(11750.735352, 140.025055, 12587.820313));
		places3.Insert(Vector(11744.568359, 143.165009, 12431.824219));
		places3.Insert(Vector(11765.271484, 141.049850, 12394.749023));
		places3.Insert(Vector(11803.713867, 141.753387, 12369.993164));
		places3.Insert(Vector(11693.954102, 158.150497, 12301.069336));
		places3.Insert(Vector(11714.786133, 157.224014, 12285.881836));
		places3.Insert(Vector(11714.791992, 157.227936, 12285.852539));
		places3.Insert(Vector(11742.135742, 149.277725, 12211.892578));
		places3.Insert(Vector(11836.135742, 142.804321, 12332.612305));
		places3.Insert(Vector(11878.375000, 142.484772, 12319.447266));
		places3.Insert(Vector(11900.648438, 142.025177, 12370.391602));
		places3.Insert(Vector(11948.856445, 142.178802, 12367.068359));
		places3.Insert(Vector(11996.259766, 141.440506, 12340.762695));
		places3.Insert(Vector(12093.231445, 130.931915, 12301.583984));
		places3.Insert(Vector(12114.474609, 128.983749, 12297.620117));
		places3.Insert(Vector(12139.211914, 127.793564, 12288.688477));
		places3.Insert(Vector(12179.733398, 125.111694, 12281.314453));
		places3.Insert(Vector(12199.802734, 123.885826, 12272.375000));
		places3.Insert(Vector(12232.650391, 121.571457, 12249.706055));
		places3.Insert(Vector(12382.803711, 113.771965, 12209.630859));
		places3.Insert(Vector(12394.602539, 117.758972, 12242.578125));
		places3.Insert(Vector(12441.714844, 125.030190, 12261.425781));
		places3.Insert(Vector(12566.886719, 123.736046, 12270.991211));
		places3.Insert(Vector(12595.439453, 138.670792, 12360.918945));
		places3.Insert(Vector(12568.208008, 138.529877, 12379.018555));
		places3.Insert(Vector(12534.680664, 139.675507, 12392.145508));
		places3.Insert(Vector(11861.308594, 140.012512, 12525.054688));
		places3.Insert(Vector(11865.523438, 140.012405, 12478.839844));
		places3.Insert(Vector(11972.182617, 140.012497, 12478.552734));
		places3.Insert(Vector(11981.427734, 140.012451, 12489.181641));
		places3.Insert(Vector(11992.548828, 140.012451, 12505.455078));
		places3.Insert(Vector(12181.345703, 140.012497, 12570.337891));
		places3.Insert(Vector(12223.925781, 140.422379, 12604.748047));
		places3.Insert(Vector(12237.099609, 140.120956, 12628.397461));
		places3.Insert(Vector(12032.482422, 140.012436, 12632.93261));
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

		// // вот это временно
		// spawnLocation = "vybor";

		Print(currentMap);

		resetMapVotes();
	}

	void updateVoteData (string selectedMap, string steamid) {
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
		ref map<string, int> voteData = new map<string, int>();

		voteData["Zeleno"] = 0;
		voteData["vybor"] = 0;
		voteData["csAero"] = 0;

		foreach (string mapName, ref array<string> votes: spawnVotingData) {
			voteData[mapName] = votes.Count();
		}

		return voteData;
	}

	void ServerRPCHandler(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        
        if (GetGame().IsClient()) {
            delete this;
            return;
        }

        switch (rpc_type) {
            case HHRPCEnum.RPC_SELECT_MAP_1: { 
            	Param1<string> farg1;
        		if (!ctx.Read(farg1)) return;

                updateVoteData("Zeleno", farg1.param1);
                break;            
            }

            case HHRPCEnum.RPC_SELECT_MAP_2: { 
            	Param1<string> farg2;
        		if (!ctx.Read(farg2)) return;

                updateVoteData("vybor", farg2.param1);
                break;            
            }

            case HHRPCEnum.RPC_SELECT_MAP_3: { 
            	Param1<string> farg3;
        		if (!ctx.Read(farg3)) return;

                updateVoteData("csAero", farg3.param1);
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

