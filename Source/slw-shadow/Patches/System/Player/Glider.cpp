#include "pch.h"
#include "Glider.h"

void slw_shadow::Player::CGlider::CreateGliderBoosters()
{
    auto* pVisualGoc = GetComponent<app::fnd::GOCVisualModel>();
    auto* pEffectGoc = GetComponent<app::game::GOCEffect>();

	if (!pVisualGoc || !pEffectGoc)
		return;

	app::game::EffectCreateInfo effectInfo{};
	effectInfo.m_pName = "ef_dl1_stagefire_lp";
	effectInfo.m_Unk1 = 1.0f;
	effectInfo.m_Unk2 = 1;
	effectInfo.m_Unk3 = true;
	effectInfo.m_pVisual = pVisualGoc;

	effectInfo.m_Position = { 0.0f, 0.0f, -3.0f };
	effectInfo.m_Rotation = { 0.707f, 0, 0, -0.707f };

	// Create Left Booster
	effectInfo.m_pBoneName = "pBoost_L";
	pEffectGoc->CreateEffectLoopEx(&GliderBoosterEffects[0], effectInfo);

	// Create Right Booster
	effectInfo.m_pBoneName = "pBoost_R";
	pEffectGoc->CreateEffectLoopEx(&GliderBoosterEffects[1], effectInfo);

	for (size_t i = 0; i < 2; i++)
		GliderBoosterEffects[i].SetGlobalScaling(0.65f);
}

HOOK(void, __fastcall, AddCallbackHook, ASLR(0x008EB820), slw_shadow::Player::CGlider* in_pThis, void* edx, app::GameDocument& in_rDocument)
{
    originalAddCallbackHook(in_pThis, edx, in_rDocument);

    in_pThis->CreateGliderBoosters();
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