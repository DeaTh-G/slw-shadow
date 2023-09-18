#include "pch.h"
#include "PlayerVehicleGliderInfo.h"

HOOK(void, __fastcall, LoadHook, ASLR(0x008F8F10), slw_shadow::Player::VehicleGliderInfo* in_pThis, void* edx, app::CObjInfoFileLoader& in_rLoader)
{
    originalLoadHook(in_pThis, edx, in_rLoader);

    in_rLoader.Load("Glider.pac", -1);
}

void slw_shadow::Player::VehicleGliderInfo::InstallPatches()
{
    // Replace Tornado.pac with Glider.pac in app::Player::VehicleTornadoInfo::Initialize
    WRITE_MEMORY(ASLR(0x008F8FCB), uintptr_t, (uintptr_t)ms_pGliderPackfileName);
}

void slw_shadow::Player::VehicleGliderInfo::InstallHooks()
{
    INSTALL_HOOK(LoadHook);
}