class SetupPlayerOptions 
{
	ref array<ref PlayerSet> PlayerSetups = new array<ref PlayerSet>;
	
	void InitPlayerSetups() {
		PlayerSet set1 = new PlayerSet(
			{"M65Jacket_Tan", "CargoPants_Green", "TortillaBag", "Sneakers_White", "PlateCarrierVest", "AviatorGlasses"}, 
			"AK101",
			{"AK74_WoodBttstck","AK74_Hndgrd"},
			{"Mag_AK101_30Rnd", "Mag_AK101_30Rnd", "PainKillerTablets", "Vodka"});

		PlayerSet set2 = new PlayerSet(
			{"M65Jacket_Black", "CargoPants_Black", "Sneakers_Red", "AviatorGlasses"}, 
			"M4A1",
			{"M4_OEBttstck", "M4_CarryHandleOptic", "M4_PlasticHndgrd"},
			{"Mag_STANAG_30Rnd", "Mag_STANAGCoupled_30Rnd", "PainKillerTablets", "Vodka"});
		
		PlayerSet set3 = new PlayerSet(
			{"M65Jacket_Black", "CargoPants_Black", "GhillieTop_Tan", "GhillieHood_Tan", "Sneakers_White", "PlateCarrierVest", "AviatorGlasses"}, 
			"SVD",
			{"PSO1Optic", "PaintGhillieAttGreen"},
			{"Mag_SVD_10Rnd", "Mag_SVD_10Rnd", "PainKillerTablets", "Vodka"});

		this.PlayerSetups.Insert(set1);
		this.PlayerSetups.Insert(set2);
		this.PlayerSetups.Insert(set3);
	}
}

class PlayerSet
{
	string Weapon;
	ref array<string> Clothes				= new array<string>;
	ref array<string> WeaponAttachments 	= new array<string>;
	ref array<string> Equipment 			= new array<string>;

	void PlayerSet(ref array<string> cl, string wp, ref array<string> watch, ref array<string> eq) {
		this.Clothes = cl;
		this.Weapon = wp;
		this.WeaponAttachments = watch;
		this.Equipment = eq;
	}
}


		
