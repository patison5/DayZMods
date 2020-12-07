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

    void HHDeadMatchPlugin () {

    	Print("HHDeadMatchPlugin был проинициализирован");

    	roundTimer	= new ref Timer();
        roundTimer.Run(roundTime, this, "endRound", NULL, true);
    }


    void endRound () {
    	Print(TOP_PREFIX + "Раунд закончился");

    	if (GetGame().IsServer()) {
	    	delayTimeout = new ref Timer();

    		// SendMessageToAll("Раунд закончился, выберите карту");
    		showPlayerEndedGUI();
    		delayTimeout.Run(timeOut, this, "startRound", new Param1<string>(" новый раунд начался"), false);
    		changeTimer();
	    }
    }


    void summurizePlayersStatistic () {
    	// собираем всю информацию по игрокам
    }

    void getBestTenPlayers () {
    	// сортируем и берем 10 лучших игроков
    }

    void resetPlayersStatistic () {
    	// сбрасываем статистику
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