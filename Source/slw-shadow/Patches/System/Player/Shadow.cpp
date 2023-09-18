#include "pch.h"
#include "Shadow.h"

const std::unordered_set<std::string_view> slw_shadow::Player::CShadow::GetJetOnStateNames() const
{
    return std::unordered_set<std::string_view>();
}

HOOK(void, __fastcall, AddCallbackHook, ASLR(0x00861B00), slw_shadow::Player::CShadow* in_pThis, void* edx, app::GameDocument& in_rDocument)
{
    originalAddCallbackHook(in_pThis, edx, in_rDocument);

    for (size_t i = 0; i < 10; i++)
        in_pThis->JetBoosterEffects[i] = app::Effect::CEffectHandle();

    in_pThis->SkateSound = app::fnd::SoundHandle();

    auto* pEffectGoc = in_pThis->GetComponent<app::game::GOCEffect>();

    auto* pLinkSonicInfo = app::ObjUtil::GetObjectInfo<app::Player::SonicZeldaInfo>(in_rDocument);
    if (!pLinkSonicInfo)
        in_pThis->CreateShadowJetBoosters(gocEffect);
    else
        in_pThis->CreateLancelotJetBoosters(gocEffect);

    for (size_t i = 0; i < 10; i++)
        in_pThis->JetBoosterEffects[i].SetGlobalScaling(0.05f);
}

HOOK(void, __fastcall, UpdateHook, ASLR(0x00861CB0), slw_shadow::Player::CShadow* in_pThis, void* edx, const app::fnd::SUpdateInfo& in_rUpdateInfo)
{
    originalUpdateHook(in_pThis, edx, in_rUpdateInfo);

    auto* pStateGoc = in_pThis->GetStateGOC();
    if (!pStateGoc)
        return;

    auto* pVisualGoc = in_pThis->GetPlayerGOC<app::Player::CVisualGOC>();
    if (!pVisualGoc)
        return;

    const char* pAnimationName = pStateGoc->GetCurrentAnimationName();
    const char* pVisualName = pVisualGoc->GetCurrentVisualName();
    int currentState = pStateGoc->GetCurrentState();

    if (!in_pThis->GetJetOnStateNames().contains(pAnimationName) ||
        currentState == 120 || currentState == 13 ||  currentState == 15 ||
        !strcmp(pVisualName, "VisualSuperSonic") || !strcmp(pVisualName, "CVisualSpin"))
    {
        in_pThis->JetBoostersVisible(false);
    }
    else
    {
        in_pThis->JetBoostersVisible(true);
    }
}

void slw_shadow::Player::CShadow::InstallPatches()
{
    // Expand allocation to reserve spaces for storing the Jet Booster effects for Shadow
    WRITE_MEMORY(ASLR(0x0085A92C), uint32_t, sizeof(slw_shadow::Player::CShadow));

    // Raise effect slots for CSonic from 8 to 18
    WRITE_MEMORY(ASLR(0x00E024B4), byte, 0x12);
}

void slw_shadow::Player::CShadow::InstallHooks()
{
    INSTALL_HOOK(AddCallbackHook);
    INSTALL_HOOK(UpdateHook);
}