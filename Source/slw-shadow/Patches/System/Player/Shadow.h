#pragma once

namespace slw_shadow::Player
{
	class CShadow : public app::Player::CSonic
	{
	private:
		inline static const size_t ms_JetBoosterEffectCount = 10;
		inline static const std::unordered_set<std::string_view> ms_JetOnStateNames =
		{
			"AUTORUNNING", "LANDRUNNING", "JOG", "RUN", "JET",
			"BRAKE_L_END", "BRAKE_L_LOOP", "BRAKE_L_START", "BRAKE_L_TURN",
			"BRAKE_R_END", "BRAKE_R_LOOP", "BRAKE_R_START", "BRAKE_R_TURN",
			"SKATE", "SKATE_BRAKE", "SKATE_CURVE_L", "SKATE_CURVE_R",
			"DASH_NORMAL", "DASH", "DASH_L", "DASH_R", "DASHRING",
			"DASH_BURNOUT_DASH_FV", "DASH_BURNOUT_DASH_SV_L", "DASH_BURNOUT_DASH_SV_R",
			"KICK", "KICK_START" "KICK_LOOP",
		};

	public:
		app::Effect::CEffectHandle<> JetBoosterEffects[ms_JetBoosterEffectCount]{};
		app::fnd::SoundHandle SkateSound{};
		bool IsAlternateSkateSound{};

		const std::unordered_set<std::string_view> GetJetOnStateNames() const;

		static void InstallPatches();
		static void InstallHooks();
	};
}