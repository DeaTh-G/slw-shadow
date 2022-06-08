#include "pch.h"
app::fnd::GOCVisualModel* SonicVisual = NULL;
bool IsLinkSonicOn = false;

HOOK(void, __fastcall, CVisualSonicActivateSubHook, ASLR(0x008FE290), int* a1, int* edx)
{
    originalCVisualSonicActivateSubHook(a1, edx);

    if (*(*((*(unsigned int***)(a1 + 4)) + 210) + 6) & 0x80000000)
        IsLinkSonicOn = true;
    else
        IsLinkSonicOn = false;
}

HOOK(void, __fastcall, CVisualSonicUpdateHook, ASLR(0x008FF1F0), app::Player::CVisualSonic* This, int* edx, float deltaTime)
{
    originalCVisualSonicUpdateHook(This, edx, deltaTime);

    SonicVisual = (app::fnd::GOCVisualModel*)(*(((int**)(((int*)This)[12])) + 1));
}

void app::Player::CVisualSonic::InstallHooks()
{
    INSTALL_HOOK(CVisualSonicActivateSubHook);
    INSTALL_HOOK(CVisualSonicUpdateHook);
}