#pragma once

namespace slw_shadow::Player
{
	class CGlider : public app::Player::CPlayerVehicle
	{
	private:
		inline static const size_t ms_GliderBoosterEffectCount = 10;

	public:
		app::Effect::CEffectHandle<> GliderBoosterEffects[ms_GliderBoosterEffectCount]{};
		
		void CreateGliderBoosters();

		static void InstallPatches();
		static void InstallHooks();
	};
}