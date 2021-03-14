class SetupPlayerOptions 
{
	// ref array<ref PlayerSet> PlayerSetups = new array<ref PlayerSet>;

	ref array<ref PlayerClothes> heavyClothes = new array<ref PlayerClothes>;
	ref array<ref PlayerWeapon>  heavyWeapons = new array<ref PlayerWeapon>;

	ref array<ref PlayerClothes> lightClothes = new array<ref PlayerClothes>;
	ref array<ref PlayerWeapon>  lightWeapons = new array<ref PlayerWeapon>;

	ref array<ref PlayerClothes> snipingClothes = new array<ref PlayerClothes>;
	ref array<ref PlayerWeapon>  snipingWeapons = new array<ref PlayerWeapon>;

	ref array<ref PlayerClothesVip> clothesVip = new array<ref PlayerClothesVip>;
	
	void InitPlayerSetups() {

		// #################### НОВОЕ ЗАПОЛНЕНИЕ ОДЕЖДОЙ ####################

		// Black IOTV
		PlayerClothes setB1 = new PlayerClothes(
			// одежда
			{"HH_TacticalShirt_black", "CargoPants_Black", "TTSKOBoots", "TacticalGloves_Black"}, 

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
			});

		// TTSKO IOTV
		PlayerClothes setTT1 = new PlayerClothes(
			// одежда
			{"HH_TTsKOJacket_Camo", "TTSKOPants", "TTSKOBoots", "TacticalGloves_Green"}, 

			// Шлем и обвесы
			"HH_K63_Helmet_Green", 
			{},

			// Броник и обвесы
			"HH_Vest_IOTV_Woods",
			{
				"HH_Vest_IOTV_Grenade_Pounch_Woods",
				"HH_Vest_IOTV_Grenade_Pounch_Woods",
				"HH_Vest_IOTV_Mag_pounch_Woods",
				"HH_Vest_IOTV_Mag_pounch_Woods",
				"HH_Vest_IOTV_BackPocketIFAK_Woods",
			});

		// Green IOTV
		PlayerClothes setG1 = new PlayerClothes(
			// одежда
			{"HH_TacticalShirt_olive", "HH_CargoPants_green", "TTSKOBoots", "TacticalGloves_Green"}, 

			// Шлем и обвесы
			"HH_K63_Helmet_Green", 
			{},

			// Броник и обвесы
			"HH_Vest_IOTV_Green",
			{
				"HH_Vest_IOTV_Grenade_Pounch_Green",
				"HH_Vest_IOTV_Grenade_Pounch_Green",
				"HH_Vest_IOTV_Mag_pounch_Green",
				"HH_Vest_IOTV_Mag_pounch_Green",
				"HH_Vest_IOTV_BackPocketIFAK_Green",
			});

		// Tan IOTV
		PlayerClothes setT1 = new PlayerClothes(
			// одежда
			{"M65Jacket_Tan", "CargoPants_Beige", "TTSKOBoots", "TacticalGloves_Black"}, 

			// Шлем и обвесы
			"HH_K63_Helmet_Green", 
			{},

			// Броник и обвесы
			"HH_Vest_IOTV_Tan",
			{
				"HH_Vest_IOTV_Grenade_Pounch_Tan",
				"HH_Vest_IOTV_Grenade_Pounch_Tan",
				"HH_Vest_IOTV_Mag_pounch_Tan",
				"HH_Vest_IOTV_Mag_pounch_Tan",
				"HH_Vest_IOTV_BackPocketIFAK_Tan",
			});

		// UCP IOTV
		PlayerClothes setU1 = new PlayerClothes(
			// одежда
			{"HH_TacticalShirt_olive", "HH_CargoPants_green", "TTSKOBoots", "TacticalGloves_Green"}, 

			// Шлем и обвесы
			"HH_K63_Helmet_Green", 
			{},

			// Броник и обвесы
			"HH_Vest_IOTV_UCP",
			{
				"HH_Vest_IOTV_Grenade_Pounch_UCP",
				"HH_Vest_IOTV_Grenade_Pounch_UCP",
				"HH_Vest_IOTV_Mag_pounch_UCP",
				"HH_Vest_IOTV_Mag_pounch_UCP",
				"HH_Vest_IOTV_BackPocketIFAK_UCP",
			});	



		// Green 6b13
		PlayerClothes setG2 = new PlayerClothes(
			// одежда
			{"HH_TacticalShirt_olive", "HH_CargoPants_green", "TTSKOBoots", "TacticalGloves_Green"}, 

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
			"HH_Vest_6b13_Frendly_Green",
			{

			});

		// Tan 6b13
		PlayerClothes setT2 = new PlayerClothes(
			// одежда
			{"HH_TTsKOJacket_Camo", "TTSKOPants", "TTSKOBoots", "TacticalGloves_Black"}, 

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
			"HH_Vest_6b13_Frendly_Tan",
			{

			});



		// Dark 6b43
		PlayerClothes setD3 = new PlayerClothes(
			// одежда
			{"HH_TacticalShirt_black", "CargoPants_Black", "TTSKOBoots", "TacticalGloves_Black"}, 

			// Шлем и обвесы
			"HH_Maska1sch_Black", 
			{"HH_Maska1sch_Visor_Black"},

			// Броник и обвесы
			"HH_Vest_6b43_Flora_dark",
			{
				"HH_Vest_6b43_Apron_Flora_dark"
			});

		// Black 6b43
		PlayerClothes setB3 = new PlayerClothes(
			// одежда
			{"HH_TacticalShirt_black", "CargoPants_Black", "TTSKOBoots", "TacticalGloves_Black"}, 

			// Шлем и обвесы
			"HH_Maska1sch_Black", 
			{"HH_Maska1sch_Visor_Black"},

			// Броник и обвесы
			"HH_Vest_6b43_Black",
			{
				"HH_Vest_6b43_BackPocket_Black",
                "HH_Vest_6b43_FrontPocket_Black",
                "HH_Vest_6b43_LeftSidePocket_Black",
                "HH_Vest_6b43_RightSidePocket_Black",
                "HH_Vest_6b43_Apron_Black"
			});

		// Green 6b43
		PlayerClothes setG3 = new PlayerClothes(
			// одежда
			{"HH_TacticalShirt_olive", "HH_CargoPants_green", "TTSKOBoots", "TacticalGloves_Green"}, 

			// Шлем и обвесы
			"HH_Maska1sch_Green", 
			{"HH_Maska1sch_Visor_Green"},

			// Броник и обвесы
			"HH_Vest_6b43_Green",
			{
				"HH_Vest_6b43_BackPocket_Green",
                "HH_Vest_6b43_FrontPocket_Green",
                "HH_Vest_6b43_LeftSidePocket_Green",
                "HH_Vest_6b43_RightSidePocket_Green",
                "HH_Vest_6b43_Apron_Green"
			});

		// TTSKO 6b43
		PlayerClothes setT3 = new PlayerClothes(
			// одежда
			{"HH_TTsKOJacket_Camo", "TTSKOPants", "TTSKOBoots", "TacticalGloves_Green"}, 

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
                "HH_Vest_6b43_Apron_TTsKO"
			});

		// Green 6b43
		PlayerClothes setF3 = new PlayerClothes(
			// одежда
			{"HH_TacticalShirt_olive", "HH_CargoPants_green", "TTSKOBoots", "TacticalGloves_Green"}, 

			// Шлем и обвесы
			"HH_Maska1sch_Green", 
			{"HH_Maska1sch_Visor_Green"},

			// Броник и обвесы
			"HH_Vest_6b43_Digital_flora",
			{
				"HH_Vest_6b43_BackPocket_Digital_flora",
                "HH_Vest_6b43_FrontPocket_Digital_flora",
                "HH_Vest_6b43_LeftSidePocket_Digital_flora",
                "HH_Vest_6b43_RightSidePocket_Digital_flora",
                "HH_Vest_6b43_Apron_Digital_flora"
			});



		// Green PlayeCarrier
		PlayerClothes setG4 = new PlayerClothes(
			// одежда
			{"HH_TacticalShirt_olive", "HH_CargoPants_green", "TTSKOBoots", "TacticalGloves_Green"}, 

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
			"PlateCarrierVest",
			{
				"PlateCarrierPouches",
                "PlateCarrierHolster",
			});

		// Black PlayeCarrier
		PlayerClothes setB4 = new PlayerClothes(
			// одежда
			{"HH_TacticalShirt_black", "CargoPants_Black", "TTSKOBoots", "TacticalGloves_Black"}, 

			// Шлем и обвесы
			"HH_Ops_Core_F_Black", 
			{
				"HH_Ops_Core_F_Ear_Black",
				"HH_Ops_Core_F_Visor_Black",
				"HH_Ops_Core_F_Mandible_Black",
				"HH_Ops_Core_F_SLAAP_Black",
				"HH_PGNVG_Black"
			},

			// Броник и обвесы
			"HH_PlateCarrierVest_black",
			{
				"HH_PlateCarrierPouches_black",
                "HH_PlateCarrierHolster_black",
			});

		// TTSKO PlayeCarrier
		PlayerClothes setF4 = new PlayerClothes(
			// одежда
			{"HH_TTsKOJacket_Camo", "TTSKOPants", "TTSKOBoots", "TacticalGloves_Green"}, 

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
			"HH_PlateCarrierVest_Flecktarn",
			{
				"HH_PlateCarrierPouches_Flecktarn",
                "HH_PlateCarrierHolster_Flecktarn",
			});

		// Flecktarn PlayeCarrier
		PlayerClothes setS4 = new PlayerClothes(
			// одежда
			{"HH_TTsKOJacket_Camo", "TTSKOPants", "TTSKOBoots", "TacticalGloves_Green"}, 

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
			"HH_PlateCarrierVest_SURPAT",
			{
				"HH_PlateCarrierPouches_SURPATn",
                "HH_PlateCarrierHolster_SURPATn",
			});



		//  UKAssVest_Black
		PlayerClothes setB5 = new PlayerClothes(
			// одежда
			{"HH_TacticalShirt_black", "CargoPants_Black", "TTSKOBoots", "TacticalGloves_Black"}, 

			// Шлем и обвесы
			"", 
			{},

			// Броник и обвесы
			"UKAssVest_Black",
			{});

		// UKAssVest_Camo
		PlayerClothes setT5 = new PlayerClothes(
			// одежда
			{"HH_TTsKOJacket_Camo", "TTSKOPants", "TTSKOBoots", "TacticalGloves_Green"}, 

			// Шлем и обвесы
			"", 
			{},

			// Броник и обвесы
			"UKAssVest_Camo",
			{});

		// UKAssVest_Olive
		PlayerClothes setO5 = new PlayerClothes(
			// одежда
			{"HH_TacticalShirt_black", "CargoPants_Black", "TTSKOBoots", "TacticalGloves_Black"}, 

			// Шлем и обвесы
			"", 
			{},

			// Броник и обвесы
			"UKAssVest_Olive",
			{});



		// тяжелая броня
		this.heavyClothes.Insert(setB1);
		this.heavyClothes.Insert(setTT1);
		this.heavyClothes.Insert(setG1);
		this.heavyClothes.Insert(setT1);
		this.heavyClothes.Insert(setU1);
		this.heavyClothes.Insert(setG2);
		this.heavyClothes.Insert(setT2);
		this.heavyClothes.Insert(setD3);
		this.heavyClothes.Insert(setB3);
		this.heavyClothes.Insert(setG3);
		this.heavyClothes.Insert(setT3);
		this.heavyClothes.Insert(setF3);

		// легкая броня
		this.lightClothes.Insert(setG4);
		this.lightClothes.Insert(setB4);
		this.lightClothes.Insert(setF4);
		this.lightClothes.Insert(setS4);
		this.lightClothes.Insert(setB5);
		this.lightClothes.Insert(setT5);
		this.lightClothes.Insert(setO5);



		// HH_AR15Beowulf_Tan
		PlayerWeapon HH_AR15Beowulf_Tan = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"HH_AR15Beowulf_Tan",
			"HH_Mag_AR15Beowulf_10Rnd",
			{"M4_T3NRDSOptic"},

			// второе оружие, тип магазина и обвесы
			"",
			"",
			{""},

			// Содержимое карманов
			{
				"HH_Mag_AR15Beowulf_10Rnd", "HH_Mag_AR15Beowulf_10Rnd", "HH_Mag_AR15Beowulf_10Rnd", "HH_Mag_AR15Beowulf_10Rnd", "HH_Mag_AR15Beowulf_10Rnd", "HH_Mag_AR15Beowulf_10Rnd",
				"PainKillerTablets", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", 
				"Epinephrine", "Epinephrine", "Morphine", "Morphine",
			});

		// HH_FalMod
		PlayerWeapon HH_FalMod = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"HH_FalMod",
			"HH_Mag_Fal_100Rnd",
			{"M4_T3NRDSOptic", "HH_Cordura_Cover_suppressor_Black"},

			// Второе оружие, тип магазина и обвесы
			"",
			"",
			{""},

			// Содержимое карманов
			{
				"HH_Mag_X_FAL_50Rnd", "HH_Mag_X_FAL_50Rnd", "HH_Mag_X_FAL_50Rnd", "HH_Mag_X_FAL_50Rnd", "HH_Mag_X_FAL_50Rnd", "HH_Mag_X_FAL_50Rnd",
				"PainKillerTablets", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", 
				"Epinephrine", "Epinephrine", "Morphine", "Morphine",
			});

		// FAL_Wood
		PlayerWeapon FAL_Wood = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"FAL_Wood",
			"HH_Mag_X_FAL_50Rnd",
			{"M4_T3NRDSOptic", "HH_Cordura_Cover_suppressor_Black", "Fal_WoodBttstck"},

			// Второе оружие, тип магазина и обвесы
			"",
			"",
			{""},

			// Содержимое карманов
			{
				"HH_Mag_X_FAL_50Rnd", "HH_Mag_X_FAL_50Rnd", "HH_Mag_X_FAL_50Rnd", "HH_Mag_X_FAL_50Rnd", "HH_Mag_X_FAL_50Rnd", "HH_Mag_X_FAL_50Rnd",
				"PainKillerTablets", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", 
				"Epinephrine", "Epinephrine", "Morphine", "Morphine",
			});


		// HH_M110_Tan
		PlayerWeapon HH_M110_Tan = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"HH_M110_Tan",
			"HH_Mag_M110_20Rnd",
			{"HuntingOptic"},

			// Второе оружие, тип магазина и обвесы
			"",
			"",
			{""},

			// Содержимое карманов
			{
				"HH_Mag_M110_20Rnd", "HH_Mag_M110_20Rnd", "HH_Mag_M110_20Rnd", "HH_Mag_M110_20Rnd", "HH_Mag_M110_20Rnd", "HH_Mag_M110_20Rnd",
				"PainKillerTablets", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", 
				"Epinephrine", "Epinephrine", "Morphine", "Morphine",
			});

		// HH_DVL10
		PlayerWeapon HH_DVL10 = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"HH_DVL10",
			"HH_Mag_DVL10_10Rnd",
			{"HuntingOptic"},

			// второе оружие, тип магазина и обвесы
			"",
			"",
			{""},

			// Содержимое карманов
			{
				"HH_Mag_DVL10_10Rnd", "HH_Mag_DVL10_10Rnd", "HH_Mag_DVL10_10Rnd", "HH_Mag_DVL10_10Rnd", "HH_Mag_DVL10_10Rnd", "HH_Mag_DVL10_10Rnd",
				"HH_Ammo_338", "HH_Ammo_338", "HH_Ammo_338", "HH_Ammo_338",  "HH_Ammo_338",  "HH_Ammo_338",
				"BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing",
				"Epinephrine", "Epinephrine", "PainKillerTablets", "PainKillerTablets", "TetracyclineAntibiotics", "TetracyclineAntibiotics", "Morphine", "Morphine", "HH_LongRangeOptics_x24_Black",
			});

		// HH_PKP
		PlayerWeapon HH_PKPs = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"HH_PKP",
			"HH_Mag_PKM_250Rnd",
			{"KobraOptic", "HH_PBS4_Suppressor"},

			// второе оружие, тип магазина и обвесы
			"",
			"",
			{},

			// Содержимое карманов
			{
				"HH_Mag_PKM_250Rnd", "HH_Mag_PKM_250Rnd", "HH_Mag_PKP_100Rnd",
				"Ammo_762x54Tracer", "Ammo_762x54Tracer", "Ammo_762x54Tracer", "Ammo_762x54Tracer",
				"BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing",
				"Epinephrine", "Epinephrine", "PainKillerTablets", "PainKillerTablets", "TetracyclineAntibiotics", "TetracyclineAntibiotics", "Morphine", "Morphine",
			});

		// HH_PKM
		PlayerWeapon HH_PKM = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"HH_PKM",
			"HH_Mag_PKM_250Rnd",
			{"KobraOptic"},

			// Второе оружие, тип магазина и обвесы
			"",
			"",
			{},

			// Содержимое карманов
			{
				"HH_Mag_PKM_250Rnd", "HH_Mag_PKM_250Rnd",
				"Ammo_762x54Tracer", "Ammo_762x54Tracer", "Ammo_762x54Tracer", "Ammo_762x54Tracer","Ammo_762x54Tracer", "Ammo_762x54Tracer", "Ammo_762x54Tracer", "Ammo_762x54Tracer",
				"BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing",
				"Epinephrine", "Epinephrine", "Morphine", "Morphine",
				"PainKillerTablets",
			});

		// HH_PKP
		PlayerWeapon HH_PKP = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"HH_PKP",
			"HH_Mag_PKM_250Rnd",
			{"KobraOptic"},

			// Второе оружие, тип магазина и обвесы
			"",
			"",
			{""},

			// Содержимое карманов
			{
				"HH_Mag_PKM_250Rnd", "HH_Mag_PKM_250Rnd", "HH_Mag_PKP_100Rnd",
				"BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing",
				"Ammo_762x54Tracer", "Ammo_762x54Tracer", "Ammo_762x54Tracer", "Ammo_762x54Tracer",  "Ammo_762x54Tracer",  "Ammo_762x54Tracer",
				"Epinephrine", "Epinephrine", "Morphine", "Morphine",
				"Ammo_762x54Tracer", "Ammo_762x54Tracer", "Ammo_762x54Tracer", "Ammo_762x54Tracer",  "Ammo_762x54Tracer",  "Ammo_762x54Tracer",
				"PainKillerTablets"
			});

		// HH_AR15_Used
		PlayerWeapon HH_AR15_Used = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"HH_AR15_Used",
			"HH_Mag_PMAG_D_60Rnd",
			{"HH_OKP7Optic"},

			// Второе оружие, тип магазина и обвесы
			"",
			"",
			{},

			// Содержимое карманов
			{
				"HH_Mag_PMAG_D_60Rnd", "HH_Mag_PMAG_D_60Rnd", "HH_Mag_PMAG_D_60Rnd", "HH_Mag_PMAG_D_60Rnd", "Mag_STANAG_30Rnd", "Mag_STANAG_30Rnd",
				"BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing",
				"Ammo_556x45", "Ammo_556x45", "Ammo_556x45", "Ammo_556x45",  "Ammo_556x45",  "Ammo_556x45",
				"Epinephrine", "Epinephrine", "Morphine", "Morphine",
				"PainKillerTablets"
			});

		// HH_HKG36
		PlayerWeapon HH_HKG36 = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"HH_HKG36",
			"HH_Mag_HKG36_30Rnd",
			{"HH_OKP7Optic"},

			// Второе оружие, тип магазина и обвесы
			"",
			"",
			{},

			// Содержимое карманов
			{
				"HH_Mag_HKG36_30Rnd", "HH_Mag_HKG36_30Rnd", "HH_Mag_HKG36_30Rnd", "HH_Mag_HKG36_30Rnd", "HH_Mag_HKG36_30Rnd", "HH_Mag_HKG36_30Rnd",
				"BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing",
				"Ammo_556x45", "Ammo_556x45", "Ammo_556x45", "Ammo_556x45",  "Ammo_556x45",  "Ammo_556x45",
				"Epinephrine", "Epinephrine", "Morphine", "Morphine",
				"PainKillerTablets"
			});

		// HH_OSV96_Black
		PlayerWeapon HH_OSV96_Black = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"HH_OSV96_Black",
			"HH_Mag_OSV96_7Rnd",
			{"HuntingOptic"},

			// Второе оружие, тип магазина и обвесы
			"",
			"",
			{},

			// Содержимое карманов
			{
				"HH_Mag_OSV96_7Rnd", "HH_Mag_OSV96_7Rnd", "HH_Mag_OSV96_7Rnd", "HH_Mag_OSV96_7Rnd", "HH_Mag_OSV96_7Rnd", "HH_Mag_OSV96_7Rnd",
				"BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing",
				"HH_Ammo_127x108", "HH_Ammo_127x108", "HH_Ammo_127x108", "HH_Ammo_127x108",  "HH_Ammo_127x108",  "HH_Ammo_127x108",
				"Epinephrine", "Epinephrine", "Morphine", "Morphine", "PainKillerTablets"
			});

		// HH_M82_White
		PlayerWeapon HH_M82_White = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"HH_M82_White",
			"HH_Mag_M82_10Rnd",
			{"HuntingOptic"},

			// Второе оружие, тип магазина и обвесы
			"",
			"",
			{},

			// Содержимое карманов
			{
				"HH_Mag_M82_10Rnd", "HH_Mag_M82_10Rnd", "HH_Mag_M82_10Rnd", "HH_Mag_M82_10Rnd", "HH_Mag_M82_10Rnd", "HH_Mag_M82_10Rnd",
				"BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing",
				"HH_Ammo_127x99", "HH_Ammo_127x99", "HH_Ammo_127x99", "HH_Ammo_127x99",  "HH_Ammo_127x99",  "HH_Ammo_127x99",
				"Epinephrine", "Epinephrine", "Morphine", "Morphine",
				 "PainKillerTablets", "HH_LongRangeOptics_x24_Black"
			});

		// HH_VSSK
		PlayerWeapon HH_VSSK = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"HH_VSSK",
			"HH_Mag_VSSK_5Rnd",
			{"HuntingOptic"},

			// второе оружие, тип магазина и обвесы
			"",
			"",
			{},

			// Содержимое карманов
			{
				"HH_Mag_VSSK_5Rnd", "HH_Mag_VSSK_5Rnd", "HH_Mag_VSSK_5Rnd", "HH_Mag_VSSK_5Rnd", "HH_Mag_VSSK_5Rnd", "HH_Mag_VSSK_5Rnd",
				"BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing",
				"HH_Ammo_127x99", "HH_Ammo_127x99", "HH_Ammo_127x99", "HH_Ammo_127x99",  "HH_Ammo_127x99",  "HH_Ammo_127x99",
				"Epinephrine", "Epinephrine", "Morphine", "Morphine",
				 "PainKillerTablets", "RGD5Grenade", "M67Grenade", "HH_LongRangeOptics_x24_Black"
			});

		// HH_AugA1
		PlayerWeapon HH_AugA1 = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"HH_AugA1",
			"HH_Mag_PMAG_D_60Rnd",
			{""},

			// второе оружие, тип магазина и обвесы
			"HH_Glock18c",
			"HH_Mag_Glock18c_50Rnd",
			{"HH_Glock18C_Hndgrd_Black", "FNP45_MRDSOptic", "PistolSuppressor"},

			// Содержимое карманов
			{
				"HH_Mag_PMAG_D_60Rnd", "HH_Mag_PMAG_D_60Rnd", "HH_Mag_PMAG_D_60Rnd", "HH_Mag_PMAG_D_60Rnd", "HH_Mag_PMAG_D_60Rnd", "HH_Mag_PMAG_D_60Rnd",
				"Ammo_556x45", "Ammo_556x45", "Ammo_556x45", "Ammo_556x45",  "Ammo_556x45",  "Ammo_556x45",
				"HH_Mag_Glock18c_50Rnd", "HH_Mag_Glock18c_50Rnd", "HH_Mag_Glock18c_50Rnd"
				"HH_Bandage", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", 
				"Epinephrine", "Epinephrine", "PainKillerTablets", "PainKillerTablets", "TetracyclineAntibiotics", "TetracyclineAntibiotics", "Morphine", "Morphine",
				 "Vodka"
			});

		// HH_Famas
		PlayerWeapon HH_Famas = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"HH_Famas",
			"Mag_STANAGCoupled_30Rnd",
			{"ACOGOptic", "M4_Suppressor"},

			// второе оружие, тип магазина и обвесы
			"HH_Glock18c",
			"HH_Mag_Glock18c_50Rnd",
			{"HH_Glock18C_Hndgrd_Black", "FNP45_MRDSOptic", "PistolSuppressor"},

			// Содержимое карманов
			{
				"Mag_STANAGCoupled_30Rnd", "Mag_STANAG_30Rnd", "Mag_STANAG_30Rnd", "Mag_STANAG_30Rnd", "Mag_STANAG_30Rnd",
				"Ammo_556x45", "Ammo_556x45", "Ammo_556x45", "Ammo_556x45",  "Ammo_556x45",  "Ammo_556x45",
				"HH_Mag_Glock18c_50Rnd", "HH_Mag_Glock18c_50Rnd", "HH_Mag_Glock18c_50Rnd"
				"BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing",
				"Epinephrine", "Epinephrine", "PainKillerTablets", "PainKillerTablets", "TetracyclineAntibiotics", "TetracyclineAntibiotics", "Morphine", "Morphine",
				 "Vodka"
			});

		// HH_AWM
		PlayerWeapon HH_AWM = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"HH_AWM",
			"HH_Mag_AWM_10Rnd",
			{"HuntingOptic", "GhillieAtt_Woodland"},

			// второе оружие, тип магазина и обвесы
			"HH_Glock18c",
			"HH_Mag_Glock18c_50Rnd",
			{"HH_Glock18C_Hndgrd_Black", "FNP45_MRDSOptic", "PistolSuppressor"},

			// Содержимое карманов
			{
				"HH_Mag_AWM_10Rnd", "HH_Mag_AWM_10Rnd", "HH_Mag_AWM_10Rnd", "HH_Mag_AWM_10Rnd", "HH_Mag_AWM_10Rnd", "HH_Mag_AWM_10Rnd",
				"HH_Ammo_338",  "HH_Ammo_338",  "HH_Ammo_338",
				"HH_Mag_Glock18c_50Rnd", "HH_Mag_Glock18c_50Rnd",
				"HH_Bandage",  "HH_Bandage", "HH_Bandage", "HH_Bandage", "BandageDressing", "BandageDressing",
				"Epinephrine", "Epinephrine", "PainKillerTablets", "PainKillerTablets", "TetracyclineAntibiotics", "TetracyclineAntibiotics", "Morphine", "Morphine", "HH_LongRangeOptics_x24_Black"
			});

		// HH_SV98
		PlayerWeapon HH_SV98 = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"HH_SV98",
			"HH_Mag_SV98_10Rnd",
			{"HuntingOptic", "GhillieAtt_Woodland"},

			// второе оружие, тип магазина и обвесы
			"HH_Glock18c",
			"HH_Mag_Glock18c_50Rnd",
			{"HH_Glock18C_Hndgrd_Black", "FNP45_MRDSOptic", "PistolSuppressor"},

			// Содержимое карманов
			{
				"HH_Mag_SV98_10Rnd", "HH_Mag_SV98_10Rnd", "HH_Mag_SV98_10Rnd", "HH_Mag_SV98_10Rnd", "HH_Mag_SV98_10Rnd", "HH_Mag_SV98_10Rnd",
				"HH_Ammo_338",  "HH_Ammo_338",  "HH_Ammo_338",
				"HH_Mag_Glock18c_50Rnd", "HH_Mag_Glock18c_50Rnd",
				"HH_Bandage",  "HH_Bandage", "HH_Bandage", "HH_Bandage", "BandageDressing", "BandageDressing",
				"Epinephrine", "Epinephrine", "PainKillerTablets", "PainKillerTablets", "TetracyclineAntibiotics", "TetracyclineAntibiotics", "Morphine", "Morphine", "HH_LongRangeOptics_x24_Black"
			});

		// HH_M200_Black
		PlayerWeapon HH_M200_Black = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"HH_M200_Black",
			"HH_Mag_M200_7Rnd",
			{"HuntingOptic", "GhillieAtt_Woodland"},

			// второе оружие, тип магазина и обвесы
			"HH_Glock18c",
			"HH_Mag_Glock18c_50Rnd",
			{"HH_Glock18C_Hndgrd_Black", "FNP45_MRDSOptic", "PistolSuppressor"},

			// Содержимое карманов
			{
				"HH_Mag_M200_7Rnd", "HH_Mag_M200_7Rnd", "HH_Mag_M200_7Rnd", "HH_Mag_M200_7Rnd", "HH_Mag_M200_7Rnd", "HH_Mag_M200_7Rnd",
				"HH_Ammo_408", "HH_Ammo_408", "HH_Ammo_408", "HH_Ammo_408", "HH_Ammo_408",  "HH_Ammo_408",  "HH_Ammo_408",
				"HH_Mag_Glock18c_50Rnd", "HH_Mag_Glock18c_50Rnd",
				"HH_Bandage",  "HH_Bandage", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing",
				"Epinephrine", "Epinephrine", "PainKillerTablets", "PainKillerTablets", "TetracyclineAntibiotics", "TetracyclineAntibiotics", "Morphine", "Morphine", "HH_LongRangeOptics_x24_Black"
			});

		// HH_ASH12
		PlayerWeapon HH_ASH12 = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"HH_ASH12",
			"HH_Mag_ASH12_10Rnd",
			{"M68Optic"},

			// второе оружие, тип магазина и обвесы
			"HH_Glock18c",
			"HH_Mag_Glock18c_50Rnd",
			{"HH_Glock18C_Hndgrd_Black", "FNP45_MRDSOptic", "PistolSuppressor"},

			// Содержимое карманов
			{
				"HH_Mag_ASH12_10Rnd", "HH_Mag_ASH12_10Rnd", "HH_Mag_ASH12_10Rnd", "HH_Mag_ASH12_10Rnd", "HH_Mag_ASH12_10Rnd", "HH_Mag_ASH12_10Rnd",
				"HH_Ammo_408", "HH_Ammo_408", "HH_Ammo_408", "HH_Ammo_408", "HH_Ammo_408",  "HH_Ammo_408",  "HH_Ammo_408",
				"HH_Mag_Glock18c_50Rnd", "HH_Mag_Glock18c_50Rnd",
				"HH_Bandage",  "HH_Bandage", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing",
				"Epinephrine", "Epinephrine", "PainKillerTablets", "PainKillerTablets", "TetracyclineAntibiotics", "TetracyclineAntibiotics", "Morphine", "Morphine", "ACOGOptic",
			});

		// HH_STG44
		PlayerWeapon HH_STG44 = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"HH_STG44",
			"HH_Mag_STG44_30Rnd",
			{},

			// второе оружие, тип магазина и обвесы
			"HH_Glock18c",
			"HH_Mag_Glock18c_50Rnd",
			{"HH_Glock18C_Hndgrd_Black", "FNP45_MRDSOptic", "PistolSuppressor"},

			// Содержимое карманов
			{
				"HH_Mag_STG44_30Rnd", "HH_Mag_STG44_30Rnd", "HH_Mag_STG44_30Rnd", "HH_Mag_STG44_30Rnd", "HH_Mag_STG44_30Rnd", "HH_Mag_STG44_30Rnd",
				"HH_Ammo_792x33", "HH_Ammo_792x33", "HH_Ammo_792x33", "HH_Ammo_792x33", "HH_Ammo_792x33",  "HH_Ammo_792x33",  "HH_Ammo_792x33",
				"HH_Mag_Glock18c_50Rnd", "HH_Mag_Glock18c_50Rnd",
				"HH_Bandage",  "HH_Bandage", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing",
				"Epinephrine", "Epinephrine", "PainKillerTablets", "PainKillerTablets", "TetracyclineAntibiotics", "TetracyclineAntibiotics", "Morphine", "Morphine", "HH_LongRangeOptics_x24_Black",
			});

		// HH_PPSH
		PlayerWeapon HH_PPSH = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"HH_PPSH",
			"HH_Mag_PPSH_Drum",
			{},

			// второе оружие, тип магазина и обвесы
			"",
			"",
			{},

			// Содержимое карманов
			{
				"HH_Mag_PPSH_Drum", "HH_Mag_PPSH_Drum", "HH_Mag_PPSH_Drum", "HH_Mag_PPSH_Drum", "HH_Mag_PPSH_Drum", "HH_Mag_PPSH_Drum",
				"HH_Bandage",  "HH_Bandage", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing",
				"Epinephrine", "Epinephrine", "PainKillerTablets", "PainKillerTablets", "TetracyclineAntibiotics", "TetracyclineAntibiotics", "Morphine", "Morphine", "HH_LongRangeOptics_x24_Black",
			});

		// SVD_Wood
		PlayerWeapon SVD_Wood = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"SVD_Wood",
			"Mag_SVD_10Rnd",
			{"PSO11Optic"},

			// второе оружие, тип магазина и обвесы
			"",
			"",
			{},

			// Содержимое карманов
			{
				"Mag_SVD_10Rnd", "Mag_SVD_10Rnd", "Mag_SVD_10Rnd", "Mag_SVD_10Rnd", "Mag_SVD_10Rnd", "Mag_SVD_10Rnd",
				"Ammo_762x54Tracer", "Ammo_762x54Tracer", "Ammo_762x54Tracer", "Ammo_762x54Tracer", "Ammo_762x54Tracer",  "Ammo_762x54Tracer",  "Ammo_762x54Tracer",
				"HH_Bandage",  "HH_Bandage", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing",
				"Epinephrine", "Epinephrine", "PainKillerTablets", "PainKillerTablets", "TetracyclineAntibiotics", "TetracyclineAntibiotics", "Morphine", "Morphine", "HH_MTK83Optic", "HuntingOptic",
			});

		// Mosin9130
		PlayerWeapon Mosin9130 = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"Mosin9130",
			"",
			{"PUScopeOptic"},

			// второе оружие, тип магазина и обвесы
			"",
			"",
			{},

			// Содержимое карманов
			{
				"Ammo_762x54Tracer", "Ammo_762x54Tracer", "Ammo_762x54Tracer", "Ammo_762x54Tracer", "Ammo_762x54Tracer",  "Ammo_762x54Tracer",  "Ammo_762x54Tracer",
				"HH_Bandage",  "HH_Bandage", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing",
				"Epinephrine", "Epinephrine", "PainKillerTablets", "PainKillerTablets", "TetracyclineAntibiotics", "TetracyclineAntibiotics", "Morphine", "Morphine", "HH_LongRangeOptics_x24_Black",
			});

		// HH_SVT40
		PlayerWeapon HH_SVT40 = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"HH_SVT40",
			"HH_Mag_SVT40_10Rnd",
			{"HH_PBScopeOpticSVT", "HH_SVT40_Bayonet"},

			// второе оружие, тип магазина и обвесы
			"",
			"",
			{},

			// Содержимое карманов
			{
				"HH_Mag_SVT40_10Rnd", "HH_Mag_SVT40_10Rnd", "HH_Mag_SVT40_10Rnd", "HH_Mag_SVT40_10Rnd", "HH_Mag_SVT40_10Rnd", "HH_Mag_SVT40_10Rnd",
				"Ammo_762x54Tracer", "Ammo_762x54Tracer", "Ammo_762x54Tracer", "Ammo_762x54Tracer", "Ammo_762x54Tracer",  "Ammo_762x54Tracer",  "Ammo_762x54Tracer",
				"HH_Bandage",  "HH_Bandage", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing",
				"Epinephrine", "Epinephrine", "PainKillerTablets", "PainKillerTablets", "TetracyclineAntibiotics", "TetracyclineAntibiotics", "Morphine", "Morphine", "HH_PUScopeOpticSVT",
			});


		// Winchester70
		PlayerWeapon Winchester70 = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"Winchester70",
			"",
			{"HuntingOptic", "GhillieAtt_Woodland"},

			// второе оружие, тип магазина и обвесы
			"HH_Glock18c",
			"HH_Mag_Glock18c_50Rnd",
			{"HH_Glock18C_Hndgrd_Black", "FNP45_MRDSOptic", "PistolSuppressor"},

			// Содержимое карманов
			{
				"Ammo_308WinTracer",  "Ammo_308WinTracer",  "Ammo_308WinTracer", "Ammo_308WinTracer", "Ammo_308WinTracer",
				"HH_Mag_Glock18c_50Rnd", "HH_Mag_Glock18c_50Rnd",
				"HH_Bandage",  "HH_Bandage", "HH_Bandage", "HH_Bandage", "BandageDressing", "BandageDressing",
				"Epinephrine", "Epinephrine", "PainKillerTablets", "PainKillerTablets", "TetracyclineAntibiotics", "TetracyclineAntibiotics", "Morphine", "Morphine", "HH_LongRangeOptics_x24_Black"
			});

		// B95
		PlayerWeapon B95 = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"B95",
			"",
			{"HuntingOptic"},

			// второе оружие, тип магазина и обвесы
			"HH_Glock18c",
			"HH_Mag_Glock18c_50Rnd",
			{"HH_Glock18C_Hndgrd_Black", "FNP45_MRDSOptic", "PistolSuppressor"},

			// Содержимое карманов
			{
				"Ammo_308WinTracer",  "Ammo_308WinTracer",  "Ammo_308WinTracer", "Ammo_308WinTracer", "Ammo_308WinTracer",
				"HH_Mag_Glock18c_50Rnd", "HH_Mag_Glock18c_50Rnd",
				"HH_Bandage",  "HH_Bandage", "HH_Bandage", "HH_Bandage", "BandageDressing", "BandageDressing",
				"Epinephrine", "Epinephrine", "PainKillerTablets", "PainKillerTablets", "TetracyclineAntibiotics", "TetracyclineAntibiotics", "Morphine", "Morphine", "HH_LongRangeOptics_x24_Black"
			});

		// SKS
		PlayerWeapon SKS = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"SKS",
			"",
			{"PUScopeOptic"},

			// второе оружие, тип магазина и обвесы
			"",
			"",
			{},

			// Содержимое карманов
			{
				"Ammo_762x39Tracer", "Ammo_762x39Tracer", "Ammo_762x39Tracer", "Ammo_762x39Tracer", "Ammo_762x39Tracer",  "Ammo_762x39Tracer",  "Ammo_762x39Tracer",
				"HH_Bandage",  "HH_Bandage", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing",
				"Epinephrine", "Epinephrine", "PainKillerTablets", "PainKillerTablets", "TetracyclineAntibiotics", "TetracyclineAntibiotics", "Morphine", "Morphine", "HH_LongRangeOptics_x24_Black",
			});


		// AK101_Black
		PlayerWeapon AK101_Black = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"AK101_Black",
			"HH_Mag_AK101_30Rnd",
			{"AK_WoodHndgrd_Black", "AK_WoodBttstck_Green", "KobraOptic"},

			// второе оружие, тип магазина и обвесы
			"HH_Glock18c",
			"HH_Mag_Glock18c_50Rnd",
			{"HH_Glock18C_Hndgrd_Black", "FNP45_MRDSOptic", "PistolSuppressor"},

			// Содержимое карманов
			{
				"HH_Mag_AK101_30Rnd", "HH_Mag_AK101_30Rnd", "HH_Mag_AK101_30Rnd", "HH_Mag_AK101_30Rnd", "HH_Mag_AK101_30Rnd", "HH_Mag_AK101_30Rnd",
				"Ammo_556x45", "Ammo_556x45", "Ammo_556x45", "Ammo_556x45",  "Ammo_556x45",  "Ammo_556x45",
				"HH_Mag_Glock18c_50Rnd", "HH_Mag_Glock18c_50Rnd", "HH_Mag_Glock18c_50Rnd"
				"HH_Bandage", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", 
				"Epinephrine", "Epinephrine", "PainKillerTablets", "PainKillerTablets", "TetracyclineAntibiotics", "TetracyclineAntibiotics", "Morphine", "Morphine"
			});

		// AK74
		PlayerWeapon AK74 = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"AK74",
			"Mag_AK74_30Rnd",
			{"AK74_Hndgrd", "AK74_WoodBttstck", "KobraOptic"},

			// второе оружие, тип магазина и обвесы
			"HH_Glock18c",
			"HH_Mag_Glock18c_50Rnd",
			{"HH_Glock18C_Hndgrd_Black", "FNP45_MRDSOptic", "PistolSuppressor"},

			// Содержимое карманов
			{
				"Mag_AK74_30Rnd", "Mag_AK74_30Rnd", "Mag_AK74_30Rnd", "Mag_AK74_30Rnd", "Mag_AK74_30Rnd", "Mag_AK74_30Rnd",
				"Ammo_545x39", "Ammo_545x39", "Ammo_545x39", "Ammo_545x39",  "Ammo_545x39",  "Ammo_545x39",
				"HH_Mag_Glock18c_50Rnd", "HH_Mag_Glock18c_50Rnd", "HH_Mag_Glock18c_50Rnd"
				"HH_Bandage", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", 
				"Epinephrine", "Epinephrine", "PainKillerTablets", "PainKillerTablets", "TetracyclineAntibiotics", "TetracyclineAntibiotics", "Morphine", "Morphine"
			});

		// HH_P90
		PlayerWeapon HH_P90 = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"HH_P90",
			"HH_Mag_P90_50Rnd",
			{},

			// второе оружие, тип магазина и обвесы
			"HH_Glock18c",
			"HH_Mag_Glock18c_50Rnd",
			{"HH_Glock18C_Hndgrd_Black", "FNP45_MRDSOptic", "PistolSuppressor"},

			// Содержимое карманов
			{
				"HH_Mag_P90_50Rnd", "HH_Mag_P90_50Rnd", "HH_Mag_P90_50Rnd", "HH_Mag_P90_50Rnd", "HH_Mag_P90_50Rnd", "HH_Mag_P90_50Rnd",
				"HH_Mag_Glock18c_50Rnd", "HH_Mag_Glock18c_50Rnd", "HH_Mag_Glock18c_50Rnd"
				"HH_Bandage", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", 
				"Epinephrine", "Epinephrine", "PainKillerTablets", "PainKillerTablets", "TetracyclineAntibiotics", "TetracyclineAntibiotics", "Morphine", "Morphine"
			});

		// Saiga_Wood
		PlayerWeapon Saiga_Wood = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"Saiga_Wood",
			"Mag_Saiga_Drum20Rnd_Green",
			{},

			// второе оружие, тип магазина и обвесы
			"HH_Glock18c",
			"HH_Mag_Glock18c_50Rnd",
			{"HH_Glock18C_Hndgrd_Black", "FNP45_MRDSOptic", "PistolSuppressor"},

			// Содержимое карманов
			{
				"Mag_Saiga_Drum20Rnd_Green", "Mag_Saiga_Drum20Rnd_Green", "Mag_Saiga_Drum20Rnd_Green", "Mag_Saiga_Drum20Rnd_Green", "Mag_Saiga_Drum20Rnd_Green", "Mag_Saiga_Drum20Rnd_Green",
				"HH_Mag_Glock18c_50Rnd", "HH_Mag_Glock18c_50Rnd", "HH_Mag_Glock18c_50Rnd"
				"HH_Bandage", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", 
				"Epinephrine", "Epinephrine", "PainKillerTablets", "PainKillerTablets", "TetracyclineAntibiotics", "TetracyclineAntibiotics", "Morphine", "Morphine"
			});

		// HH_M1928A1
		PlayerWeapon HH_M1928A1 = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"HH_M1928A1",
			"HH_Mag_M1928A1_Drum",
			{},

			// второе оружие, тип магазина и обвесы
			"HH_Glock18c",
			"HH_Mag_Glock18c_50Rnd",
			{"HH_Glock18C_Hndgrd_Black", "FNP45_MRDSOptic", "PistolSuppressor"},

			// Содержимое карманов
			{
				"HH_Mag_M1928A1_Drum", "HH_Mag_M1928A1_Drum", "HH_Mag_M1928A1_Drum", "HH_Mag_M1928A1_Drum", "HH_Mag_M1928A1_Drum", "HH_Mag_M1928A1_Drum",
				"HH_Mag_Glock18c_50Rnd", "HH_Mag_Glock18c_50Rnd", "HH_Mag_Glock18c_50Rnd"
				"HH_Bandage", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", 
				"Epinephrine", "Epinephrine", "PainKillerTablets", "PainKillerTablets", "TetracyclineAntibiotics", "TetracyclineAntibiotics", "Morphine", "Morphine"
			});

		// HH_M24_Wood
		PlayerWeapon HH_M24_Wood = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"HH_M24_Wood",
			"",
			{"HuntingOptic"},

			// второе оружие, тип магазина и обвесы
			"HH_Glock18c",
			"HH_Mag_Glock18c_50Rnd",
			{"HH_Glock18C_Hndgrd_Black", "FNP45_MRDSOptic", "PistolSuppressor"},

			// Содержимое карманов
			{
				"HH_Mag_M24_10Rnd", "HH_Mag_M24_10Rnd", "HH_Mag_M24_10Rnd", "HH_Mag_M24_10Rnd", "HH_Mag_M24_10Rnd",
				"Ammo_308Win",  "Ammo_308Win",  "Ammo_308Win", "Ammo_308Win", "Ammo_308Win",
				"HH_Mag_Glock18c_50Rnd", "HH_Mag_Glock18c_50Rnd",
				"HH_Bandage",  "HH_Bandage", "HH_Bandage", "HH_Bandage", "BandageDressing", "BandageDressing",
				"Epinephrine", "Epinephrine", "PainKillerTablets", "PainKillerTablets", "TetracyclineAntibiotics", "TetracyclineAntibiotics", "Morphine", "Morphine", "HH_LongRangeOptics_x24_Black"
			});

		// HH_K98
		PlayerWeapon HH_K98 = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"HH_K98",
			"",
			{"HH_K98Optic", "HH_K98_Bayonet"},

			// второе оружие, тип магазина и обвесы
			"HH_Glock18c",
			"HH_Mag_Glock18c_50Rnd",
			{"HH_Glock18C_Hndgrd_Black", "FNP45_MRDSOptic", "PistolSuppressor"},

			// Содержимое карманов
			{
				"HH_Ammo_792x57",  "HH_Ammo_792x57",  "HH_Ammo_792x57", "HH_Ammo_792x57", "HH_Ammo_792x57",
				"HH_Mag_Glock18c_50Rnd", "HH_Mag_Glock18c_50Rnd",
				"HH_Bandage",  "HH_Bandage", "HH_Bandage", "HH_Bandage", "BandageDressing", "BandageDressing",
				"Epinephrine", "Epinephrine", "PainKillerTablets", "PainKillerTablets", "TetracyclineAntibiotics", "TetracyclineAntibiotics", "Morphine", "Morphine", "HH_LongRangeOptics_x24_Black"
			});

		// HH_M14Long
		PlayerWeapon HH_M14Long = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"HH_M14Long",
			"HH_Mag_M14Long_20Rnd",
			{"ACOGOptic"},

			// второе оружие, тип магазина и обвесы
			"HH_Glock18c",
			"HH_Mag_Glock18c_50Rnd",
			{"HH_Glock18C_Hndgrd_Black", "FNP45_MRDSOptic", "PistolSuppressor"},

			// Содержимое карманов
			{
				"HH_Mag_M14Long_20Rnd", "HH_Mag_M14Long_20Rnd", "HH_Mag_M14Long_20Rnd",  
				"Ammo_308Win",  "Ammo_308Win",  "Ammo_308Win", "Ammo_308Win", "Ammo_308Win",
				"HH_Mag_Glock18c_50Rnd", "HH_Mag_Glock18c_50Rnd",
				"HH_Bandage",  "HH_Bandage", "HH_Bandage", "HH_Bandage", "BandageDressing", "BandageDressing",
				"Epinephrine", "Epinephrine", "PainKillerTablets", "PainKillerTablets", "TetracyclineAntibiotics", "TetracyclineAntibiotics", "Morphine", "Morphine",
			});

		// HH_RPK16_Black
		PlayerWeapon HH_RPK16_Black = new PlayerWeapon(
			// оружие, тип магазина и обвесы
			"HH_RPK16_Black",
			"HH_Mag_RPK16_Black_Drum60Rnd",
			{"PUScopeOptic"},

			// второе оружие, тип магазина и обвесы
			"",
			"",
			{},

			// Содержимое карманов
			{
				"HH_Mag_RPK16_Black_Drum60Rnd", "HH_Mag_RPK16_Black_Drum60Rnd", "HH_Mag_RPK16_Black_Drum60Rnd",  
				"Ammo_762x39Tracer", "Ammo_762x39Tracer", "Ammo_762x39Tracer", "Ammo_762x39Tracer", "Ammo_762x39Tracer",  "Ammo_762x39Tracer",  "Ammo_762x39Tracer",
				"HH_Bandage",  "HH_Bandage", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing", "BandageDressing",
				"Epinephrine", "Epinephrine", "PainKillerTablets", "PainKillerTablets", "TetracyclineAntibiotics", "TetracyclineAntibiotics", "Morphine", "Morphine", "HH_LongRangeOptics_x24_Black",
			});


		// тяжелые стволы
		this.heavyWeapons.Insert(HH_AR15Beowulf_Tan);
		this.heavyWeapons.Insert(HH_FalMod);
		this.heavyWeapons.Insert(HH_FalMod);
		this.heavyWeapons.Insert(HH_FalMod);
		this.heavyWeapons.Insert(HH_FalMod);
		this.heavyWeapons.Insert(FAL_Wood);
		this.heavyWeapons.Insert(FAL_Wood);
		this.heavyWeapons.Insert(FAL_Wood);
		this.heavyWeapons.Insert(FAL_Wood);
		this.heavyWeapons.Insert(HH_DVL10);
		this.heavyWeapons.Insert(HH_DVL10);
		this.heavyWeapons.Insert(HH_DVL10);
		this.heavyWeapons.Insert(HH_PKPs);
		this.heavyWeapons.Insert(HH_PKM);
		this.heavyWeapons.Insert(HH_PKM);
		this.heavyWeapons.Insert(HH_PKP);
		this.heavyWeapons.Insert(HH_OSV96_Black);
		this.heavyWeapons.Insert(HH_M82_White);
		this.heavyWeapons.Insert(HH_VSSK);
		this.heavyWeapons.Insert(HH_AWM);
		this.heavyWeapons.Insert(HH_AWM);
		this.heavyWeapons.Insert(HH_AWM);
		this.heavyWeapons.Insert(HH_SV98);
		this.heavyWeapons.Insert(HH_SV98);
		this.heavyWeapons.Insert(HH_SV98);
		this.heavyWeapons.Insert(HH_M200_Black);
		this.heavyWeapons.Insert(HH_ASH12);


		// снйперские стволы
		this.snipingWeapons.Insert(HH_M110_Tan);
		this.snipingWeapons.Insert(HH_DVL10);
		this.snipingWeapons.Insert(HH_DVL10);
		this.snipingWeapons.Insert(HH_DVL10);
		this.snipingWeapons.Insert(HH_OSV96_Black);
		this.snipingWeapons.Insert(HH_M82_White);
		this.snipingWeapons.Insert(HH_VSSK);
		this.snipingWeapons.Insert(HH_AWM);
		this.snipingWeapons.Insert(HH_AWM);
		this.snipingWeapons.Insert(HH_AWM);
		this.snipingWeapons.Insert(HH_SV98);
		this.snipingWeapons.Insert(HH_M200_Black);
		this.snipingWeapons.Insert(SVD_Wood);
		this.snipingWeapons.Insert(SVD_Wood);
		this.snipingWeapons.Insert(SVD_Wood);
		this.snipingWeapons.Insert(Mosin9130);
		this.snipingWeapons.Insert(HH_SVT40);
		this.snipingWeapons.Insert(Winchester70);
		this.snipingWeapons.Insert(Winchester70);
		this.snipingWeapons.Insert(B95);
		this.snipingWeapons.Insert(SKS);
		this.snipingWeapons.Insert(HH_M24_Wood);
		this.snipingWeapons.Insert(HH_K98);
		this.snipingWeapons.Insert(HH_M14Long);
		this.snipingWeapons.Insert(HH_M14Long);


		// легкие стволы
		this.lightWeapons.Insert(HH_AR15_Used);
		this.lightWeapons.Insert(HH_AR15_Used);
		this.lightWeapons.Insert(HH_HKG36);
		this.lightWeapons.Insert(HH_AugA1);
		this.lightWeapons.Insert(HH_Famas);
		this.lightWeapons.Insert(HH_STG44);
		this.lightWeapons.Insert(HH_PPSH);
		this.lightWeapons.Insert(Mosin9130);
		this.lightWeapons.Insert(Winchester70);
		this.lightWeapons.Insert(B95);
		this.lightWeapons.Insert(SKS);
		this.lightWeapons.Insert(HH_M24_Wood);
		this.lightWeapons.Insert(HH_K98);
		this.lightWeapons.Insert(HH_M14Long);
		this.lightWeapons.Insert(AK101_Black);
		this.lightWeapons.Insert(AK101_Black);
		this.lightWeapons.Insert(AK74);
		this.lightWeapons.Insert(AK74);
		this.lightWeapons.Insert(HH_P90);
		this.lightWeapons.Insert(Saiga_Wood);
		this.lightWeapons.Insert(HH_M1928A1);
		this.lightWeapons.Insert(HH_RPK16_Black);
		



		PlayerClothesVip DadyaFedor = new PlayerClothesVip(
			// Стим айди
			"76561198077282054",
			// одежда
			{"HH_TacticalShirt_V", "HH_Pants_kneepads_black", "MilitaryBoots_Redpunk", "TacticalGloves_Black"}, 
		);

		this.clothesVip.Insert(DadyaFedor);
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



