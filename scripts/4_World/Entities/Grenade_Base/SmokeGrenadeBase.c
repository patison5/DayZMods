enum ESmokeGrenadeState
{
	NO_SMOKE 	= 0
	START 	 	= 1,
	LOOP 	 	= 2,
	END			= 3,
	//! ---
	COUNT 		= 4
}

class SmokeGrenadeBase extends Grenade_Base
{
	protected ref Timer				m_TimerSmokeStart;
	protected ref Timer				m_TimerSmokeLoop;
	protected ref Timer				m_TimerSmokeEnd;
	
	protected ref Timer				m_TimerDefer;
	
	protected ESmokeGrenadeState	m_SmokeGrenadeState;
	protected ESmokeGrenadeState	m_LastSmokeGrenadeState;

	//! particle
	protected Particle 				m_ParticleSmoke;
	protected int					m_ParticleSmokeCurrentId;
	protected int					m_ParticleSmokeStartId;
	protected int					m_ParticleSmokeLoopId;
	protected int					m_ParticleSmokeEndId;
	protected vector				m_ParticleSmokePosition;
	
	//! sounds
	protected EffectSound			m_SoundSmoke;
	protected string				m_SoundSmokeStartId;
	protected string				m_SoundSmokeLoopId;
	protected string				m_SoundSmokeEndId;

	void SetParticleSmokeCurrent(int particle)
	{
		m_ParticleSmokeCurrentId = particle;
	}
	
	void SetParticleSmokeStart(int particle)
	{
		m_ParticleSmokeStartId = particle;
	}

	void SetParticleSmokeLoop(int particle)
	{
		m_ParticleSmokeLoopId = particle;
	}

	void SetParticleSmokeEnd(int particle)
	{
		m_ParticleSmokeEndId = particle;
	}
	
	void SetSoundSmokeStart(string sound)
	{
		m_SoundSmokeStartId = sound;
	}

	void SetSoundSmokeLoop(string sound)
	{
		m_SoundSmokeLoopId = sound;
	}

	void SetSoundSmokeEnd(string sound)
	{
		m_SoundSmokeEndId = sound;
	}	

	protected void PlaySmokeParticle()
	{
		m_ParticleSmoke = Particle.PlayOnObject(m_ParticleSmokeCurrentId, this, m_ParticlePosition, vector.Zero, true);
	}

	protected void SoundSmokeStart()
	{
		PlaySoundSetLoop(m_SoundSmoke, m_SoundSmokeStartId, 0.3, 1.0);
	}
	
	protected void SoundSmokeLoop()
	{
		PlaySoundSetLoop(m_SoundSmoke, m_SoundSmokeLoopId, 0.3, 1.0);
	}

	protected void SoundSmokeEnd()
	{
		PlaySoundSetLoop(m_SoundSmoke, m_SoundSmokeEndId, 1.0, 1.0);
	}
	
	//Stop
	protected void SoundSmokeStop()
	{
		StopSoundSet(m_SoundSmoke);
	}

	protected void DestroySmokeGrenade()
	{
		SetSmokeGrenadeState(ESmokeGrenadeState.NO_SMOKE);
		
		if( GetGame().IsServer() )
		{
			SetHealth("", "", 0);
		}
	}
	
