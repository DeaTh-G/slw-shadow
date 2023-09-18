#pragma once

namespace slw_shadow::Player
{
	class ShadowLancelotInfo : public app::Player::SonicZeldaInfo
	{
	public:
		static void InstallHooks();
	};
}