class UIHudTop extends UIScriptedMenu
{	
    // private Widget               NickName;
    // private Widget               playerKills;
    // private Widget               playerDeath;
    // private Widget  			 rangeDistance;
   	
    PluginTopNotification m_pluginTopNotification;
    // HHDeadMatchClientPlugin m_HHDeadMatchClientPlugin;

   	private bool m_Initialized;
   	private bool m_IsMenuOpen;

    void UIHudTop()
    {
    }

    /*
		This is the destructor, called when this class is deleted / destroyed
    */
    void ~UIHudTop() 
    {
    	PPEffects.SetBlurMenu( 0 );

        //Destroy root widget and all its children
        if ( layoutRoot )
        	layoutRoot.Unlink();
    }

    //after show
    override void OnShow()
    {
        super.OnShow();

        PPEffects.SetBlurMenu( 0.5 ); //Add blurr effect
        g_Game.GetUIManager().ShowCursor(true);
        g_Game.GetUIManager().ShowUICursor(false);
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetMission().PlayerControlEnable(false);
        GetGame().GetMission().GetHud().Show( true );
    }

    override Widget Init()
    {
        if (!m_Initialized) //Only draw and init widgets if not already done that, since this function is called each time you do ( ShowScriptedMenu() )
        {

            m_pluginTopNotification = PluginTopNotification.Cast(GetPlugin(PluginTopNotification));
            // m_HHDeadMatchClientPlugin = HHDeadMatchClientPlugin.Cast(GetPlugin(HHDeadMatchClientPlugin));

            

            // layoutRoot = GetGame().GetWorkspace().CreateWidgets( "MyMods/TradeMod/GUI/Layouts/TopLayout.layout" ); //Create custom widget / .layout

           	// NickName	   = TextWidget.Cast( layoutRoot.FindAnyWidget( "NickName" ) );
           	// playerKills	   = TextWidget.Cast( layoutRoot.FindAnyWidget( "playerKills" ) );
           	// playerDeath	   = TextWidget.Cast( layoutRoot.FindAnyWidget( "playerDeath" ) );
           	// rangeDistance  = TextWidget.Cast( layoutRoot.FindAnyWidget( "rangeDistance" ) );

            m_Initialized = true;

            m_pluginTopNotification.setDefaults();
        }
        return layoutRoot;
    }


    //Called on each frame, this will be paused when the menu is hidden or missiongameplay callqueue is frozen / paused
    override void Update(float timeslice)
    {
        super.Update(timeslice);
    }

   
    bool IsMenuOpen() 
    {
        return m_IsMenuOpen;
    }

    void SetMenuOpen(bool isMenuOpen) 
    {
        m_IsMenuOpen = isMenuOpen;
        if (m_IsMenuOpen)
            PPEffects.SetBlurMenu( 0.5 );
        else
            PPEffects.SetBlurMenu( 0 );
    }



    // void updateKills (int kills) {
    // 	playerKills.SetText(kills.ToString());
    // }
};