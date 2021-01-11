/*
    @DOC / Notes:
    The keybind toggle for the menu works with MissionGameplay 
    ( the quickest way to get your input functional, plenty of other methods such as creating 
    your own plugin using PluginManager to manage your entire input system, this goes the same with storing 
    the instance of your menu, MissionGameplay is not the only option )
    The menu inherits UIScriptedMenu just as any other vanilla menu in the game.
    
    This is setup very similar to the way vanilla base game script creates menus. By modding MissionBase.c you are expanding on the available menus, the const UI_CUSTOM_MENU 
    is the unique ID of your newly added menu of class UIHudTop
    This is not the only method in creating UI, however i find this method to be most simple as all EventHandlers are attached and a load of pre-written 
    functions are there for you to use from base class UIScriptedMenu
*/

modded class MissionGameplay 
{
    private ref UIHudTop myHudTop;


    Widget Thirsty;
    Widget Hungry;
    Widget Temperature;

    override void OnInit()
    {
        super.OnInit();

        Thirsty = Widget.Cast(m_HudRootWidget.FindAnyWidget("Thirsty"));
        Thirsty.Show(false);

        Hungry = Widget.Cast(m_HudRootWidget.FindAnyWidget("Hungry"));
        Hungry.Show(false);

        Temperature = Widget.Cast(m_HudRootWidget.FindAnyWidget("Temperature"));
        Temperature.Show(false);
    }

    override void OnMissionStart()
    {
        Print("OnMissionStart был вызван!");

        super.OnMissionStart();

        if (!myHudTop)
            myHudTop = UIHudTop.Cast(GetUIManager().EnterScriptedMenu(UI_TOP_LAYOUT, null));

        myHudTop.hideMainScreen();
        GetGame().GetUIManager().HideScriptedMenu(myHudTop);
    }
    
    override void OnMissionFinish()
    {
       
        myHudTop.Close();
        myHudTop = NULL;

        super.OnMissionFinish();
    }

    override void OnUpdate(float timeslice) {

        // Man player = GetGame().GetPlayer();

        // if (player && player.IsAlive()) {
        //     if (GetGame().GetUIManager().GetMenu() == NULL && myHudTop == null) {
        //         myHudTop = UIHudTop.Cast(GetUIManager().EnterScriptedMenu(UI_TOP_LAYOUT, null));

        //         Print("Инициализируем худтоп ебана рот");

        //         if (!myHudTop.IsMenuOpen()) {
        //             Print("Прячем эту ебалу");
        //             myHudTop.SetMenuOpen(false);
        //             myHudTop.hideMainScreen();
        //             GetGame().GetUIManager().HideScriptedMenu(myHudTop);
        //         }
        //     }
        // } else {
        //     Print("Player пока что мерв, не можем проинициализировать...");
        // }

        super.OnUpdate(timeslice);


        // if ( myHudTop ) {
        //     if (myHudTop.IsMenuOpen()) {
               
        //     } else if (GetGame().GetUIManager().GetMenu() == NULL) {
        //         //Show Menu
        //         GetGame().GetUIManager().ShowScriptedMenu(myHudTop, NULL);
        //         // myHudTop.SetMenuOpen(true);
        //     }
        // } else if (GetGame().GetUIManager().GetMenu() == NULL && myHudTop == null) {
        //     //Create Menu
        //     myHudTop = UIHudTop.Cast(GetUIManager().EnterScriptedMenu(UI_TOP_LAYOUT, null));
        //     // myHudTop.SetMenuOpen(true);
        // }





        
        // Input input = GetGame().GetInput();/
        // if (input.LocalPress("UAUIBack", false)) 
        // {
        //     if (myHudTop != NULL && GetGame().GetUIManager().GetMenu() == myHudTop) {
        //         myHudTop.SetMenuOpen(false);
        //         GetGame().GetUIManager().HideScriptedMenu(myHudTop);
        //     }
        // }

        // if ( input.LocalPress("UAOpenCustomMenu", false) ) 
        // {
        //     if ( myHudTop ) {
        //         if (myHudTop.IsMenuOpen()) {
        //             //Hide Menu
        //             myHudTop.SetMenuOpen(false);
        //             GetGame().GetUIManager().HideScriptedMenu(myHudTop);
        //         } else if (GetGame().GetUIManager().GetMenu() == NULL) {
        //             //Show Menu
        //             GetGame().GetUIManager().ShowScriptedMenu(myHudTop, NULL);
        //             myHudTop.SetMenuOpen(true);
        //         }
        //     } else if (GetGame().GetUIManager().GetMenu() == NULL && myHudTop == null) {
        //         //Create Menu
        //         myHudTop = UIHudTop.Cast(GetUIManager().EnterScriptedMenu(UI_TOP_LAYOUT, null));
        //         myHudTop.SetMenuOpen(true);
        //     }
        // }


    }

    override void OnKeyPress(int key) {
        super.OnKeyPress(key);
        
        if (key == KeyCode.KC_ESCAPE) {

            myHudTop.SetMenuOpen(false);

            // if (GetUIManager().FindMenu(UI_TOP_LAYOUT)) {
            //     GetUIManager().CloseMenu(UI_TOP_LAYOUT);
            // }
           
            // if (myHudTop) {
            //     myHudTop.Close();
            //     myHudTop = NULL;            
            // }           
        }
    }
};