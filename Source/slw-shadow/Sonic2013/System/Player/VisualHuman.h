#pragma once
#include <unordered_set>

namespace app::Player
{
	static std::unordered_set<std::string_view> SkateSoundStates =
	{
		"AUTORUNNING", "LANDRUNNING", "JOG", "RUN", "JET", "SKATE",
		"DASH_BURNOUT_DASH_FV", "DASH_BURNOUT_DASH_SV_L", "DASH_BURNOUT_DASH_SV_R",
		"DASH_NORMAL", "DASH", "DASH_L", "DASH_R",
	};

	class CVisualHuman : public CPlayerVisual 
	{
	public:
		static void InstallHooks();

		void AnimCallBackStopSkateSound(animation::CharactorAnimation* pAnimation, animation::ETriggerValueType type, animation::CallbackParam param)
		{
			std::string animationName = ((animation::CharactorAnimationSingle*)pAnimation)->GetCurrentAnimationName();		
			if (!SkateSoundStates.contains(animationName))
			{
				if (((CSonic*)m_pOwner)->SkateSound.IsValid())
					StopSE(&((CSonic*)m_pOwner)->SkateSound);
				return;
			}
		}
	};
}