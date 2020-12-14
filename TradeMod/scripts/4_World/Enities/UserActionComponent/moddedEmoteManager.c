modded class EmoteManager
{
	PluginPlayersTop m_playerStatPlugin;
	void EmoteManager(PlayerBase player)
	{
		m_playerStatPlugin = PluginPlayersTop.Cast(GetPlugin(PluginPlayersTop));
	}

	override void CommitSuicide()
	{
		Weapon_Base weapon;
		WeaponEventBase weapon_event = new WeaponEventTrigger;
		
		//firearm suicide
		if (Weapon_Base.CastTo(weapon,m_Player.GetItemInHands()))
		{
			if (weapon.CanFire())
			{
				if (m_Player.IsAlive()) 
				{
					if (m_playerStatPlugin)
					{
						m_playerStatPlugin.Suicide(m_Player);
					}
				}
			}
		}
		
		//melee weapon suicide
		else if (m_Player.GetItemInHands() && m_Player.GetItemInHands().ConfigIsExisting("suicideAnim"))
		{
			if (m_playerStatPlugin)
			{
				m_playerStatPlugin.Suicide(m_Player);
			}
		}
		
		super.CommitSuicide();
	}
}