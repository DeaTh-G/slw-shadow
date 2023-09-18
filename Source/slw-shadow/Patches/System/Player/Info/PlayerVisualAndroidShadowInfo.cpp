#include "pch.h"
#include "PlayerVisualAndroidShadowInfo.h"

HOOK(void, __fastcall, InitializeHook, ASLR(0x008F8C00), slw_shadow::Player::AndroidShadowInfo* in_pThis, void* edx, app::GameDocument& in_rDocument)
{
    originalInitializeHook(in_pThis, edx, in_rDocument);

    in_pThis->AntennaModels[0] = { nullptr };
    in_pThis->AntennaModels[1] = { nullptr };
}

void slw_shadow::Player::AndroidShadowInfo::InstallHooks()
{
    INSTALL_HOOK(InitializeHook);
}