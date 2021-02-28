#define _ARMA_

class CfgPatches
{
	class TradeMod
	{
		author = "Lulex.py";
		name = "HHDeadMatch";
		url = "";
		units[] = {};
		weapons[] = {};
		requiredAddons[] = {"DZ_Data","DZ_Sounds_Effects"};
		requiredVersion = 0.1;
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



class CfgSoundShaders
{
	class steamMessage_SoundShader
	{
		samples[] = {{"\MyMods\TradeMod\sounds\steamMessage",1}};

		
		volume = 1;
	};
	
};
class CfgSoundSets
{
	class steamMessage_SoundSet
	{
		soundShaders[] = {"steamMessage_SoundShader"};
		volumeFactor = 1;
		frequencyFactor = 1;
		spatial = 1;
	};
	
};

class CfgSounds
{
    sounds[]    =    {};
        
    class Dominating
    {
        name        =    "Dominating";
        sound[]        =    {"MyMods\TradeMod\sounds\Dominating.ogg", 20, 1, 3};
        titles[]    =    {};
    };
};

