#pragma once
extern app::fnd::GOCVisualModel* SonicVisual;
extern bool IsLinkSonicOn;

namespace app::Player
{
	class CVisualSonic
	{
	public:
		static void InstallHooks();
	};
}