	protected void RefreshParticlesAndSounds()
	{
		ESmokeGrenadeState state = GetSmokeGrenadeState();

		if( m_LastSmokeGrenadeState != state )
		{
			if( state == ESmokeGrenadeState.START )
			{
				//Print("RefreshAudioVisual:: START");
				SoundSmokeEnd();
				SoundSmokeStart();
				
				DestroyParticle(m_ParticleSmoke);
				SetParticleSmokeCurrent(m_ParticleSmokeStartId);
				PlaySmokeParticle();
			}
			else if( state == ESmokeGrenadeState.LOOP )
			{
				//Print("RefreshAudioVisual:: LOOP");
				SoundSmokeStop();
				SoundSmokeLoop();
				
				DestroyParticle(m_ParticleSmoke);
				SetParticleSmokeCurrent(m_ParticleSmokeLoopId);
				PlaySmokeParticle();
			}
			else if( state == ESmokeGrenadeState.END )
			{
				//Print("RefreshAudioVisual:: END");
				SoundSmokeStop();
				SoundSmokeEnd();
				
				DestroyParticle(m_ParticleSmoke);
				SetParticleSmokeCurrent(m_ParticleSmokeEndId);
				PlaySmokeParticle();
			}
			else if( state == ESmokeGrenadeState.NO_SMOKE )
			{
				//Print("RefreshAudioVisual:: NO_SMOKE");
				SoundSmokeStop();

				DestroyParticle(m_ParticleSmoke);
			}
			
			m_LastSmokeGrenadeState = state;
		}
	}
	
	override void Unpin()
	{
		super.Unpin();
		
		Activate();

	}
	
	override void OnActivateFinished()
	{
		if ( GetCompEM() && GetCompEM().CanWork() )
		{
			GetCompEM().SwitchOn();
		}
	}
	
	// When smoke starts
	override void OnWorkStart()
	{
		SetSmokeGrenadeState(ESmokeGrenadeState.START);

		Param1<ESmokeGrenadeState> par = new Param1<ESmokeGrenadeState>(ESmokeGrenadeState.LOOP);
		m_TimerSmokeLoop.Run(5.0, this, "SetSmokeGrenadeState", par);
	}
	
	// When the smoke stops
	override void OnWorkStop()
	{
		SetSmokeGrenadeState(ESmokeGrenadeState.END);

		//! defer timer
		m_TimerDefer.Run(5.0, this, "DestroySmokeGrenade");
	}
	
	override bool CanPutInCargo( EntityAI parent )
	{
		return !GetCompEM().IsWorking();
	}
	
	override void OnActivatedByTripWire()
	{
		GetCompEM().SwitchOn();
	}

	override void SetActions()
	{
		super.SetActions();

		RemoveAction(ActionPin);
	}
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		RefreshParticlesAndSounds();
	}

	override void OnExplosionEffects(Object source, Object directHit, int componentIndex, string surface, vector pos, vector surfNormal, float energyFactor, float explosionFactor, bool isWater, string ammoType) {}
	
	ESmokeGrenadeState GetSmokeGrenadeState()
	{
		return m_SmokeGrenadeState;
	}

	override void EEDelete(EntityAI parent)
	{
		SoundSmokeStop();
		DestroyParticle(m_ParticleSmoke);
	}

	void SetSmokeGrenadeState(ESmokeGrenadeState state)
	{
		//Print("Setting SGS to: " + typename.EnumToString(ESmokeGrenadeState, state));

		if( GetGame().IsServer() )
		{
			if ( m_SmokeGrenadeState != state )
			{
				m_SmokeGrenadeState = state;
				
				//synchronize
				SetSynchDirty();
			}
		}
	}
	
	void SmokeGrenadeBase()
	{
		m_SmokeGrenadeState = ESmokeGrenadeState.NO_SMOKE;

		m_TimerSmokeLoop = new Timer;
		m_TimerDefer = new Timer;

		SetAmmoType("");
		SetPinnable(false);
		SetGrenadeType(EGrenadeType.CHEMICAL);
		SetParticleSmokeStart(ParticleList.INVALID); //! no effect on base
		SetParticleSmokeLoop(ParticleList.INVALID); //! no effect on base
		SetParticleSmokeEnd(ParticleList.INVALID); //! no effect on base

		RegisterNetSyncVariableFloat("m_EM.m_Energy");
		RegisterNetSyncVariableInt("m_SmokeGrenadeState", ESmokeGrenadeState.NO_SMOKE, ESmokeGrenadeState.COUNT);
	}
	
	override void OnExplode()
	{}
	
	void ~SmokeGrenadeBase();
}