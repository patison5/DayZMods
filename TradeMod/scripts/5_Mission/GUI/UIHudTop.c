class UIHudTop extends UIScriptedMenu
{	
    Widget                              notification;
    TextWidget                          mainTitle, subTitle, timerWidget, tableTitle, notifMessage, zeleno, vybor, szAero;

    ButtonWidget                        btnMap1, btnMap2, btnMap3, selectedBtn;

    RichTextWidget                      mapTitle1, mapTitle2, mapTitle3;
    
    ref WrapSpacerWidget                parent;
    ref array<Widget>                   m_SectionEntries = new array<Widget>;

    private ref Timer                   adminNotficationTimer;

    const string SOUND_NOTIFICATION = "steamMessage_SoundSet";

    private bool m_Initialized;
    private bool m_IsMenuOpen;



    override Widget Init() {

        if (!m_Initialized) //Only draw and init widgets if not already done that, since this function is called each time you do ( ShowScriptedMenu() )
        {

            Print("UIHudTop " + "начинаем инициализацию");

            layoutRoot = GetGame().GetWorkspace().CreateWidgets( "MyMods/TradeMod/GUI/Layouts/roundEndScreen.layout", null ); //Create custom widget / .layout

            mainTitle      = TextWidget.Cast( layoutRoot.FindAnyWidget(  "title"  ) );
            subTitle       = TextWidget.Cast( layoutRoot.FindAnyWidget(  "title2" ) );
            timerWidget    = TextWidget.Cast( layoutRoot.FindAnyWidget(  "timer"  ) );
            tableTitle     = TextWidget.Cast( layoutRoot.FindAnyWidget(  "pname"  ) );

            mapTitle1     = TextWidget.Cast( layoutRoot.FindAnyWidget(  "map4title"  ) );
            mapTitle2     = TextWidget.Cast( layoutRoot.FindAnyWidget(  "map2title"  ) );
            mapTitle3     = TextWidget.Cast( layoutRoot.FindAnyWidget(  "map1title"  ) );

            zeleno  =  TextWidget.Cast( layoutRoot.FindAnyWidget(  "map1Count"  ) );
            vybor   =  TextWidget.Cast( layoutRoot.FindAnyWidget(  "map2Count"  ) );
            szAero  =  TextWidget.Cast( layoutRoot.FindAnyWidget(  "map3Count"  ) );

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

        mapTitle1.SetText("Северо-западный аэропорт");
        mapTitle2.SetText("Выбор");
        mapTitle3.SetText("Зелено");

        zeleno.SetText("0");
        vybor.SetText("0");
        szAero.SetText("0");

        createTopElements();
    }

    void hideMainScreen () {
        layoutRoot.Show(false);
        UnlockControlsModded();
    }

    void showMainScreen () {

        layoutRoot.Show(true);
        LockControlsModded();
    }

    private void createTopElements() {
        for (int i = 0; i < 10; i++) {

            Widget element = GetGame().GetWorkspace().CreateWidgets("MyMods/TradeMod/GUI/Layouts/roundEndListItem.layout", parent);

            TextWidget num         = TextWidget.Cast( element.FindAnyWidget( "num" ) );
            TextWidget pname       = TextWidget.Cast( element.FindAnyWidget( "pname" ) );
            TextWidget kills       = TextWidget.Cast( element.FindAnyWidget( "kills" ) );
            TextWidget deaths      = TextWidget.Cast( element.FindAnyWidget( "deaths" ) );
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
                Param3<string, ref array<ref PlayerStatisticInfo>, ref map<string, int>> args3;
                if (!ctx.Read(args3)) return;

                ref map<string, int> voteData = args3.param3

                foreach (string mapName, int votes: args3.param3)
                    Print("[" + mapName + "] : " + votes);

                updateVotesCount(args3.param3);

                timerWidget.SetText(args3.param1);
                updateTopElements(args3.param2);

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
        string steamId = player.GetIdentity().GetName();

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