#include "pch.h"
#include "PlayerVisualShadowLancelotInfo.h"

HOOK(void, __fastcall, InitializeHook, ASLR(0x008F8800), slw_shadow::Player::ShadowLancelotInfo* in_pThis, void* edx, app::GameDocument& in_rDocument)
{
    originalInitializeHook(in_pThis, edx, in_rDocument);

    hh::ut::PackFile packFile = app::ObjUtil::GetPackFile("Lancelot.pac");
    in_pThis->Model = app::ObjUtil::GetModelResource("chr_Linksonic", packFile);
}

void slw_shadow::Player::ShadowLancelotInfo::InstallHooks()
{
    INSTALL_HOOK(InitializeHook);
}