class PlayerClothes
{
	string Helmet;
	string Vest;
	ref array<string> HelmetAttachments		= new array<string>;
	ref array<string> VestAttachments 		= new array<string>;
	ref array<string> Clothes				= new array<string>;

	void PlayerClothes(ref array<string> cl, string hel, ref array<string> helAtt, string vest, ref array<string> vestAtt) {
		this.Clothes = cl;

		this.Helmet = hel;
		this.HelmetAttachments = helAtt;
		this.Vest = vest;
		this.VestAttachments = vestAtt;
	}
}


class PlayerWeapon
{
	string Weapon;
	string Weapon2;
	string MagType;
	string MagType2;
	ref array<string> WeaponAttachments 	= new array<string>;
	ref array<string> WeaponAttachments2 	= new array<string>;
	ref array<string> Equipment 			= new array<string>;

	void PlayerWeapon(string wp, string magType, ref array<string> wpatt, string wp2, string magType2, ref array<string> wpatt2, ref array<string> eq) {
		this.Weapon = wp;
		this.WeaponAttachments = wpatt;
		this.MagType = magType;

		this.Weapon2 = wp2;
		this.WeaponAttachments2 = wpatt2;
		this.MagType2 = magType2;

		this.Equipment = eq;
	}
}



class PlayerClothesVip
{
	string steamId64 = "";
	ref array<string> Clothes = new array<string>;

	void PlayerClothesVip ( string steam, ref array<string> cl ) {
		this.steamId64 = steam;
		this.Clothes = cl;
	}
}