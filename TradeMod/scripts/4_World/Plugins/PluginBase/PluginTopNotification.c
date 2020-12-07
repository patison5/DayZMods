class PluginTopNotification extends PluginBase
{
	Widget								layoutRoot;
	TextWidget               			NickName, playerKills, playerDeath, rangeDistance;

	void PluginTopNotification()
	{			
		layoutRoot = GetGame().GetWorkspace().CreateWidgets( "MyMods/TradeMod/GUI/Layouts/hud.layout" ); //Create custom widget / .layout

		// NickName	   = TextWidget.Cast( layoutRoot.FindAnyWidget( "NickName" ) );
       	playerKills	   = TextWidget.Cast( layoutRoot.FindAnyWidget( "kills_value" ) );
       	playerDeath	   = TextWidget.Cast( layoutRoot.FindAnyWidget( "deaths_value" ) );
       	rangeDistance  = TextWidget.Cast( layoutRoot.FindAnyWidget( "distance_value" ) );

      	this.setDefaults();

        if (GetGame().IsServer() && GetGame().IsMultiplayer()) return;
		GetDayZGame().Event_OnRPC.Insert(ClientRPCHandler);
	}

	void ~PluginTopNotification () {
		GetDayZGame().Event_OnRPC.Remove(ClientRPCHandler);
	}


	void setDefaults() {
		// NickName.SetText("");
		playerKills.SetText("0");
        playerDeath.SetText("0");
        rangeDistance.SetText("0");
	}


	void ClientRPCHandler(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {

		if (GetGame().IsServer() && GetGame().IsMultiplayer()) {
			delete this;
			return;
		}

		switch (rpc_type) {
			case HHRPCEnum.RPC_CLIENT_UPDATE_TOP: { 
				Param4<string, string, string, string> args;

				if (!ctx.Read(args)) return;

				// NickName.SetText(args.param1);
				playerKills.SetText(args.param2);
		        playerDeath.SetText(args.param3);
		        rangeDistance.SetText(args.param4 + "m");

				break;
			}

		}
	}


}