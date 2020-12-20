#define _ARMA_

class CfgPatches
{
	class CheatersOff
	{
		requiredAddons[] = {};
	};
};
class CfgMods
{
	class CheatersOff
	{
		type = "mod";
		dir="CheatersOff";
		
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"MyMods/CheatersOff/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"MyMods/CheatersOff/scripts/4_World"};
			};
			// class missionScriptModule
			// {
			// 	value = "";
			// 	files[] = {"MyMods/CheatersOff/scripts/5_Mission"};
			// };
		};
	};
};
