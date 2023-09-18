#include "pch.h"
#include "Glider.h"

HOOK(void, __fastcall, AddCallbackHook, ASLR(0x008EB820), slw_shadow::Player::CGlider* in_pThis, void* edx, app::GameDocument& in_rDocument)
{
    originalAddCallbackHook(in_pThis, edx, in_rDocument);

    auto* pVisualGoc = in_pThis->GetComponent<app::fnd::GOCVisualModel>();
    auto* pEffectGoc = in_pThis->GetComponent<app::game::GOCEffect>();

    app::Player::CreateGliderBoosters(pVisualGoc, pEffectGoc);
}

void slw_shadow::Player::CGlider::InstallPatches()
{
    // Raise effect slots for CPlaneTornado from 1 to 3
    WRITE_MEMORY(ASLR(0x008EBCA7), byte, 0x03);

    // Remove effect From CPlaneTornado
    WRITE_MEMORY(ASLR(0x00E01234), byte, 0x00);
}

void slw_shadow::Player::CGlider::InstallHooks()
{
    INSTALL_HOOK(AddCallbackHook);
}