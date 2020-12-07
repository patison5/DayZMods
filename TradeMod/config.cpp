#define _ARMA_

class CfgPatches
{
	class TradeMod
	{
		requiredAddons[] = {};
	};
};
class CfgMods
{
	class TradeMod
	{
		type = "mod";
		dir="TradeMod";
		inputs="MyMods/TradeMod/data/inputs.xml";
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"MyMods/TradeMod/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"MyMods/TradeMod/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"MyMods/TradeMod/scripts/5_Mission"};
			};
		};
	};
};
