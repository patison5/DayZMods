class UIHudTop extends UIScriptedMenu
{	
    Widget                              notification;
    TextWidget                          mainTitle, subTitle, timerWidget, tableTitle, notifMessage;

    ButtonWidget                        btnMap1, btnMap2, btnMap3;
    
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

    /*
        This is the destructor, called when this class is deleted / destroyed
    */
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

        createTopElements();
    }

    void hideMainScreen () {
        layoutRoot.Show(false);
        UnlockControlsModded();
    }

    void showMainScreen (ref array<ref PlayerStatisticInfo> _players) {
        updateTopElements(_players);
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
            if (_players) Print("2. " + TOP_PREFIX + _players.Count() + "шт");


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



    void ClientRPCHandler(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {

        if (GetGame().IsServer() && GetGame().IsMultiplayer()) {
            delete this;
            return;
        }

        switch (rpc_type) {
            case HHRPCEnum.RPC_CLIENT_SHOW_END_SCREEN: { 
                Param1<ref array<ref PlayerStatisticInfo>> args;
                if (!ctx.Read(args)) return;
                showMainScreen(args.param1);

                break;
            }

            case HHRPCEnum.RPC_CLIENT_HIDE_END_SCREEN: { 
                hideMainScreen();

                Param1<string> args2;
                if (!ctx.Read(args2)) return;
                break;
            }

            case HHRPCEnum.RPC_CLIENT_UPDATE_MAIN_SCREEN_TIMER: { 
                Param1<string> args3;
                if (!ctx.Read(args3)) return;

                timerWidget.SetText(args3.param1);
                break;
            }

            case HHRPCEnum.RPC_SHOW_ADMIN_FUN_MESSAGE: { 

                PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());

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

        Man player = GetGame().GetPlayer();

        switch (w) {
            case btnMap1:
                GetGame().RPCSingleParam(player, HHRPCEnum.RPC_SELECT_MAP_1, NULL, true, player.GetIdentity());
                break;

             case btnMap2:
                GetGame().RPCSingleParam(player, HHRPCEnum.RPC_SELECT_MAP_2, NULL, true, player.GetIdentity());
                break;

             case btnMap3:
                GetGame().RPCSingleParam(player, HHRPCEnum.RPC_SELECT_MAP_3, NULL, true, player.GetIdentity());
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