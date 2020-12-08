class HHDeadMatchPlugin extends PluginBase
{
	// Timers
    private ref Timer                   roundTimer;
    private ref Timer                   delayTimeout;
    private ref Timer                   showDelayTimeout;

    bool isEnded = false;
    private int timeOut = 15;
    private int roundTime = 60;

    private int timeOutCounter = timeOut;

    private ref array<ref PlayerStatisticInfo> _players = new array<ref PlayerStatisticInfo>;

    void HHDeadMatchPlugin () {
    	Print("HHDeadMatchPlugin был проинициализирован");

        // delete that function

    	roundTimer	= new ref Timer();
        roundTimer.Run(roundTime, this, "endRound", NULL, true);
    }


    void endRound () {
    	if (GetGame().IsServer()) {
            Print(TOP_PREFIX + "Раунд закончился");

	    	delayTimeout = new ref Timer();

            summurizePlayersStatistic();
            getBestTenPlayers();
    		showPlayerEndedGUI();

    		delayTimeout.Run(timeOut, this, "startRound", new Param1<string>(" новый раунд начался"), false);
    		changeTimer(); //обратный отсчет на клиенте
	    }
    }

    void summurizePlayersStatistic () {
    	// собираем всю информацию по игрокам
        Print("Начинаем собирать статисику по каждому игроку");

        TStringArray fileNamesList = this.getPlayersList();
        _players = new array<ref PlayerStatisticInfo>;
        
        for ( int k = 0; k < fileNamesList.Count(); ++k ) {
            string fileName = fileNamesList.Get(k);

            if (!FileExist(S_PLAYERS + fileName + ".json")) {
                continue;
            } else {
                PlayerStatisticInfo _plData = new PlayerStatisticInfo();
                JsonFileLoader<ref PlayerStatisticInfo>.JsonLoadFile(S_PLAYERS + fileName + ".json", _plData);

                _players.Insert(_plData);
                Print("НАШЕЛ ОЧЕРЕДНОЙ ЭЛЕМЕНТ " + k.ToString());
            }   
        }
    }

    void getBestTenPlayers () {
    	// сортируем и берем 10 лучших игроков 

        for (int i = 0; i < _players.Count(); i++) {
            bool flag = true;

            for (int j = 0; j < _players.Count() - (i + 1); j++) { 
                if (_players.Get(j).kills < _players.Get(j + 1).kills) {
                    flag = false;

                    // auto tmp = _players.Get(j);
                    // _players.Set(j, _players.Get(j + 1));
                    // _players.Set(j + 1, tmp);

                    _players.SwapItems(j, j + 1);
                }
            }

            if (flag)
                break;
        }
    }

  

    void resetPlayersStatistic () {
    	// сбрасываем статистику
        TStringArray fileNamesList = this.getPlayersList();

        for ( int i = 0; i < fileNamesList.Count(); ++i ) {
            string fileName = fileNamesList.Get(i);
            if (FileExist(S_PLAYERS + fileName + ".json")) DeleteFile(S_PLAYERS + fileName + ".json");
        }
    }

    void startRound (string msg) {
    	// SendMessageToAll(msg);
    	closePlayerEndedGUI();
   		killAllPlayers();
        // resetPlayersStatistic();
    }




    void showPlayerEndedGUI () {
        Print("ОТПРАВЛЯЮ РПС НА КЛИЕНТЫ");

    	// отображаем игроку статистику топа и рисуем варианты выбора карты
    	ref array<Man> players = new array<Man>;
    	GetGame().GetPlayers( players );
    	foreach( auto player : players  )
        {
            if (player.GetIdentity()) {
				// auto param4 = new Param1<string>("PIDOR");
                auto param4 = new Param1<ref array<ref PlayerStatisticInfo>>(_players);

                Print("ОТПРАВЛЯЮ РПС : " + _players.Get(0).playerName);

                if (_players) Print(TOP_PREFIX + _players.Count() + "шт");

				GetGame().RPCSingleParam(player, HHRPCEnum.RPC_CLIENT_SHOW_END_SCREEN, param4, true, player.GetIdentity());
			}
        }
    }

    void closePlayerEndedGUI () {
    	// отображаем игроку статистику топа и рисуем варианты выбора карты
    	ref array<Man> players = new array<Man>;
    	GetGame().GetPlayers( players );
    	foreach( auto player : players  )
        {
            if (player.GetIdentity()) {
            	auto param5 = new Param1<string>("PIDOR");
				GetGame().RPCSingleParam(player, HHRPCEnum.RPC_CLIENT_HIDE_END_SCREEN, param5, true, player.GetIdentity());
			}
        }
    }

    void updateMainScreenTimer (string time) {
    	ref array<Man> players = new array<Man>;
    	GetGame().GetPlayers( players );
    	foreach( auto player : players  )
        {
            if (player.GetIdentity()) {
            	auto param5 = new Param1<string>(time);
				GetGame().RPCSingleParam(player, HHRPCEnum.RPC_CLIENT_UPDATE_MAIN_SCREEN_TIMER, param5, true, player.GetIdentity());
			}
        }
    }

    void killAllPlayers () {
    	ref array<Man> players = new array<Man>;
    	GetGame().GetPlayers( players );
    	foreach( auto player : players  )
        {
            player.SetHealth("","",-100);
        }
    }


    void sendMessage (PlayerBase player, string message) {
    	Param1<string> m_MessageParam = new Param1<string>(TOP_PREFIX + message);
	    GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, m_MessageParam, true, player.GetIdentity());
    }

    void changeTimer () {
		timeOutCounter = timeOutCounter - 1;

		updateMainScreenTimer(timeOutCounter.ToString());

		if (timeOutCounter > 0) {
	    	showDelayTimeout = new ref Timer();
			showDelayTimeout.Run(1, this, "changeTimer", NULL, false);
		} else {
			timeOutCounter = 15;
		}
    }


    //========================================
    // getPlayersList
    //========================================  
    TStringArray getPlayersList()
    {
        if ( !FileExist( S_PLAYERS ) )
            MakeDirectory( S_PLAYERS );

        string  file_name;
        int     file_attr;
        int     flags;
        TStringArray list = new TStringArray;
        
        string path_find_pattern = S_PLAYERS + "/*.json";
        FindFileHandle file_handler = FindFile(path_find_pattern, file_name, file_attr, flags);
        
        bool found = true;
        while ( found )
        {
            int pos = file_name.IndexOf(".");
            
            if ( pos > -1 )
                list.Insert( file_name.Substring(0, pos) );
            
            found = FindNextFile(file_handler, file_name, file_attr);
        }

        return list;
    }


    void SendMessageToAll(string message)
    {
        if (GetGame().IsServer())
        {
            ref array<Man> players = new array<Man>;
            GetGame().GetPlayers( players );
            foreach( auto player : players  )
            {
                Param1<string> m_MessageParam = new Param1<string>(message);
                GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, m_MessageParam, true, player.GetIdentity());
            }
        }
    }
}