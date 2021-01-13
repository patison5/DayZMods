class PluginTopNotification extends PluginBase
{
	Widget								wraper;
	TextWidget               			playerKills, playerDeath, killstrike;

	void PluginTopNotification()
	{	
        if (GetGame().IsServer() && GetGame().IsMultiplayer()) return;

		wraper = GetGame().GetWorkspace().CreateWidgets( "MyMods/TradeMod/GUI/Layouts/hud.layout" ); //Create custom widget / .layout

       	playerKills	   = TextWidget.Cast( wraper.FindAnyWidget( "kills_value" ) );
       	playerDeath	   = TextWidget.Cast( wraper.FindAnyWidget( "deaths_value" ) );
       	killstrike     = TextWidget.Cast( wraper.FindAnyWidget( "distance_value" ) );

      	this.setDefaults();

		GetDayZGame().Event_OnRPC.Insert(ClientRPCHandler);
	}

	void ~PluginTopNotification () {
		GetDayZGame().Event_OnRPC.Remove(ClientRPCHandler);
		wraper.Show(false);
	}

	void setDefaults() {
		playerKills.SetText("0");
        playerDeath.SetText("0");
        killstrike.SetText("0");
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

				playerKills.SetText(args.param2);
		        playerDeath.SetText(args.param3);
		        killstrike.SetText(args.param4);

				break;
			}
		}
	}


}