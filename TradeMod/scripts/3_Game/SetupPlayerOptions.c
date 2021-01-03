class SetupPlayerOptions 
{
	ref array<ref PlayerSet> PlayerSetups = new array<ref PlayerSet>;
	
	void InitPlayerSetups() {

		PlayerSet set4 = new PlayerSet(
			// одежда
			{"TacticalGloves_Black", "TacticalShirt_Black", "HH_Pants_kneepads_black", "HH_Military_Boots_Black"}, 

			// оружие и обвесы
			"HH_DVL10",
			"HH_Mag_DVL10_10Rnd",
			{"HH_LongRangeOptics_x24_Black"},

			// Шлем и обвесы
			"HH_K63_Helmet_Black", 
			{},

			// Броник и обвесы
			"HH_Vest_IOTV_Black",
			{
				"HH_Vest_IOTV_Grenade_Pounch_Black",
				"HH_Vest_IOTV_Grenade_Pounch_Black",
				"HH_Vest_IOTV_Mag_pounch_Black",
				"HH_Vest_IOTV_Mag_pounch_Black",
				"HH_Vest_IOTV_BackPocketIFAK_Black",
			},

			// Содержимое карманов
			{
				"HH_Mag_DVL10_10Rnd", "HH_Mag_DVL10_10Rnd", "HH_Mag_DVL10_10Rnd", "HH_Mag_DVL10_10Rnd", "HH_Mag_DVL10_10Rnd", "HH_Mag_DVL10_10Rnd",
				"HH_Ammo_338", "HH_Ammo_338", "HH_Ammo_338", "HH_Ammo_338",  "HH_Ammo_338",  "HH_Ammo_338",
				"BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "Vodka",
				"Epinephrine", "Epinephrine", "PainKillerTablets", "PainKillerTablets", "TetracyclineAntibiotics", "TetracyclineAntibiotics", "Morphine", "Morphine", "Splint", "HuntingOptic",
				"Battery9V", "Battery9V",
				"RGD5Grenade", "M67Grenade"
			});


		PlayerSet set5 = new PlayerSet(
			// одежда
			{"TacticalGloves_Black", "TacticalShirt_Black", "HH_Pants_kneepads_black", "HH_Military_Boots_Black"}, 

			// оружие и обвесы
			"HH_PKP",
			"HH_Mag_PKM_250Rnd",
			{"KobraOptic"},

			// Шлем и обвесы
			"HH_K63_Helmet_Black", 
			{},

			// Броник и обвесы
			"HH_Vest_IOTV_Black",
			{
				"HH_Vest_IOTV_Grenade_Pounch_Black",
				"HH_Vest_IOTV_Grenade_Pounch_Black",
				"HH_Vest_IOTV_Mag_pounch_Black",
				"HH_Vest_IOTV_Mag_pounch_Black",
				"HH_Vest_IOTV_BackPocketIFAK_Black",
			},

			// Содержимое карманов
			{
				"HH_Mag_PKM_250Rnd", "HH_Mag_PKM_250Rnd", "HH_Mag_PKP_100Rnd",
				"Ammo_762x54Tracer", "Ammo_762x54Tracer", "Ammo_762x54Tracer", "Ammo_762x54Tracer",
				"BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "Vodka",
				"Epinephrine", "Epinephrine", "PainKillerTablets", "PainKillerTablets", "TetracyclineAntibiotics", "TetracyclineAntibiotics", "Morphine", "Morphine", "Splint", "HuntingOptic",
				"Battery9V", "Battery9V",
				"RGD5Grenade", "M67Grenade"
			});


		PlayerSet set6 = new PlayerSet(
			// одежда
			{"HH_TTsKOJacket_Camo", "HH_Pants_kneepads_TTSKO", "HH_Military_Boots_Black", "TacticalGloves_Green"}, 

			// оружие и обвесы
			"HH_PKM",
			"HH_Mag_PKM_250Rnd",
			{"KobraOptic"},

			// Шлем и обвесы
			"HH_K63_Helmet_Green", 
			{},

			// Броник и обвесы
			"HH_Vest_6b13_Frendly_Tan",
			{},

			// Содержимое карманов
			{
				"HH_Mag_PKM_250Rnd", "HH_Mag_PKM_250Rnd",
				"Ammo_762x54Tracer", "Ammo_762x54Tracer", "Ammo_762x54Tracer", "Ammo_762x54Tracer",
				"BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing",
				"Epinephrine", "Epinephrine", "Morphine", "Morphine", "Splint",
				"PainKillerTablets", "Battery9V", "Battery9V", "Vodka",
				"RGD5Grenade", "M67Grenade"
			});



		PlayerSet set7 = new PlayerSet(
			// одежда
			{"HH_TTsKOJacket_Camo", "HH_Pants_kneepads_TTSKO", "HH_Military_Boots_Black", "TacticalGloves_Green"}, 

			// оружие и обвесы
			"HH_ASVAL",
			"HH_Mag_ASVAL_VSS_30Rnd_Spar",
			{"HH_OKP7Optic"},

			// Шлем и обвесы
			"HH_K63_Helmet_Green", 
			{},

			// Броник и обвесы
			"HH_Vest_6b13_Frendly_Tan",
			{},

			// Содержимое карманов
			{
				"HH_Mag_ASVAL_VSS_30Rnd_Spar", "HH_Mag_ASVAL_VSS_30Rnd_Spar", "HH_Mag_ASVAL_VSS_30Rnd_Spar", "HH_Mag_ASVAL_VSS_30Rnd_Spar",
				"Ammo_9x39AP", "Ammo_9x39AP", "Ammo_9x39AP", "Ammo_9x39AP", "Ammo_9x39AP",
				"PainKillerTablets", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "Vodka", 
				"Epinephrine", "Epinephrine", "Morphine", "Morphine", "Splint",
				"Battery9V", "Battery9V",
				"RGD5Grenade", "M67Grenade"
			});



		PlayerSet set8 = new PlayerSet(
			// одежда
			{"HH_TTsKOJacket_Camo", "HH_Pants_kneepads_TTSKO", "HH_Military_Boots_Black", "TacticalGloves_Green"}, 

			// оружие и обвесы
			"HH_PKP",
			"HH_Mag_PKM_250Rnd",
			{"HH_OKP7Optic"},

			// Шлем и обвесы
			"HH_Maska1sch_Green", 
			{"HH_Maska1sch_Visor_Green"},

			// Броник и обвесы
			"HH_Vest_6b43_TTsKO",
			{
				"HH_Vest_6b43_BackPocket_TTsKO",
				"HH_Vest_6b43_FrontPocket_TTsKO",
				"HH_Vest_6b43_LeftSidePocket_TTsKO",
				"HH_Vest_6b43_RightSidePocket_TTsKO",
				"HH_Vest_6b43_Apron_TTsKO",
			},

			// Содержимое карманов
			{
				"HH_Mag_PKM_250Rnd", "HH_Mag_PKM_250Rnd", "HH_Mag_PKP_100Rnd",
				"Vodka", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing",
				"Ammo_762x54Tracer", "Ammo_762x54Tracer", "Ammo_762x54Tracer", "Ammo_762x54Tracer",  "Ammo_762x54Tracer",  "Ammo_762x54Tracer",
				"Epinephrine", "Epinephrine", "Morphine", "Morphine", "Splint",
				"Ammo_762x54Tracer", "Ammo_762x54Tracer", "Ammo_762x54Tracer", "Ammo_762x54Tracer",  "Ammo_762x54Tracer",  "Ammo_762x54Tracer",
				"Battery9V", "Battery9V", "PainKillerTablets",
			});


		// this.PlayerSetups.Insert(set1);
		// this.PlayerSetups.Insert(set2);
		// this.PlayerSetups.Insert(set3);
		this.PlayerSetups.Insert(set4);
		this.PlayerSetups.Insert(set5);
		this.PlayerSetups.Insert(set6);
		this.PlayerSetups.Insert(set7);
		this.PlayerSetups.Insert(set8);
	}
}

class PlayerSet
{
	string Weapon;
	string Helmet;
	string Vest;
	string MagType;

	ref array<string> Clothes				= new array<string>;
	ref array<string> Equipment 			= new array<string>;

	ref array<string> WeaponAttachments 	= new array<string>;
	ref array<string> HelmetAttachments		= new array<string>;
	ref array<string> VestAttachments 		= new array<string>;

	void PlayerSet(ref array<string> cl, string wp, string magType, ref array<string> wpatt, string hel, ref array<string> helAtt, string vest, ref array<string> vestAtt, ref array<string> eq) {
		this.Clothes = cl;
		this.Weapon = wp;
		this.WeaponAttachments = wpatt;
		this.Equipment = eq;

		this.Helmet = hel;
		this.HelmetAttachments = helAtt;
		this.Vest = vest;
		this.VestAttachments = vestAtt;

		this.MagType = magType;
	}
}


		
