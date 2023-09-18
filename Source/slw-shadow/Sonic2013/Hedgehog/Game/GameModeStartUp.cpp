#include "pch.h"

HOOK(void, __fastcall, GameModeStartUpPreLoadResidentFileHook, ASLR(0x0091B4F0))
{
    originalGameModeStartUpPreLoadResidentFileHook();

    app::fnd::FileLoaderParam loader{};
    loader.field_0C = 0x1000;
    app::GameMode::LoadFile("sound/se_player_shadow.acb", &loader);
}

void app::GameModeStartUp::InstallHooks()
{
    INSTALL_HOOK(GameModeStartUpPreLoadResidentFileHook);
}
