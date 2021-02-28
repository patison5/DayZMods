class EarPlugs extends PluginBase 
{
	void decreaseVolume() {
		float f_Volume 			= GetGame().GetSoundScene().GetSoundVolume() - 0.1;
		float f_SpeechExVolume 	= GetGame().GetSoundScene().GetSoundVolume() - 0.1;
		float f_MusicVolume 	= GetGame().GetSoundScene().GetSoundVolume() - 0.1;
		float f_VOIPVolume 		= GetGame().GetSoundScene().GetSoundVolume() - 0.1;
		float f_RadioVolume 	= GetGame().GetSoundScene().GetSoundVolume() - 0.1;

		if (f_Volume < 0) f_Volume = 0;
		if (f_SpeechExVolume < 0) f_SpeechExVolume = 0;
		if (f_MusicVolume < 0) f_MusicVolume = 0;
		if (f_VOIPVolume < 0) f_VOIPVolume = 0;
		if (f_RadioVolume < 0) f_RadioVolume = 0;

		GetGame().GetSoundScene().SetSoundVolume(f_Volume, 0);
		GetGame().GetSoundScene().SetSpeechExVolume(f_SpeechExVolume, 0);
		GetGame().GetSoundScene().SetMusicVolume(f_MusicVolume, 0);
		GetGame().GetSoundScene().SetVOIPVolume(f_VOIPVolume, 0);
		GetGame().GetSoundScene().SetRadioVolume(f_RadioVolume, 0);


		Print("-----------------");
		Print(g_Game.m_volume_sound);
		Print(GetGame().GetSoundScene().GetSoundVolume())
		Print("-----------------");
	}

	void riseVolume () {
		float f_Volume 			= GetGame().GetSoundScene().GetSoundVolume() + 0.1;
		float f_SpeechExVolume 	= GetGame().GetSoundScene().GetSoundVolume() + 0.1;
		float f_MusicVolume 	= GetGame().GetSoundScene().GetSoundVolume() + 0.1;
		float f_VOIPVolume 		= GetGame().GetSoundScene().GetSoundVolume() + 0.1;
		float f_RadioVolume 	= GetGame().GetSoundScene().GetSoundVolume() + 0.1;

		if (f_Volume > 1) f_Volume = 1;
		if (f_SpeechExVolume > 1) f_SpeechExVolume = 1;
		if (f_MusicVolume > 1) f_MusicVolume = 1;
		if (f_VOIPVolume > 1) f_VOIPVolume = 1;
		if (f_RadioVolume > 1) f_RadioVolume = 1;

		GetGame().GetSoundScene().SetSoundVolume(f_Volume, 0);
		GetGame().GetSoundScene().SetSpeechExVolume(f_SpeechExVolume, 0);
		GetGame().GetSoundScene().SetMusicVolume(f_MusicVolume, 0);
		GetGame().GetSoundScene().SetVOIPVolume(f_VOIPVolume, 0);
		GetGame().GetSoundScene().SetRadioVolume(f_RadioVolume, 0);

		Print("######################");
		Print(g_Game.m_volume_sound);
		Print(GetGame().GetSoundScene().GetSoundVolume())
		Print("######################");
	}
}

