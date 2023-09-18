#pragma once

namespace slw_shadow::Player
{
	class alignas(16) CGlider : public app::Player::CPlaneTornado
	{
	private:
		inline static const size_t ms_GliderBoosterEffectCount = 2;

	public:
		app::Effect::CEffectHandle<> GliderBoosterEffects[ms_GliderBoosterEffectCount]{};
		
		void CreateGliderBoosters();

		static void InstallPatches();
		static void InstallHooks();
	};
}