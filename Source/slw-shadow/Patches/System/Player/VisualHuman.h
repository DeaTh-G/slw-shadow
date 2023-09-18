#pragma once
#include <unordered_set>

namespace slw_shadow::Player
{
	class CVisualHuman : public app::Player::CVisualHuman
	{
	private:
		inline static const std::unordered_set<std::string_view> ms_SkateStateNames = {
			"AUTORUNNING", "LANDRUNNING", "JOG", "RUN", "JET", "SKATE",
			"DASH_BURNOUT_DASH_FV", "DASH_BURNOUT_DASH_SV_L", "DASH_BURNOUT_DASH_SV_R",
			"DASH_NORMAL", "DASH", "DASH_L", "DASH_R",
		};

	public:
		void AnimationCallback(app::animation::CharactorAnimation* in_pAnimation, app::animation::ETriggerValueType in_triggerType, app::animation::CallbackParam in_param);
		const std::unordered_set<std::string_view> GetSkateStateNames() const;
		static void InstallHooks();
	};
}