modded class ActionDigOutStash : ActionContinuousBase
{

	ref BurryCheatersOff m_burryCheatersOff;

	void ActionDigOutStash()
	{
		m_burryCheatersOff = GetBurryCheatersOff();
	}

	override void OnFinishProgressServer( ActionData action_data )
	{	
		Object targetObject = action_data.m_Target.GetObject();
		EntityAI targetEntity = EntityAI.Cast(targetObject);
		UndergroundStash target_stash;

		if (!targetEntity)
		{
			return;
		}
		
		// Dig out of stash
		if ( Class.CastTo(target_stash, targetEntity) )
		{

			ItemBase chest = target_stash.GetStashedItem();
			
			if (chest)
			{
                m_burryCheatersOff.updateData(action_data.m_Player, 0, 1);
			}
		}

		super.OnFinishProgressServer(action_data);
	}
}