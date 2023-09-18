#include "pch.h"
#include "GameModeStartUp.h"

HOOK(void, __fastcall, PreLoadResidentFileHook, ASLR(0x0091B4F0), app::GameModeStartUp* in_pThis, void* edx)
{
    originalPreLoadResidentFileHook(in_pThis, edx);

    app::fnd::FileLoaderParam loader{};
    loader.m_Unk4 = 4096;
    app::GameMode::LoadFile("sound/se_player_shadow.acb", loader);
}

void slw_shadow::GameModeStartUp::InstallHooks()
{
    INSTALL_HOOK(PreLoadResidentFileHook);
}