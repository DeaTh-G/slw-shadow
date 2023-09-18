#pragma once

namespace slw_shadow::Player
{
	class VehicleGliderInfo : public app::Player::VehicleTornadoInfo
	{
	private:
		inline static const char* ms_pGliderPackfileName = "Glider.pac";

	public:
		static void InstallPatches();
		static void InstallHooks();
	};
}