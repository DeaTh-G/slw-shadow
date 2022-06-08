#include "pch.h"

using namespace app::Player;
using namespace app::game;
using namespace app::animation;

HOOK(void, __fastcall, CVisualHumanAnimCallBackFootHook, ASLR(0x008FDAC0), CVisualHuman* This, void* edx, CharactorAnimation* pAnimation, ETriggerValueType type, CallbackParam param)
{
    originalCVisualHumanAnimCallBackFootHook(This, edx, pAnimation, type, param);

    std::string animationName = ((CharactorAnimationSingle*)pAnimation)->GetCurrentAnimationName();
    if (!SkateSoundStates.contains(animationName))
        return;

    if (!((CSonic*)This->m_pOwner)->IsAlternateSkateSound)
        This->PlaySE(&((CSonic*)This->m_pOwner)->SkateSound, "sh_skate_l");
    else
        This->PlaySE(&((CSonic*)This->m_pOwner)->SkateSound, "sh_skate_r");

    ((CSonic*)This->m_pOwner)->IsAlternateSkateSound = !((CSonic*)This->m_pOwner)->IsAlternateSkateSound;
}

HOOK(void, __fastcall, CVisualHumanRegisterAnimationCallBackHook, ASLR(0x008FDC40), CVisualHuman* This, void* edx)
{
    originalCVisualHumanRegisterAnimationCallBackHook(This, edx);

    GOCAnimationScript* gocAnimation = *(app::game::GOCAnimationScript**)(*This->m_pGOCHolder + 8);

    if (!gocAnimation)
        return;

    AnimationCallback* callback = CreateAnimCallback(This, &CVisualHuman::AnimCallBackStopSkateSound, This->pAllocator);
    gocAnimation->RegisterCallback(-1, callback);
}

HOOK(void, __fastcall, CVisualHumanDeactivateHook, ASLR(0x008FDBA0), CVisualHuman* This, void* edx)
{
    originalCVisualHumanDeactivateHook(This, edx);

    GOCAnimationScript* gocAnimation = *(app::game::GOCAnimationScript**)(*This->m_pGOCHolder + 8);

    if (!gocAnimation)
        return;

    gocAnimation->UnregisterCallback(-1);
}

void CVisualHuman::InstallHooks()
{
    INSTALL_HOOK(CVisualHumanRegisterAnimationCallBackHook);
    INSTALL_HOOK(CVisualHumanDeactivateHook);
    INSTALL_HOOK(CVisualHumanAnimCallBackFootHook);
}