#pragma once

namespace slw_shadow::Player
{
	class AndroidShadowInfo : public app::Player::VirtualSonicInfo
	{
	public:
		static void InstallHooks();
	};
}