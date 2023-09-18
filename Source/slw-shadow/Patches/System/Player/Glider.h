#pragma once

namespace slw_shadow::Player
{
	class CGlider : public app::Player::CPlayerVehicle
	{
	public:
		static void InstallPatches();
		static void InstallHooks();
	};
}