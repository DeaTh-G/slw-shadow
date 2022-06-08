#include "pch.h"

HOOK(void, __fastcall, CSonicAddCallbackHook, ASLR(0x00861B00), app::Player::CSonic* This, void* edx, int* a2)
{
    for (size_t i = 0; i < 10; i++)
        This->JetBoosterEffects[i] = app::Effect::CEffectHandle();
    This->SkateSound = app::fnd::SoundHandle();

    originalCSonicAddCallbackHook(This, edx, a2);

    if (!SonicVisual)
        return;

    app::game::GOCEffect* gocEffect = (app::game::GOCEffect*)app::GameObject::GetGOC((int*)This, (char*)ASLR(0x00D642B4));

    if (!IsLinkSonicOn)
        This->CreateShadowJetBoosters(gocEffect);
    else
        This->CreateLancelotJetBoosters(gocEffect);

    for (size_t i = 0; i < 10; i++)
        This->JetBoosterEffects[i].SetGlobalScaling(0.05f);
}

HOOK(void, __fastcall, CSonicUpdateHook, ASLR(0x00861CB0), app::Player::CSonic* This, void* edx, const app::fnd::SUpdateInfo& updateInfo)
{
    originalCSonicUpdateHook(This, edx, updateInfo);

    app::Player::CStateGOC* stateGOC = (app::Player::CStateGOC*)app::CGOCCollectionImpl::GetGOC((void*)((int*)This + 0xC9), (char*)ASLR(0x00DF77D8));
    if (!stateGOC)
        return;

    app::Player::CVisualGOC* visualGOC = (app::Player::CVisualGOC*)app::CGOCCollectionImpl::GetGOC((void*)(((int*)stateGOC)[22] + 0x32C), (char*)ASLR(0x00E01360));
    if (!visualGOC)
        return;
    std::string visualName = visualGOC->GetCurrentVisualName();

    if (!app::Player::JetOnStates.contains(stateGOC->GetCurrentAnimationName()) ||
        stateGOC->GetCurrentState() == 120 || stateGOC->GetCurrentState() == 13 ||
        stateGOC->GetCurrentState() == 15 || visualName == "VisualSuperSonic")
    {
        This->JetBoostersVisible(false);
    }
    else
    {
        This->JetBoostersVisible(true);
    }
}

HOOK(void, __fastcall, SonicZeldaInfoInitializeHook, ASLR(0x008F8800), int* a1, int* edx, int* a2)
{
    int packFile = 0;
    app::ObjUtil::GetPackFile(&packFile, "Lancelot.pac");

    originalSonicZeldaInfoInitializeHook(a1, edx, a2);
    if (!packFile)
        return;

    app::ObjUtil::GetModelResource(a1 + 4, "chr_Linksonic", &packFile);
}

HOOK(void, __fastcall, VirtualSonicInfoInitializeHook, ASLR(0x008F8C00), app::Player::VirtualSonicInfo* This, int* edx, int* a2)
{
    originalVirtualSonicInfoInitializeHook(This, edx, a2);

    This->AntennaModelP1 = 0;
    This->AntennaModelP2 = 0;
}

void app::Player::CSonic::InstallPatches()
{
    // Expand allocation to reserve spaces for storing the Jet Booster effects for Shadow
    WRITE_MEMORY_WITH_TYPE(ASLR(0x0085A92C), uint32_t, sizeof(app::Player::CSonic));

    // Raise effect slots for CSonic from 8 to 18
    WRITE_MEMORY(ASLR(0x00E024B4), 0x12);
}

void app::Player::CSonic::InstallHooks()
{
    INSTALL_HOOK(CSonicAddCallbackHook);
    INSTALL_HOOK(CSonicUpdateHook);
}

void app::Player::SonicZeldaInfo::InstallHooks() { INSTALL_HOOK(SonicZeldaInfoInitializeHook); }

void app::Player::VirtualSonicInfo::InstallHooks() { INSTALL_HOOK(VirtualSonicInfoInitializeHook); }