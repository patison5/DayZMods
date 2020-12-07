class HHDeadMatchClientPlugin extends ScriptedWidgetEventHandler
{
	Widget								layoutRoot;
	TextWidget               			mainTitle, subTitle, timerWidget, tableTitle;
	
	ref WrapSpacerWidget 				parent;
	ref array<Widget>					m_SectionEntries = new array<Widget>;

	bool _isOpen = false;

	void HHDeadMatchClientPlugin () {
		layoutRoot = GetGame().GetWorkspace().CreateWidgets( "MyMods/TradeMod/GUI/Layouts/roundEndScreen.layout", null ); //Create custom widget / .layout

		mainTitle	   = TextWidget.Cast( layoutRoot.FindAnyWidget(  "title"  ) );
       	subTitle	   = TextWidget.Cast( layoutRoot.FindAnyWidget(  "title2" ) );
       	timerWidget	   = TextWidget.Cast( layoutRoot.FindAnyWidget(  "timer"  ) );
       	tableTitle	   = TextWidget.Cast( layoutRoot.FindAnyWidget(  "pname"  ) );

       	parent = WrapSpacerWidget.Cast( layoutRoot.FindAnyWidget("TopContainer") );

       	if (!parent) { 
       		Print(TOP_PREFIX+" родителя нет и я хуй знает почему...");
       		return;
       	} else {
       		Print(TOP_PREFIX + "РОДИТЕЛЬ ЕСТЬ, ПЫТАЕМСЯ ДОБАВИТЬ В НЕГО ЭЛЕМЕНТЫ")
       	}

       	Widget element = GetGame().GetWorkspace().CreateWidgets("MyMods/TradeMod/GUI/Layouts/roundEndListItem.layout", parent);

       	if (!element) {
       		Print(TOP_PREFIX + " element нет и я хуй знает почему...");
       		return;
       	}

       	TextWidget num	   	   = TextWidget.Cast( element.FindAnyWidget( "num" ) );
       	TextWidget pname	   = TextWidget.Cast( element.FindAnyWidget( "pname" ) );
       	TextWidget kills	   = TextWidget.Cast( element.FindAnyWidget( "kills" ) );
       	TextWidget deaths	   = TextWidget.Cast( element.FindAnyWidget( "deaths" ) );
       	TextWidget distance	   = TextWidget.Cast( element.FindAnyWidget( "distance" ) );

       	num.SetText("1");
		pname.SetText("[(V)] Russki Camper");
		kills.SetText("123");
		deaths.SetText("32");
		distance.SetText("934m");


		if (!num || !pname || !kills || !deaths || !distance) {
			Print(TOP_PREFIX + " мелких элементов нихуя нет и я хуй знает почему...");
       		return;
		}

		element.Update();
		parent.Update();
		layoutRoot.Update();


		parent.Show(true);
		element.Show(true);
		num.Show(true);
		pname.Show(true);
		kills.Show(true);
		deaths.Show(true);
		distance.Show(true);

      	this.setDefaults();

      	// layoutRoot.Show(false);

  //     	if (GetGame().IsServer() && GetGame().IsMultiplayer()) return;
		// GetDayZGame().Event_OnRPC.Insert(ClientRPCHandler);

		Print("Инициализация прошла успешно блять");

		if (GetGame().IsServer() && GetGame().IsMultiplayer()) return;
		GetDayZGame().Event_OnRPC.Insert(ClientRPCHandler);
	}

	void ~HHDeadMatchClientPlugin () {

	}

	void setDefaults() {
		mainTitle.SetText("Матч завершен");
		subTitle.SetText("Следующий раунд");
        timerWidget.SetText("15");
        tableTitle.SetText("Ник игрока");

        createTopElements();
	}

	void hideMainScreen () {
		// GetGame().GetUIManager().HideScriptedMenu(myHudTop);
 	// 	myHudTop = UIHudTop.Cast(GetUIManager().EnterScriptedMenu(UI_TOP_LAYOUT, null));

 		layoutRoot.Show(false);
 		UnlockControls();
	}

	void showMainScreen () {
		layoutRoot.Show(true);
		LockControls();
	}

	private void createTopElements() {
		for (int i = 0; i < 8; i++) {

			Widget element = GetGame().GetWorkspace().CreateWidgets("MyMods/TradeMod/GUI/Layouts/roundEndListItem.layout", parent);

	       	TextWidget num	   	   = TextWidget.Cast( element.FindAnyWidget( "num" ) );
	       	TextWidget pname	   = TextWidget.Cast( element.FindAnyWidget( "pname" ) );
	       	TextWidget kills	   = TextWidget.Cast( element.FindAnyWidget( "kills" ) );
	       	TextWidget deaths	   = TextWidget.Cast( element.FindAnyWidget( "deaths" ) );
	       	TextWidget distance	   = TextWidget.Cast( element.FindAnyWidget( "distance" ) );

	       	num.SetText(i.ToString());
			pname.SetText("[(V)] Russki Camper");
			kills.SetText("123");
			deaths.SetText("32");
			distance.SetText("934m");

			Print("createTopElements закончила работу : " + i.ToString());
		}
	}


	private void LockControls()
    {
        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
        GetGame().GetUIManager().ShowUICursor( true );
        GetGame().GetInput().ChangeGameFocus(1);
        // GetGame().GetMission().GetHud().Show( false );
    }

    private void UnlockControls()
    {
        GetGame().GetMission().PlayerControlEnable(false);
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetUIManager().ShowUICursor( false );
    }



	void ClientRPCHandler(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {

		if (GetGame().IsServer() && GetGame().IsMultiplayer()) {
			delete this;
			return;
		}

		switch (rpc_type) {
			case HHRPCEnum.RPC_CLIENT_SHOW_END_SCREEN: { 
				showMainScreen();

				Param1<string> args;
				if (!ctx.Read(args)) return;
				break;
			}

			case HHRPCEnum.RPC_CLIENT_HIDE_END_SCREEN: { 
				hideMainScreen();

				Param1<string> args2;
				if (!ctx.Read(args2)) return;
				break;
			}

			case HHRPCEnum.RPC_CLIENT_UPDATE_MAIN_SCREEN_TIMER: { 
				showMainScreen();

				Param1<string> args3;
				if (!ctx.Read(args3)) return;

				timerWidget.SetText(args3.param1);
				break;
			}
		}
	}

}