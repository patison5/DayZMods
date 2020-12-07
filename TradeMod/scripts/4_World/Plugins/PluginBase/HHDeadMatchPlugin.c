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

    	roundTimer	= new ref Timer();
        roundTimer.Run(roundTime, this, "endRound", NULL, true);
    }


    void endRound () {
    	if (GetGame().IsServer()) {
            Print(TOP_PREFIX + "Раунд закончился");

	    	delayTimeout = new ref Timer();

            summurizePlayersStatistic();
    		showPlayerEndedGUI();
    		delayTimeout.Run(timeOut, this, "startRound", new Param1<string>(" новый раунд начался"), false);
    		changeTimer();
	    }
    }


    void summurizePlayersStatistic () {
    	// собираем всю информацию по игрокам
        Print("Начинаем собирать статисику по каждому игроку");

        TStringArray fileNamesList = this.getPlayersList();
        
        for ( int i = 0; i < fileNamesList.Count(); ++i ) {
            string fileName = fileNamesList.Get(i);

            Print(TOP_PREFIX + "Было найдено : " + fileName);

            if (!FileExist(S_ROOTFOLDER + fileName + ".json")) {
                continue;
            } else {

                PlayerStatisticInfo _plData = new PlayerStatisticInfo();
                JsonFileLoader<ref PlayerStatisticInfo>.JsonLoadFile(S_ROOTFOLDER + fileName + ".json", _plData);

                _players.Insert(_plData);
            }   
        }
    }

    void getBestTenPlayers () {
    	// сортируем и берем 10 лучших игроков 
    }

    void resetPlayersStatistic () {
    	// сбрасываем статистику
        TStringArray fileNamesList = this.getPlayersList();
        
        for ( int i = 0; i < fileNamesList.Count(); ++i ) {
            string fileName = fileNamesList.Get(i);

            if (!FileExist(S_ROOTFOLDER + fileName + ".json")) {
                continue;
            } else {    
                //а лучше вообще файл удалять, но там вроде такой хуйни нельзя провернуть...

                PlayerStatisticInfo _plData = new JsonSaveFile();

                JsonFileLoader<ref PlayerStatisticInfo>.JsonLoadFile(S_ROOTFOLDER + steamId + ".json", _plData);

                _plData.kills = 0;
                _plData.deadth = 0;
                _plData.maxRangeKill = 0;

                JsonFileLoader<ref PlayerStatisticInfo>.JsonLoadFile(S_ROOTFOLDER + fileName + ".json", _plData);
            }   
        }
    }

    void startRound (string msg) {
    	// SendMessageToAll(msg);
    	closePlayerEndedGUI();
   		killAllPlayers();
    }




    void showPlayerEndedGUI () {
    	// отображаем игроку статистику топа и рисуем варианты выбора карты
    	ref array<Man> players = new array<Man>;
    	GetGame().GetPlayers( players );
    	foreach( auto player : players  )
        {
            if (player.GetIdentity()) {
				auto param4 = new Param1<string>("PIDOR");
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