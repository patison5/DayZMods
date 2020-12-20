modded class ActionDigInStash: ActionContinuousBase
{
	
	ref BurryCheatersOff m_burryCheatersOff;

	// override void ActionBuryAshes()
	// {
	// 	super.ActionBuryAshes();
	// 	m_burryCheatersOff = new BurryCheatersOff();
	// }

	void ActionDigInStash () {
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
		
		ItemBase stashed_item;
		UndergroundStash stash;
		vector pos = targetEntity.GetPosition();
					
		Class.CastTo(stashed_item,  targetEntity );
		Class.CastTo(stash,  GetGame().CreateObjectEx("UndergroundStash", pos, ECE_PLACE_ON_SURFACE) );
		  
		if ( stash )
		{
		    m_burryCheatersOff.updateData(action_data.m_Player, 1, 0);
		}

		super.OnFinishProgressServer(action_data);
	}
}