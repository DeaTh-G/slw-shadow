#include "pch.h"
#include "VisualHuman.h"

void slw_shadow::Player::CVisualHuman::AnimCallBackStopSkateSound(app::animation::CharactorAnimation* in_pAnimation, app::animation::ETriggerValueType in_triggerType, app::animation::CallbackParam in_param)
{
    auto* pAnimationName = static_cast<app::animation::CharactorAnimationSingle*>(in_pAnimation)->GetCurrentAnimationName();
    if (!ms_SkateStateNames.contains(pAnimationName))
    {
        auto* pShadow = static_cast<slw_shadow::Player::CShadow*>(pPlayer);
        if (pShadow->SkateSound.IsValid())
            app::Player::StateUtil::StopSE(*pShadow->GetStateGOC(), pShadow->SkateSound);
    }
}

const std::unordered_set<std::string_view> slw_shadow::Player::CVisualHuman::GetSkateStateNames() const
{
    return ms_SkateStateNames;
}

HOOK(void, __fastcall, AnimCallBackFootHook, ASLR(0x008FDAC0), slw_shadow::Player::CVisualHuman* in_pThis, void* edx, app::animation::CharactorAnimation* in_pAnimation, app::animation::ETriggerValueType in_type, app::animation::CallbackParam in_param)
{
    originalAnimCallBackFootHook(in_pThis, edx, in_pAnimation, in_type, in_param);

    auto* pAnimationName = static_cast<app::animation::CharactorAnimationSingle*>(in_pAnimation)->GetCurrentAnimationName();
    if (in_pThis->GetSkateStateNames().contains(pAnimationName))
    {
        auto* pShadow = static_cast<slw_shadow::Player::CShadow*>(in_pThis->pPlayer);

        if (pShadow->IsAlternateSkateSound)
            pShadow->SkateSound = in_pThis->PlaySE("sh_skate_l");
        else
            pShadow->SkateSound = in_pThis->PlaySE("sh_skate_r");

        pShadow->IsAlternateSkateSound = !pShadow->IsAlternateSkateSound;
    }
}

HOOK(void, __fastcall, RegisterAnimationCallBackHook, ASLR(0x008FDC40), slw_shadow::Player::CVisualHuman* in_pThis, void* edx)
{
    originalRegisterAnimationCallBackHook(in_pThis, edx);

    if (auto rpAnimationScriptGoc = in_pThis->pGocHolder->GetUnit(0).m_rpAnimScript)
        rpAnimationScriptGoc->RegisterCallback(-1, app::animation::CreateAnimCallback<slw_shadow::Player::CVisualHuman>(in_pThis, &slw_shadow::Player::CVisualHuman::AnimCallBackStopSkateSound, in_pThis->GetAllocator()));
}

HOOK(void, __fastcall, DeactivateHook, ASLR(0x008FDBA0), app::Player::CVisualHuman* in_pThis, void* edx)
{
    originalDeactivateHook(in_pThis, edx);
   
    if (auto rpAnimationScriptGoc = in_pThis->pGocHolder->GetUnit(0).m_rpAnimScript)
        rpAnimationScriptGoc->UnregisterCallback(-1);
}

void slw_shadow::Player::CVisualHuman::InstallHooks()
{
    INSTALL_HOOK(AnimCallBackFootHook);
    INSTALL_HOOK(RegisterAnimationCallBackHook);
    INSTALL_HOOK(DeactivateHook);
}