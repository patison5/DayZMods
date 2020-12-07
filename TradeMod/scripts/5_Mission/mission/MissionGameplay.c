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
    // private ref HHDeadMatchClientPlugin

    override void OnUpdate(float timeslice) {
        super.OnUpdate(timeslice);

        
        
        Input input = GetGame().GetInput();
        if (input.LocalPress("UAUIBack", false)) 
        {
            if (myHudTop != NULL && GetGame().GetUIManager().GetMenu() == myHudTop) {
                myHudTop.SetMenuOpen(false);
                GetGame().GetUIManager().HideScriptedMenu(myHudTop);
            }
        }

        if ( input.LocalPress("UAOpenCustomMenu", false) ) 
        {
            if ( myHudTop ) {
                if (myHudTop.IsMenuOpen()) {
                    //Hide Menu
                    myHudTop.SetMenuOpen(false);
                    GetGame().GetUIManager().HideScriptedMenu(myHudTop);
                } else if (GetGame().GetUIManager().GetMenu() == NULL) {
                    //Show Menu
                    GetGame().GetUIManager().ShowScriptedMenu(myHudTop, NULL);
                    myHudTop.SetMenuOpen(true);
                }
            } else if (GetGame().GetUIManager().GetMenu() == NULL && myHudTop == null) {
                //Create Menu
                myHudTop = UIHudTop.Cast(GetUIManager().EnterScriptedMenu(UI_TOP_LAYOUT, null));
                myHudTop.SetMenuOpen(true);
            }
        }
    }
};