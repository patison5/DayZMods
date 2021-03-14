class UIHudTop extends UIScriptedMenu
{	
    Widget                              notification;
    TextWidget                          mainTitle, subTitle, timerWidget, tableTitle, notifMessage, zeleno, vybor, szAero;

    TextWidget                          LeftTitleTextWidget;
    TextWidget                          CenterHeaderTitle;
    TextWidget                          SelectMapTitle;
    TextWidget                          privateKillsTitle;
    TextWidget                          privateDeathTitle;
    TextWidget                          privateKDTitle;
    TextWidget                          privateLongestKillTitle;
    TextWidget                          privateKillstrikeTitle;
    TextWidget                          PrivatStatisticTitle;
    TextWidget                          privateMatchFinishedTitle;
    TextWidget                          privateMatchesWonTitle;
    TextWidget                          privateBestVesaponTitle;
    TextWidget                          privateKillsValue;
    TextWidget                          privateDeathValue;
    TextWidget                          privateKDValue;
    TextWidget                          privateLongestKillValue;
    TextWidget                          privateKillstrikeValue;
    TextWidget                          privateMatchFinishedValue;
    TextWidget                          privateMatchesWonValue;
    TextWidget                          privateBestVesaponValue;

    TextWidget                          headPercentValue;
    TextWidget                          leftArmPercentValue;
    TextWidget                          RightArmPercentValue;
    TextWidget                          torsoPercentValue;
    TextWidget                          leftHandPercentValue;
    TextWidget                          rightHandPercentValue;
    TextWidget                          leftLegPercentValue;
    TextWidget                          rightLegPercentValue;
    TextWidget                          leftFootPercentValue;
    TextWidget                          rightFootPercentValue;

    ButtonWidget                        btnMap1, btnMap2, btnMap3, selectedBtn;

    TextWidget                          mapTitle1, mapTitle2, mapTitle3;
    
    ref WrapSpacerWidget                parent;
    ref array<Widget>                   m_SectionEntries = new array<Widget>;

    private ref Timer                   adminNotficationTimer;

    const string SOUND_NOTIFICATION = "steamMessage_SoundSet";

    private bool m_Initialized;
    private bool m_IsMenuOpen;

    override Widget Init() {

        if (!m_Initialized)
        {
            Print("UIHudTop " + "начинаем инициализацию");

            layoutRoot = GetGame().GetWorkspace().CreateWidgets( "MyMods/TradeMod/GUI/Layouts/HHDeadMatchEndScreen.layout", null );

            mainTitle      = TextWidget.Cast( layoutRoot.FindAnyWidget(  "MainTitleTextWidget"  ) );
            subTitle       = TextWidget.Cast( layoutRoot.FindAnyWidget(  "NextRoundAfter" ) );
            timerWidget    = TextWidget.Cast( layoutRoot.FindAnyWidget(  "EndRoundTimer"  ) );
            tableTitle     = TextWidget.Cast( layoutRoot.FindAnyWidget(  "headerNickname"  ) );

            mapTitle1     = TextWidget.Cast( layoutRoot.FindAnyWidget(  "map1Title"  ) );
            mapTitle2     = TextWidget.Cast( layoutRoot.FindAnyWidget(  "map2Title"  ) );
            mapTitle3     = TextWidget.Cast( layoutRoot.FindAnyWidget(  "map3Title"  ) );

            zeleno  =  TextWidget.Cast( layoutRoot.FindAnyWidget(  "map1Count"  ) );
            vybor   =  TextWidget.Cast( layoutRoot.FindAnyWidget(  "map2Count"  ) );
            szAero  =  TextWidget.Cast( layoutRoot.FindAnyWidget(  "map3Count"  ) );

            LeftTitleTextWidget       =  TextWidget.Cast( layoutRoot.FindAnyWidget(  "LeftTitleTextWidget"  ) );      
            CenterHeaderTitle         =  TextWidget.Cast( layoutRoot.FindAnyWidget(  "CenterHeaderTitle"  ) );      
            SelectMapTitle            =  TextWidget.Cast( layoutRoot.FindAnyWidget(  "SelectMapTitle"  ) );  

            privateKillsTitle         =  TextWidget.Cast( layoutRoot.FindAnyWidget(  "privateKillsTitle"  ) );      
            privateDeathTitle         =  TextWidget.Cast( layoutRoot.FindAnyWidget(  "privateDeathTitle"  ) );      
            privateKDTitle            =  TextWidget.Cast( layoutRoot.FindAnyWidget(  "privateKDTitle"  ) );  
            privateLongestKillTitle   =  TextWidget.Cast( layoutRoot.FindAnyWidget(  "privateLongestKillTitle"  ) );          
            privateKillstrikeTitle    =  TextWidget.Cast( layoutRoot.FindAnyWidget(  "privateKillstrikeTitle"  ) );   

            PrivatStatisticTitle      =  TextWidget.Cast( layoutRoot.FindAnyWidget(  "PrivatStatisticTitle"  ) );          
            privateMatchFinishedTitle =  TextWidget.Cast( layoutRoot.FindAnyWidget(  "privateMatchFinishedTitle"  ) );              
            privateMatchesWonTitle    =  TextWidget.Cast( layoutRoot.FindAnyWidget(  "privateMatchesWonTitle"  ) );          
            privateBestVesaponTitle   =  TextWidget.Cast( layoutRoot.FindAnyWidget(  "privateBestVesaponTitle"  ) );    

            privateKillsValue       = TextWidget.Cast( layoutRoot.FindAnyWidget(  "privateKillsValue"  ) );          
            privateDeathValue       = TextWidget.Cast( layoutRoot.FindAnyWidget(  "privateDeathValue"  ) );          
            privateKDValue          = TextWidget.Cast( layoutRoot.FindAnyWidget(  "privateKDValue"  ) );      
            privateLongestKillValue = TextWidget.Cast( layoutRoot.FindAnyWidget(  "privateLongestKillValue"  ) );              
            privateKillstrikeValue  = TextWidget.Cast( layoutRoot.FindAnyWidget(  "privateKillstrikeValue"  ) );    

            privateMatchFinishedValue = TextWidget.Cast( layoutRoot.FindAnyWidget(  "privateMatchFinishedValue"  ) );    
            privateMatchesWonValue    = TextWidget.Cast( layoutRoot.FindAnyWidget(  "privateMatchesWonValue"  ) );
            privateBestVesaponValue   = TextWidget.Cast( layoutRoot.FindAnyWidget(  "privateBestVesaponValue"  ) ); 

            headPercentValue        = TextWidget.Cast( layoutRoot.FindAnyWidget(  "headPercentValue"  ) );            
            leftArmPercentValue     = TextWidget.Cast( layoutRoot.FindAnyWidget(  "leftArmPercentValue"  ) );                
            RightArmPercentValue    = TextWidget.Cast( layoutRoot.FindAnyWidget(  "RightArmPercentValue"  ) );                
            torsoPercentValue       = TextWidget.Cast( layoutRoot.FindAnyWidget(  "torsoPercentValue"  ) );            
            leftHandPercentValue    = TextWidget.Cast( layoutRoot.FindAnyWidget(  "leftHandPercentValue"  ) );                
            rightHandPercentValue   = TextWidget.Cast( layoutRoot.FindAnyWidget(  "rightHandPercentValue"  ) );                
            leftLegPercentValue     = TextWidget.Cast( layoutRoot.FindAnyWidget(  "leftLegPercentValue"  ) );                
            rightLegPercentValue    = TextWidget.Cast( layoutRoot.FindAnyWidget(  "rightLegPercentValue"  ) );                
            leftFootPercentValue    = TextWidget.Cast( layoutRoot.FindAnyWidget(  "leftFootPercentValue"  ) );                
            rightFootPercentValue   = TextWidget.Cast( layoutRoot.FindAnyWidget(  "rightFootPercentValue"  ) );                                    

            parent = WrapSpacerWidget.Cast( layoutRoot.FindAnyWidget("TopContainer") );

            this.setDefaults();
            
            layoutRoot.Update();
            layoutRoot.Show(false);

            // notification = GetGame().GetWorkspace().CreateWidgets( "MyMods/TradeMod/GUI/Layouts/SindicatMessage.layout", null );
            // notifMessage = TextWidget.Cast( notification.FindAnyWidget(  "message"  ) );
            // notifMessage.SetText("НУ ЭТО БАН!");
            // notification.Show(false);


            btnMap1 = ButtonWidget.Cast( layoutRoot.FindAnyWidget(  "btnMap1"  ) );
            btnMap2 = ButtonWidget.Cast( layoutRoot.FindAnyWidget(  "btnMap2"  ) );
            btnMap3 = ButtonWidget.Cast( layoutRoot.FindAnyWidget(  "btnMap3"  ) );

            // if (GetGame().IsServer() && GetGame().IsMultiplayer()) return;
            GetDayZGame().Event_OnRPC.Insert(ClientRPCHandler);

            m_Initialized = true;
        }

        return layoutRoot;
    }

    void UIHudTop() {}

    void ~UIHudTop() 
    {
        hideMainScreen();

        // PPEffects.SetBlurMenu( 1 );

        //Destroy root widget and all its children
        if ( layoutRoot )
            layoutRoot.Unlink();
    }



    void setDefaults() {
        mainTitle.SetText("Матч завершен");
        subTitle.SetText("Следующий раунд");
        timerWidget.SetText("15");
        tableTitle.SetText("Ник игрока");

        // mapTitle1.SetText("Северо-западный <br/>аэропорт");
        mapTitle1.SetText("Зелено");
        mapTitle2.SetText("Выбор");
        mapTitle3.SetText("Красностав");

        zeleno.SetText("0");
        vybor.SetText("0");
        szAero.SetText("0");

        LeftTitleTextWidget.SetText( "Статистика игроков" );
        CenterHeaderTitle.SetText( "Личная статистика матча" );
        SelectMapTitle.SetText( "Выбор карты" );

        privateKillsTitle.SetText( "Убийства" );
        privateDeathTitle.SetText( "Смерти" );
        privateKDTitle.SetText( "Убийства/Смерти" );
        privateLongestKillTitle.SetText( "Самый дальний выстрел" );
        privateKillstrikeTitle.SetText( "Серия убийств" );

        PrivatStatisticTitle.SetText( "Личная статистика" );
        privateMatchFinishedTitle.SetText( "Матчей сыграно" );
        privateMatchesWonTitle.SetText( "Занятых топ1" );
        privateBestVesaponTitle.SetText( "Лучшее оружие" );

        headPercentValue.SetText( "0" );
        leftArmPercentValue.SetText( "0" );
        RightArmPercentValue.SetText( "0" );
        torsoPercentValue.SetText( "0" );
        leftHandPercentValue.SetText( "0" );
        rightHandPercentValue.SetText( "0" );
        leftLegPercentValue.SetText( "0" );
        rightLegPercentValue.SetText( "0" );
        leftFootPercentValue.SetText( "0" );
        rightFootPercentValue.SetText( "0" );

        createTopElements();
    }

    void hideMainScreen () {
        GetGame().GetMission().GetHud().Show( true );
        layoutRoot.Show(false);
        PPEffects.SetBlurMenu( 0 );
        UnlockControlsModded();
        
        selectedBtn = NULL;
    }

    void showMainScreen () {
        GetGame().GetMission().GetHud().Show( false );
        layoutRoot.Show(true);
        PPEffects.SetBlurMenu( 1 );
        LockControlsModded();
    }

    private void createTopElements() {
        for (int i = 0; i < 10; i++) {

            Widget element = GetGame().GetWorkspace().CreateWidgets("MyMods/TradeMod/GUI/Layouts/HHDeadMatchEndScreenElement.layout", parent);

            TextWidget num         = TextWidget.Cast( element.FindAnyWidget( "num" ) );
            TextWidget pname       = TextWidget.Cast( element.FindAnyWidget( "pname" ) );
            TextWidget kills       = TextWidget.Cast( element.FindAnyWidget( "kills" ) );
            TextWidget deaths      = TextWidget.Cast( element.FindAnyWidget( "death" ) );
            TextWidget distance    = TextWidget.Cast( element.FindAnyWidget( "distance" ) );

            element.SetName("element_" + i);
            num.SetName("num_" + i);
            pname.SetName("pname_" + i);
            kills.SetName("kills_" + i);
            deaths.SetName("deaths_" + i);
            distance.SetName("distance_" + i);

            num.SetText((i + 1).ToString());
            pname.SetText("");
            kills.SetText("");
            deaths.SetText("");
            distance.SetText("");

            Print("Упало на " + i.ToString());
        }
    }


    private void updateTopElements(ref array<ref PlayerStatisticInfo> _players) {
        for (int i = 0; i < 10; i++) {

            if (!_players) { Print("2. NO FUCKING PLAYERS"); return; }


            Widget element = Widget.Cast( layoutRoot.FindAnyWidget( "element_" + i) );

            TextWidget num         = TextWidget.Cast( element.FindAnyWidget( "num_" + i) );
            TextWidget pname       = TextWidget.Cast( element.FindAnyWidget( "pname_" + i) );
            TextWidget kills       = TextWidget.Cast( element.FindAnyWidget( "kills_" + i) );
            TextWidget deaths      = TextWidget.Cast( element.FindAnyWidget( "deaths_" + i) );
            TextWidget distance    = TextWidget.Cast( element.FindAnyWidget( "distance_" + i) );

            num.SetText((i + 1).ToString());

            if (i < _players.Count()) {
                pname.SetText(_players.Get(i).playerName);
                kills.SetText(_players.Get(i).kills.ToString());
                deaths.SetText(_players.Get(i).deadth.ToString());
                distance.SetText(_players.Get(i).maxRangeKill.ToString() + "m");
            } else {
                pname.SetText("");
                kills.SetText("");
                deaths.SetText("");
                distance.SetText("");
            }

            element.Show(true);
        }
    }


    private void LockControlsModded()
    {
        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
        GetGame().GetUIManager().ShowUICursor( true );
        GetGame().GetInput().ChangeGameFocus(1);
        // GetGame().GetMission().GetHud().Show( false );
    }

    private void UnlockControlsModded()
    {
        if (GetGame().GetMission())
            GetGame().GetMission().PlayerControlEnable(false);
        
        if (GetGame().GetInput())
            GetGame().GetInput().ResetGameFocus();

        if (GetGame().GetInput())
            GetGame().GetUIManager().ShowUICursor( false );
    }

    private void closeAdminMessage () {
        // notification.Show(false);
    }

    void updateVotesCount(ref map<string, int> voteData) {
        zeleno.SetText("0");
        vybor.SetText("0");
        szAero.SetText("0");
        
        if (zeleno && voteData["Zeleno"])
            zeleno.SetText(voteData["Zeleno"].ToString());
        
        if (vybor && voteData["vybor"])
            vybor.SetText(voteData["vybor"].ToString());
        
        if (szAero && voteData["csAero"])
            szAero.SetText(voteData["csAero"].ToString());
    }

    ref PlayerStatisticInfo findCurrentPlayerStatistic (ref array<ref PlayerStatisticInfo> _players, string steamId) {
        foreach (ref PlayerStatisticInfo pl : _players) {
            if (pl.steamID64 == steamId) return pl;
        }
        return NULL;
    }

    void updatePrivateMatchStatistic (ref array<ref PlayerStatisticInfo> _players) {

        ref PlayerStatisticInfo plStat = findCurrentPlayerStatistic(_players, g_Game.GetSteam64Id());
        float kd = 0;

        if (!plStat) return;

        if (plStat.deadth == 0) {
            kd = plStat.kills
        } else {
            kd = plStat.kills / plStat.deadth;
        }

        Print( plStat.kills.ToString() );
        Print( plStat.deadth.ToString() );
        Print( kd.ToString() );
        Print( plStat.maxRangeKill.ToString() );
        Print( plStat.killstreak.ToString() );

        privateKillsValue.SetText( plStat.kills.ToString() );  
        privateDeathValue.SetText( plStat.deadth.ToString() );
        privateKDValue.SetText( kd.ToString() );
        privateLongestKillValue.SetText( plStat.maxRangeKill.ToString() + "m" );
        privateKillstrikeValue.SetText( plStat.killstreak.ToString() );
    }

    void updatePrivateStatistic (ref PlayerStatisticAllInfo _players) {
        privateMatchFinishedValue.SetText( _players.matchesPlayed.ToString() );
        privateMatchesWonValue.SetText( _players.matchesWon.ToString() );

        ref map<string, ref WeaponStatistic> weaponsData = _players.weaponsData;
        string bestWeapon = "Отсутствует";
        int bestWeaponKills = 0;

        foreach(string k, ref WeaponStatistic weapon: weaponsData)
        {
            if (bestWeaponKills < weapon.kills) {
                bestWeaponKills = weapon.kills;
                bestWeapon = k;
            }
        }

        Print("DEBUGIN епта");
        Print(bestWeapon);
        Print(bestWeaponKills.ToString());

        privateBestVesaponValue.SetText( bestWeapon );
    }

    void updateHumanPercentageData (ref array<ref PlayerStatisticInfo> _players) {
        ref PlayerStatisticInfo plStat = findCurrentPlayerStatistic(_players, g_Game.GetSteam64Id());

        if (!plStat) return;

        int sum = plStat.leftFoot + plStat.rightFoot + plStat.leftLeg + plStat.rightLeg;
        sum = sum + plStat.torso + plStat.head + plStat.leftHand + plStat.rightHand + plStat.leftArm + plStat.rightArm;
        
        if (sum == 0) sum = 1;

        Print("debugin test conut");

        float leftFoot        = plStat.leftFoot * 100 / sum;
        float rightFoot       = plStat.rightFoot * 100 / sum;
        float leftLeg         = plStat.leftLeg * 100 / sum;
        float rightLeg        = plStat.rightLeg * 100 / sum;
        float torso           = plStat.torso * 100 / sum;
        float head            = plStat.head * 100 / sum;
        float leftHand        = plStat.leftHand * 100 / sum;
        float rightHand       = plStat.rightHand * 100 / sum;
        float leftArm         = plStat.leftArm * 100 / sum;
        float rightArm        = plStat.rightArm * 100 / sum;

        Print("SUM IS : " + plStat.torso);
        Print("SUM IS : " + plStat.torso * 100 / sum);
        Print("SUM IS : " + plStat.torso * 100 / sum);
        Print("SUM IS : " + torso.ToString());

        Print("end debugin test conut");

        headPercentValue.SetText(       head.ToString().ToInt().ToString()         + "%"  );
        leftArmPercentValue.SetText(    leftArm.ToString().ToInt().ToString()      + "%"  );
        RightArmPercentValue.SetText(   rightArm.ToString().ToInt().ToString()     + "%"  );
        torsoPercentValue.SetText(      torso.ToString().ToInt().ToString()        + "%"  );
        leftHandPercentValue.SetText(   leftHand.ToString().ToInt().ToString()     + "%"  );
        rightHandPercentValue.SetText(  rightHand.ToString().ToInt().ToString()    + "%"  );
        leftLegPercentValue.SetText(    leftLeg.ToString().ToInt().ToString()      + "%"  );
        rightLegPercentValue.SetText(   rightLeg.ToString().ToInt().ToString()     + "%"  );
        leftFootPercentValue.SetText(   leftFoot.ToString().ToInt().ToString()     + "%"  );
        rightFootPercentValue.SetText(  rightFoot.ToString().ToInt().ToString()    + "%"  );
    }

    void ClientRPCHandler(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());

        if (GetGame().IsServer() && GetGame().IsMultiplayer()) {
            delete this;
            return;
        }

        switch (rpc_type) {
            case HHRPCEnum.RPC_CLIENT_SHOW_END_SCREEN: { 
                Param1<ref array<ref PlayerStatisticInfo>> args;
                if (!ctx.Read(args)) return;

                if (!player)
                    player = PlayerBase.Cast(GetGame().GetPlayer());

                // DeadScreen ShowDeadScreen player.ShowDeadScreen

                player.CloseInventoryMenu();
                updateTopElements(args.param1);
                showMainScreen();

                break;
            }

            case HHRPCEnum.RPC_CLIENT_HIDE_END_SCREEN: { 
                hideMainScreen();

                Param1<string> args2;
                if (!ctx.Read(args2)) return;
                break;
            }

            case HHRPCEnum.RPC_CLIENT_UPDATE_MAIN_SCREEN_TIMER: { 
                Param4<string, ref array<ref PlayerStatisticInfo>, ref map<string, int>,  ref PlayerStatisticAllInfo> args3;
                if (!ctx.Read(args3)) return;

                ref map<string, int> voteData = args3.param3

                foreach (string mapName, int votes: args3.param3)
                    Print("[" + mapName + "] : " + votes);

                updateVotesCount(args3.param3);

                timerWidget.SetText(args3.param1);
                updateTopElements(args3.param2);
                updatePrivateMatchStatistic(args3.param2);
                updatePrivateStatistic(args3.param4);
                updateHumanPercentageData(args3.param2)

                showMainScreen();

                break;
            }

            case HHRPCEnum.RPC_SHOW_ADMIN_FUN_MESSAGE: { 

                if (!player)
                    player = PlayerBase.Cast(GetGame().GetPlayer());

                Param1<string> args4;
                if (!ctx.Read(args4)) return;

                // adminNotficationTimer   = new ref Timer();
                // notification.Show(true);
                // adminNotficationTimer.Run(10, this, "closeAdminMessage", NULL, true);
                // notifMessage.SetText(args4.param1);

                // //Now we can play the proper sound
                // EffectSound effectSound = NULL;

                // effectSound = SEffectManager.CreateSound( SOUND_NOTIFICATION, player.GetPosition() );
        
                // if (effectSound != NULL)
                // {
                //  effectSound.SoundPlay();
                // } else {
                //  Print("NO FUCKING SOUND FOUND!!!!!!!!!!!!!!!!");
                // }

                EffectSound sound = SEffectManager.PlaySound( SOUND_NOTIFICATION, player.GetPosition() );
                // sound.SetParent(player);
                sound.SetSoundAutodestroy( true );

                break;
            }
        }
    }

    //--- EVENTS
    override bool OnClick(Widget w, int x, int y, int button)
    {
        super.OnClick(w, x, y, button);

        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        // string steamId = player.GetIdentity().GetPlainId();
        string steamId = g_Game.GetSteam64Id();

        auto param1 = new Param1<string>(steamId);

        switch (w) {
            case btnMap1:
                if (selectedBtn != btnMap1) {
                    GetGame().RPCSingleParam(player, HHRPCEnum.RPC_SELECT_MAP_1, param1, true, player.GetIdentity());
                    selectedBtn = btnMap1;
                }
                break;

             case btnMap2:
                if (selectedBtn != btnMap2) {
                    GetGame().RPCSingleParam(player, HHRPCEnum.RPC_SELECT_MAP_2, param1, true, player.GetIdentity());
                    selectedBtn = btnMap2;
                }
                break;

             case btnMap3:
                if (selectedBtn != btnMap3) {
                    GetGame().RPCSingleParam(player, HHRPCEnum.RPC_SELECT_MAP_3, param1, true, player.GetIdentity());
                    selectedBtn = btnMap3;
                }
                break;
        }

        return true;
    }



    // PluginTopNotification m_pluginTopNotification;

  

    //after show
    // override void OnShow()
    // {
    //     // super.OnShow();

    //     // PPEffects.SetBlurMenu( 0.5 ); //Add blurr effect
    //     // g_Game.GetUIManager().ShowCursor(true);
    //     // g_Game.GetUIManager().ShowUICursor(false);
    //     // GetGame().GetInput().ResetGameFocus();
    //     // GetGame().GetMission().PlayerControlEnable(false);
    //     // GetGame().GetMission().GetHud().Show( true );
    // }

    // override Widget Init()
    // {
    //     if (!m_Initialized) //Only draw and init widgets if not already done that, since this function is called each time you do ( ShowScriptedMenu() )
    //     {

    //         // m_pluginTopNotification = PluginTopNotification.Cast(GetPlugin(PluginTopNotification));

    //         m_Initialized = true;

    //         m_pluginTopNotification.setDefaults();
    //     }
    //     return layoutRoot;
    // }


    //Called on each frame, this will be paused when the menu is hidden or missiongameplay callqueue is frozen / paused
    // override void Update(float timeslice)
    // {
    //     super.Update(timeslice);
    // }

   
    bool IsMenuOpen() 
    {
        return m_IsMenuOpen;
    }

    void SetMenuOpen(bool isMenuOpen) 
    {
        m_IsMenuOpen = isMenuOpen;
        if (m_IsMenuOpen)
            PPEffects.SetBlurMenu( 0.2 );
        else
            PPEffects.SetBlurMenu( 0 );
    }
};