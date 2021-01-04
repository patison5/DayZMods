class SetupPlayerOptions 
{
	ref array<ref PlayerSet> PlayerSetups = new array<ref PlayerSet>;
	
	void InitPlayerSetups() {

		// HH_AR15Beowulf_Tan
		PlayerSet set1 = new PlayerSet(
			// одежда
			{"HH_TTsKOJacket_Camo", "HH_Pants_kneepads_TTSKO", "HH_Military_Boots_Black", "TacticalGloves_Green"}, 

			// оружие, тип магазина и обвесы
			"HH_AR15Beowulf_Tan",
			"HH_Mag_AR15Beowulf_10Rnd",
			{"M4_T3NRDSOptic"},

			// второе оружие, тип магазина и обвесы
			"",
			"",
			{""},


			// Шлем и обвесы
			"HH_K63_Helmet_Green", 
			{},

			// Броник и обвесы
			"HH_PlateCarrierVest_black",
			{"HH_PlateCarrierHolster_black", "HH_PlateCarrierPounches_black"},

			// Содержимое карманов
			{
				"HH_Mag_AR15Beowulf_10Rnd", "HH_Mag_AR15Beowulf_10Rnd", "HH_Mag_AR15Beowulf_10Rnd", "HH_Mag_AR15Beowulf_10Rnd", "HH_Mag_AR15Beowulf_10Rnd", "HH_Mag_AR15Beowulf_10Rnd",
				"PainKillerTablets", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "Vodka", 
				"Epinephrine", "Epinephrine", "Morphine", "Morphine", "Splint",
				"Battery9V", "Battery9V",
				"RGD5Grenade", "M67Grenade"
			});

		// HH_FalMod
		PlayerSet set2 = new PlayerSet(
			// одежда
			{"TacticalGloves_Black", "TacticalShirt_Black", "HH_Pants_kneepads_black", "HH_Military_Boots_Black"},  

			// оружие, тип магазина и обвесы
			"HH_FalMod",
			"HH_Mag_Fal_100Rnd",
			{"M4_T3NRDSOptic", "HH_Cordura_Cover_suppressor_Black"},

			// Второе оружие, тип магазина и обвесы
			"",
			"",
			{""},

			// Шлем и обвесы
			"HH_K63_Helmet_Black", 
			{},

			// Броник и обвесы
			"HH_PlateCarrierVest_black",
			{"HH_PlateCarrierHolster_black", "HH_PlateCarrierPounches_black"},

			// Содержимое карманов
			{
				"HH_Mag_X_FAL_50Rnd", "HH_Mag_X_FAL_50Rnd", "HH_Mag_X_FAL_50Rnd", "HH_Mag_X_FAL_50Rnd", "HH_Mag_X_FAL_50Rnd", "HH_Mag_X_FAL_50Rnd",
				"PainKillerTablets", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "Vodka", 
				"Epinephrine", "Epinephrine", "Morphine", "Morphine", "Splint",
				"Battery9V", "Battery9V",
				"RGD5Grenade", "M67Grenade"
			});

		// HH_M110_Tan
		PlayerSet set3 = new PlayerSet(
			// одежда
			{"TacticalGloves_Black", "TacticalShirt_Black", "HH_Pants_kneepads_black", "HH_Military_Boots_Black"},  

			// оружие, тип магазина и обвесы
			"HH_M110_Tan",
			"HH_Mag_M110_20Rnd",
			{"HuntingOptic"},

			// Второе оружие, тип магазина и обвесы
			"",
			"",
			{""},

			// Шлем и обвесы
			"HH_K63_Helmet_Black", 
			{},

			// Броник и обвесы
			"HH_PlateCarrierVest_black",
			{"HH_PlateCarrierHolster_black", "HH_PlateCarrierPounches_black"},

			// Содержимое карманов
			{
				"HH_Mag_M110_20Rnd", "HH_Mag_M110_20Rnd", "HH_Mag_M110_20Rnd", "HH_Mag_M110_20Rnd", "HH_Mag_M110_20Rnd", "HH_Mag_M110_20Rnd",
				"PainKillerTablets", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "Vodka", 
				"Epinephrine", "Epinephrine", "Morphine", "Morphine", "Splint",
				"Battery9V", "Battery9V",
				"RGD5Grenade", "M67Grenade"
			});

		// HH_DVL10
		PlayerSet set4 = new PlayerSet(
			// одежда
			{"TacticalGloves_Black", "TacticalShirt_Black", "HH_Pants_kneepads_black", "HH_Military_Boots_Black"}, 

			// оружие, тип магазина и обвесы
			"HH_DVL10",
			"HH_Mag_DVL10_10Rnd",
			{"HH_LongRangeOptics_x24_Black"},

			// второе оружие, тип магазина и обвесы
			"HH_DVL10",
			"HH_Mag_DVL10_10Rnd",
			{"HH_LongRangeOptics_x24_Black"},


			// Шлем и обвесы
			"HH_Ops_Core_F_Black", 
			{
				"HH_Ops_Core_F_Ear_Black",
				"HH_Ops_Core_F_Visor_Black",
				"HH_Ops_Core_F_Mandible_Black",
				"HH_Ops_Core_F_SLAAP_Black"
			},

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

		// HH_PKP
		PlayerSet set5 = new PlayerSet(
			// одежда
			{"TacticalGloves_Black", "TacticalShirt_Black", "HH_Pants_kneepads_black", "HH_Military_Boots_Black"}, 

			// оружие, тип магазина и обвесы
			"HH_PKP",
			"HH_Mag_PKM_250Rnd",
			{"KobraOptic", "HH_PBS4_Suppressor"},

			// второе оружие, тип магазина и обвесы
			"",
			"",
			{},



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

		// HH_PKM
		PlayerSet set6 = new PlayerSet(
			// одежда
			{"HH_TTsKOJacket_Camo", "HH_Pants_kneepads_TTSKO", "HH_Military_Boots_Black", "TacticalGloves_Green"}, 

			// оружие, тип магазина и обвесы
			"HH_PKM",
			"HH_Mag_PKM_250Rnd",
			{"KobraOptic"},

			// Второе оружие, тип магазина и обвесы
			"HH_PKM",
			"HH_Mag_PKM_250Rnd",
			{"KobraOptic", "HH_PBS4_Suppressor"},

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

		// HH_ASVAL
		PlayerSet set7 = new PlayerSet(
			// одежда
			{"HH_TTsKOJacket_Camo", "HH_Pants_kneepads_TTSKO", "HH_Military_Boots_Black", "TacticalGloves_Green"}, 

			// оружие, тип магазина и обвесы
			"HH_ASVAL",
			"HH_Mag_ASVAL_VSS_30Rnd_Spar",
			{"HH_OKP7Optic"},

			// Второе оружие, тип магазина и обвесы
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

		// HH_PKP
		PlayerSet set8 = new PlayerSet(
			// одежда
			{"HH_TTsKOJacket_Camo", "HH_Pants_kneepads_TTSKO", "HH_Military_Boots_Black", "TacticalGloves_Green"}, 

			// оружие, тип магазина и обвесы
			"HH_PKP",
			"HH_Mag_PKM_250Rnd",
			{"HH_OKP7Optic"},

			// Второе оружие, тип магазина и обвесы
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

		// HH_AR15_Used
		PlayerSet set9 = new PlayerSet(
			// одежда
			{"HH_TTsKOJacket_Camo", "HH_Pants_kneepads_TTSKO", "HH_Military_Boots_Black", "TacticalGloves_Green"}, 

			// оружие, тип магазина и обвесы
			"HH_AR15_Used",
			"HH_Mag_PMAG_D_60Rnd",
			{"HH_OKP7Optic"},

			// Второе оружие, тип магазина и обвесы
			"",
			"",
			{},

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
				"HH_Mag_PMAG_D_60Rnd", "HH_Mag_PMAG_D_60Rnd", "HH_Mag_PMAG_D_60Rnd", "HH_Mag_PMAG_D_60Rnd", "Mag_STANAG_30Rnd", "Mag_STANAG_30Rnd",
				"Vodka", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing",
				"Ammo_556x45", "Ammo_556x45", "Ammo_556x45", "Ammo_556x45",  "Ammo_556x45",  "Ammo_556x45",
				"Epinephrine", "Epinephrine", "Morphine", "Morphine", "Splint",
				"Battery9V", "Battery9V", "PainKillerTablets",
			});

		// HH_HKG36
		PlayerSet set10 = new PlayerSet(
			// одежда
			{"HH_TTsKOJacket_Camo", "HH_Pants_kneepads_TTSKO", "HH_Military_Boots_Black", "TacticalGloves_Green"}, 

			// оружие, тип магазина и обвесы
			"HH_HKG36",
			"HH_Mag_HKG36_30Rnd",
			{"HH_OKP7Optic"},

			// Второе оружие, тип магазина и обвесы
			"",
			"",
			{},

			// Шлем и обвесы
			"HH_Maska1sch_Green", 
			{"HH_Maska1sch_Visor_Green"},

			// Броник и обвесы
			"HH_PlateCarrierVest_black",
			{
				"HH_PlateCarrierHolster_black",
                "HH_PlateCarrierPounches_black"
			},

			// Содержимое карманов
			{
				"HH_Mag_HKG36_30Rnd", "HH_Mag_HKG36_30Rnd", "HH_Mag_HKG36_30Rnd", "HH_Mag_HKG36_30Rnd", "HH_Mag_HKG36_30Rnd", "HH_Mag_HKG36_30Rnd",
				"Vodka", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing",
				"Ammo_556x45", "Ammo_556x45", "Ammo_556x45", "Ammo_556x45",  "Ammo_556x45",  "Ammo_556x45",
				"Epinephrine", "Epinephrine", "Morphine", "Morphine", "Splint",
				"Battery9V", "Battery9V", "PainKillerTablets",
			});

		// HH_OSV96_Black
		PlayerSet set11 = new PlayerSet(
			// одежда
			{"HH_TTsKOJacket_Camo", "HH_Pants_kneepads_TTSKO", "HH_Military_Boots_Black", "TacticalGloves_Green"}, 

			// оружие, тип магазина и обвесы
			"HH_OSV96_Black",
			"HH_Mag_OSV96_7Rnd",
			{"HuntingOptic"},

			// Второе оружие, тип магазина и обвесы
			"",
			"",
			{},

			// Шлем и обвесы
			"HH_Ops_Core_F_Green", 
			{
				"HH_Ops_Core_F_Ear_Green",
				"HH_Ops_Core_F_Visor_Green",
				"HH_Ops_Core_F_Mandible_Green",
				"HH_Ops_Core_F_SLAAP_Green",
				"HH_PGNVG_Black"
			},

			// Броник и обвесы
			"HH_PlateCarrierVest_black",
			{
				"HH_PlateCarrierHolster_black",
                "HH_PlateCarrierPounches_black"
			},

			// Содержимое карманов
			{
				"HH_Mag_OSV96_7Rnd", "HH_Mag_OSV96_7Rnd", "HH_Mag_OSV96_7Rnd", "HH_Mag_OSV96_7Rnd", "HH_Mag_OSV96_7Rnd", "HH_Mag_OSV96_7Rnd",
				"Vodka", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing",
				"Ammo_556x45", "Ammo_556x45", "Ammo_556x45", "Ammo_556x45",  "Ammo_556x45",  "Ammo_556x45",
				"Epinephrine", "Epinephrine", "Morphine", "Morphine", "Splint",
				"Battery9V", "Battery9V", "PainKillerTablets",
			});

		// HH_M82_White
		PlayerSet set12 = new PlayerSet(
			// одежда
			{"HH_TTsKOJacket_Camo", "HH_Pants_kneepads_TTSKO", "HH_Military_Boots_Black", "TacticalGloves_Green"}, 

			// оружие, тип магазина и обвесы
			"HH_M82_White",
			"HH_Mag_M82_10Rnd",
			{"HuntingOptic"},

			// Второе оружие, тип магазина и обвесы
			"",
			"",
			{},

			// Шлем и обвесы
			"HH_K63_Helmet_Black", 
			{},

			// Броник и обвесы
			"HH_PlateCarrierVest_black",
			{
				"HH_PlateCarrierHolster_black",
                "HH_PlateCarrierPounches_black"
			},

			// Содержимое карманов
			{
				"HH_Mag_M82_10Rnd", "HH_Mag_M82_10Rnd", "HH_Mag_M82_10Rnd", "HH_Mag_M82_10Rnd", "HH_Mag_M82_10Rnd", "HH_Mag_M82_10Rnd",
				"Vodka", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing",
				"HH_AmmoBox_127x99_10Rnd", "HH_AmmoBox_127x99_10Rnd", "HH_AmmoBox_127x99_10Rnd", "HH_AmmoBox_127x99_10Rnd",  "HH_AmmoBox_127x99_10Rnd",  "HH_AmmoBox_127x99_10Rnd",
				"Epinephrine", "Epinephrine", "Morphine", "Morphine", "Splint",
				"Battery9V", "Battery9V", "PainKillerTablets",
			});

		// HH_VSSK
		PlayerSet set13 = new PlayerSet(
			// одежда
			{"HH_TTsKOJacket_Camo", "HH_Pants_kneepads_TTSKO", "HH_Military_Boots_Black", "TacticalGloves_Green"}, 

			// оружие, тип магазина и обвесы
			"HH_VSSK",
			"HH_Mag_VSSK_5Rnd",
			{"HuntingOptic"},

			// Второе оружие, тип магазина и обвесы
			"",
			"",
			{},

			// Шлем и обвесы
			"HH_K63_Helmet_Black", 
			{},

			// Броник и обвесы
			"HH_PlateCarrierVest_black",
			{
				"HH_PlateCarrierHolster_black",
                "HH_PlateCarrierPounches_black"
			},

			// Содержимое карманов
			{
				"HH_Mag_VSSK_5Rnd", "HH_Mag_VSSK_5Rnd", "HH_Mag_VSSK_5Rnd", "HH_Mag_VSSK_5Rnd", "HH_Mag_VSSK_5Rnd", "HH_Mag_VSSK_5Rnd",
				"Vodka", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing",
				"HH_AmmoBox_127x99_10Rnd", "HH_AmmoBox_127x99_10Rnd", "HH_AmmoBox_127x99_10Rnd", "HH_AmmoBox_127x99_10Rnd",  "HH_AmmoBox_127x99_10Rnd",  "HH_AmmoBox_127x99_10Rnd",
				"Epinephrine", "Epinephrine", "Morphine", "Morphine", "Splint",
				"Battery9V", "Battery9V", "PainKillerTablets",
			});

		// HH_Groza
		PlayerSet set14 = new PlayerSet(
			// одежда
			{"TacticalGloves_Black", "TacticalShirt_Black", "HH_Pants_kneepads_black", "HH_Military_Boots_Black"}, 

			// оружие, тип магазина и обвесы
			"HH_Groza",
			"HH_Mag_Groza_20Rnd",
			{""},

			// второе оружие, тип магазина и обвесы
			"HH_Glock18c",
			"HH_Mag_Glock18c_50Rnd",
			{"HH_Glock18C_Hndgrd_Black", "FNP45_MRDSOptic", "ImprovisedSuppressor"},


			// Шлем и обвесы
			"HH_Ops_Core_F_Black", 
			{
				"HH_Ops_Core_F_Ear_Black",
				"HH_Ops_Core_F_Visor_Black",
				"HH_Ops_Core_F_Mandible_Black",
				"HH_Ops_Core_F_SLAAP_Black"
			},

			// Броник и обвесы
			"HH_PlateCarrierVest_black",
			{
				"HH_PlateCarrierHolster_back",
                "HH_PlateCarrierPouches_black"
			},

			// Содержимое карманов
			{
				"HH_Mag_Groza_20Rnd", "HH_Mag_Groza_20Rnd", "HH_Mag_Groza_20Rnd", "HH_Mag_Groza_20Rnd", "HH_Mag_Groza_20Rnd", "HH_Mag_Groza_20Rnd",
				"Ammo_9x39AP", "Ammo_9x39AP", "Ammo_9x39AP", "Ammo_9x39AP",  "Ammo_9x39AP",  "Ammo_9x39AP",
				"HH_Mag_Glock18c_50Rnd", "HH_Mag_Glock18c_50Rnd", "HH_Mag_Glock18c_50Rnd"
				"BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "Vodka",
				"Epinephrine", "Epinephrine", "PainKillerTablets", "PainKillerTablets", "TetracyclineAntibiotics", "TetracyclineAntibiotics", "Morphine", "Morphine", "Splint", "HuntingOptic",
				"Battery9V", "Battery9V",
				"RGD5Grenade", "M67Grenade"
			});

		// HH_AugA1
		PlayerSet set15 = new PlayerSet(
			// одежда
			{"TacticalGloves_Black", "TacticalShirt_Black", "HH_Pants_kneepads_black", "HH_Military_Boots_Black"}, 

			// оружие, тип магазина и обвесы
			"HH_AugA1",
			"HH_Mag_PMAG_D_60Rnd",
			{""},

			// второе оружие, тип магазина и обвесы
			"HH_Glock18c",
			"HH_Mag_Glock18c_50Rnd",
			{"HH_Glock18C_Hndgrd_Black", "FNP45_MRDSOptic", "PistolSuppressor"},


			// Шлем и обвесы
			"HH_Ops_Core_F_Black", 
			{
				"HH_Ops_Core_F_Ear_Black",
				"HH_Ops_Core_F_Visor_Black",
				"HH_Ops_Core_F_Mandible_Black",
				"HH_Ops_Core_F_SLAAP_Black"
			},

			// Броник и обвесы
			"HH_PlateCarrierVest_black",
			{
				"HH_PlateCarrierHolster_back",
                "HH_PlateCarrierPouches_black"
			},

			// Содержимое карманов
			{
				"HH_Mag_PMAG_D_60Rnd", "HH_Mag_PMAG_D_60Rnd", "HH_Mag_PMAG_D_60Rnd", "HH_Mag_PMAG_D_60Rnd", "HH_Mag_PMAG_D_60Rnd", "HH_Mag_PMAG_D_60Rnd",
				"Ammo_9x39AP", "Ammo_9x39AP", "Ammo_9x39AP", "Ammo_9x39AP",  "Ammo_9x39AP",  "Ammo_9x39AP",
				"HH_Mag_Glock18c_50Rnd", "HH_Mag_Glock18c_50Rnd", "HH_Mag_Glock18c_50Rnd"
				"BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "Vodka",
				"Epinephrine", "Epinephrine", "PainKillerTablets", "PainKillerTablets", "TetracyclineAntibiotics", "TetracyclineAntibiotics", "Morphine", "Morphine", "Splint", "HuntingOptic",
				"Battery9V", "Battery9V",
				"RGD5Grenade", "M67Grenade"
			});

		// HH_Famas
		PlayerSet set16 = new PlayerSet(
			// одежда
			{"TacticalGloves_Black", "TacticalShirt_Black", "HH_Pants_kneepads_black", "HH_Military_Boots_Black"}, 

			// оружие, тип магазина и обвесы
			"HH_Famas",
			"Mag_STANAGCoupled_30Rnd",
			{"ACOGOptic", "M4_Suppressor"},

			// второе оружие, тип магазина и обвесы
			"HH_Glock18c",
			"HH_Mag_Glock18c_50Rnd",
			{"HH_Glock18C_Hndgrd_Black", "FNP45_MRDSOptic", "PistolSuppressor"},


			// Шлем и обвесы
			"HH_Ops_Core_F_Black", 
			{
				"HH_Ops_Core_F_Ear_Black",
				"HH_Ops_Core_F_Visor_Black",
				"HH_Ops_Core_F_Mandible_Black",
				"HH_Ops_Core_F_SLAAP_Black"
			},

			// Броник и обвесы
			"HH_PlateCarrierVest_black",
			{
				"HH_PlateCarrierHolster_back",
                "HH_PlateCarrierPouches_black"
			},

			// Содержимое карманов
			{
				"Mag_STANAG_30Rnd", "Mag_STANAG_30Rnd", "Mag_STANAG_30Rnd", "Mag_STANAG_30Rnd", "Mag_STANAG_30Rnd", "Mag_STANAG_30Rnd",
				"Ammo_9x39AP", "Ammo_9x39AP", "Ammo_9x39AP", "Ammo_9x39AP",  "Ammo_9x39AP",  "Ammo_9x39AP",
				"HH_Mag_Glock18c_50Rnd", "HH_Mag_Glock18c_50Rnd", "HH_Mag_Glock18c_50Rnd"
				"BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "Vodka",
				"Epinephrine", "Epinephrine", "PainKillerTablets", "PainKillerTablets", "TetracyclineAntibiotics", "TetracyclineAntibiotics", "Morphine", "Morphine", "Splint", "HuntingOptic",
				"Battery9V", "Battery9V",
				"RGD5Grenade", "M67Grenade"
			});

		this.PlayerSetups.Insert(set1);
		this.PlayerSetups.Insert(set2);
		this.PlayerSetups.Insert(set3);
		this.PlayerSetups.Insert(set4);
		this.PlayerSetups.Insert(set5);
		this.PlayerSetups.Insert(set6);
		this.PlayerSetups.Insert(set7);
		this.PlayerSetups.Insert(set8);
		this.PlayerSetups.Insert(set9);
		this.PlayerSetups.Insert(set10);
		this.PlayerSetups.Insert(set11);
		this.PlayerSetups.Insert(set12);
		this.PlayerSetups.Insert(set13);
		this.PlayerSetups.Insert(set14);
		this.PlayerSetups.Insert(set15);
		this.PlayerSetups.Insert(set16);
	}
}

class PlayerSet
{
	string Weapon;
	string Weapon2;
	string Helmet;
	string Vest;
	string MagType;
	string MagType2;

	ref array<string> Clothes				= new array<string>;
	ref array<string> Equipment 			= new array<string>;

	ref array<string> WeaponAttachments 	= new array<string>;
	ref array<string> WeaponAttachments2 	= new array<string>;
	ref array<string> HelmetAttachments		= new array<string>;
	ref array<string> VestAttachments 		= new array<string>;

	void PlayerSet(ref array<string> cl, string wp, string magType, ref array<string> wpatt, string wp2, string magType2, ref array<string> wpatt2, string hel, ref array<string> helAtt, string vest, ref array<string> vestAtt, ref array<string> eq) {
		this.Clothes = cl;
		this.Equipment = eq;

		this.Helmet = hel;
		this.HelmetAttachments = helAtt;
		this.Vest = vest;
		this.VestAttachments = vestAtt;

		this.Weapon = wp;
		this.WeaponAttachments = wpatt;
		this.MagType = magType;

		this.Weapon2 = wp2;
		this.WeaponAttachments2 = wpatt2;
		this.MagType2 = magType2;
	}
}


		
