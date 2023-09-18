#include "pch.h"
#include "Shadow.h"

const std::unordered_set<std::string_view> slw_shadow::Player::CShadow::GetJetOnStateNames() const
{
    return ms_JetOnStateNames;
}

void slw_shadow::Player::CShadow::CreateShadowJetBoosters()
{
	auto* pEffectGoc = GetComponent<app::game::GOCEffect>();
	if (!pEffectGoc)
		return;

	auto rpVisualGoc = GetPlayerGOC<app::Player::CVisualGOC>()->m_rpHumanVisual->pGocHolder->GetUnit(0).m_rpModel;

	app::game::EffectCreateInfo effectInfo{};
	effectInfo.m_pName = "ef_dl3_gossipstone_fire";
	effectInfo.m_Unk1 = 1.0f;
	effectInfo.m_Unk2 = 1;
	effectInfo.m_Unk3 = true;
	effectInfo.m_pVisual = rpVisualGoc.get();

	app::math::Transform transform{};
	rpVisualGoc->GetNodeTransform(0, "Foot_L", &transform);
	effectInfo.m_Rotation = { -transform.m_Rotation.x(), -transform.m_Rotation.y(), -transform.m_Rotation.z(), transform.m_Rotation.w() };

	effectInfo.m_pBoneName = "Foot_L";

	// Create Left Back Booster
	effectInfo.m_Position = csl::math::Vector3(1.2f, -0.08f, 0.525f);
	pEffectGoc->CreateEffectLoopEx(&JetBoosterEffects[0], effectInfo);

	// Create Left 2nd Booster
	effectInfo.m_Position = csl::math::Vector3(1.2f, -0.06f, 0);
	pEffectGoc->CreateEffectLoopEx(&JetBoosterEffects[1], effectInfo);

	rpVisualGoc->GetNodeTransform(0, "Toe_L", &transform);
	Eigen::Quaternionf q{ transform.m_Rotation.w(), transform.m_Rotation.x(), transform.m_Rotation.y(), transform.m_Rotation.z() };
	q = Eigen::AngleAxisf(0.5f * MATHF_PI, Eigen::Vector3f::UnitX()) * q;
	effectInfo.m_Rotation = csl::math::Quaternion(q.y(), q.z(), q.w(), q.x());
	effectInfo.m_pBoneName = "Toe_L";

	// Create Left 3rd Booster
	effectInfo.m_Position = csl::math::Vector3(-0.225f, -0.02f, 0.26f);
	pEffectGoc->CreateEffectLoopEx(&JetBoosterEffects[2], effectInfo);

	// Create Left 4th Booster
	effectInfo.m_Position = csl::math::Vector3(0.29f, -0.01f, 0.26f);
	pEffectGoc->CreateEffectLoopEx(&JetBoosterEffects[3], effectInfo);

	q = Eigen::AngleAxisf(-0.25f * MATHF_PI, Eigen::Vector3f::UnitX()) * q;
	effectInfo.m_Rotation = csl::math::Quaternion(q.y(), q.z(), q.w(), q.x());

	// Create Left Front Booster
	effectInfo.m_Position = csl::math::Vector3(0.68f, 0.02f, 0);
	pEffectGoc->CreateEffectLoopEx(&JetBoosterEffects[4], effectInfo);

	rpVisualGoc->GetNodeTransform(0, "Foot_R", &transform);
	effectInfo.m_Rotation = { -transform.m_Rotation.x(), -transform.m_Rotation.y(), transform.m_Rotation.z(), -transform.m_Rotation.w() };

	effectInfo.m_pBoneName = "Foot_R";

	// Create Right Back Booster
	effectInfo.m_Position = csl::math::Vector3(1.2f, 0.08f, 0.525f);
	pEffectGoc->CreateEffectLoopEx(&JetBoosterEffects[5], effectInfo);

	// Create Right 2nd Booster
	effectInfo.m_Position = csl::math::Vector3(1.2f, 0.06f, 0);
	pEffectGoc->CreateEffectLoopEx(&JetBoosterEffects[6], effectInfo);

	rpVisualGoc->GetNodeTransform(0, "Toe_R", &transform);
	q = { transform.m_Rotation.w(), transform.m_Rotation.x(), transform.m_Rotation.y(), transform.m_Rotation.z() };
	q = Eigen::AngleAxisf(0.5f * MATHF_PI, Eigen::Vector3f::UnitX()) * q;
	effectInfo.m_Rotation = csl::math::Quaternion(q.y(), q.z(), q.w(), q.x());
	effectInfo.m_pBoneName = "Toe_R";

	// Create Right 3rd Booster
	effectInfo.m_Position = csl::math::Vector3(-0.225f, 0, 0.26f);
	pEffectGoc->CreateEffectLoopEx(&JetBoosterEffects[7], effectInfo);

	// Create Right 4th Booster
	effectInfo.m_Position = csl::math::Vector3(0.29f, -0.01f, 0.26f);
	pEffectGoc->CreateEffectLoopEx(&JetBoosterEffects[8], effectInfo);

	q = Eigen::AngleAxisf(-0.25f * MATHF_PI, Eigen::Vector3f::UnitX()) * q;
	effectInfo.m_Rotation = csl::math::Quaternion(q.y(), q.z(), q.w(), q.x());

	// Create Right Front Booster
	effectInfo.m_Position = csl::math::Vector3(0.68f, -0.04f, 0);
	pEffectGoc->CreateEffectLoopEx(&JetBoosterEffects[9], effectInfo);
}

void slw_shadow::Player::CShadow::CreateLancelotJetBoosters()
{
	auto* pEffectGoc = GetComponent<app::game::GOCEffect>();
	if (!pEffectGoc)
		return;
	
	auto rpVisualGoc = GetPlayerGOC<app::Player::CVisualGOC>()->m_rpHumanVisual->pGocHolder->GetUnit(0).m_rpModel;

	app::game::EffectCreateInfo effectInfo{};
	effectInfo.m_pName = "ef_dl3_gossipstone_fire";
	effectInfo.m_Unk1 = 1.0f;
	effectInfo.m_Unk2 = 1;
	effectInfo.m_Unk3 = true;
	effectInfo.m_pVisual = rpVisualGoc.get();

	app::math::Transform transform{};
	rpVisualGoc->GetNodeTransform(0, "Foot_L", &transform);
	effectInfo.m_Rotation = { -transform.m_Rotation.x(), -transform.m_Rotation.y(), -transform.m_Rotation.z(), transform.m_Rotation.w() };
	
	effectInfo.m_pBoneName = "Foot_L";

	// Create Left Back Booster
	effectInfo.m_Position = csl::math::Vector3(1.2f, -0.06f, 0.12f);
	pEffectGoc->CreateEffectLoopEx(&JetBoosterEffects[0], effectInfo);

	// Create Left 2nd Booster
	effectInfo.m_Position = csl::math::Vector3(1.2f, -0.02f, -1.115f);
	pEffectGoc->CreateEffectLoopEx(&JetBoosterEffects[1], effectInfo);

	// Create Left 3rd Booster
	effectInfo.m_Position = csl::math::Vector3(1.2f, 0.02f, -1.82f);
	pEffectGoc->CreateEffectLoopEx(&JetBoosterEffects[2], effectInfo);

	Eigen::Quaternionf q{ transform.m_Rotation.w(), -transform.m_Rotation.x(), -transform.m_Rotation.y(), -transform.m_Rotation.z() };
	q = Eigen::AngleAxisf(1.25f * MATHF_PI, Eigen::Vector3f::UnitX()) * q;
	effectInfo.m_Rotation = csl::math::Quaternion(q.y(), q.z(), q.w(), q.x());

	// Create Left Front Booster
	effectInfo.m_Position = csl::math::Vector3(1, 0.02f, -2.3f);
	pEffectGoc->CreateEffectLoopEx(&JetBoosterEffects[3], effectInfo);

	rpVisualGoc->GetNodeTransform(0, "Foot_R", &transform);
	effectInfo.m_Rotation = { -transform.m_Rotation.x(), -transform.m_Rotation.y(), transform.m_Rotation.z(), -transform.m_Rotation.w() };
	
	effectInfo.m_pBoneName = "Foot_R";

	// Create Right Back Booster
	effectInfo.m_Position = csl::math::Vector3(1.2f, 0.06f, 0.12f);
	pEffectGoc->CreateEffectLoopEx(&JetBoosterEffects[4], effectInfo);

	// Create Right 2nd Booster
	effectInfo.m_Position = csl::math::Vector3(1.2f, 0.02f, -1.115f);
	pEffectGoc->CreateEffectLoopEx(&JetBoosterEffects[5], effectInfo);

	// Create Right 3rd Booster
	effectInfo.m_Position = csl::math::Vector3(1.2f, -0.02f, -1.82f);
	pEffectGoc->CreateEffectLoopEx(&JetBoosterEffects[6], effectInfo);

	q = { -transform.m_Rotation.w(), -transform.m_Rotation.x(), -transform.m_Rotation.y(), transform.m_Rotation.z() };
	q = Eigen::AngleAxisf(1.25f * MATHF_PI, Eigen::Vector3f::UnitX()) * q;
	effectInfo.m_Rotation = csl::math::Quaternion(q.y(), q.z(), q.w(), q.x());

	// Create Right Front Booster
	effectInfo.m_Position = csl::math::Vector3(1, 0.02f, -2.3f);
	pEffectGoc->CreateEffectLoopEx(&JetBoosterEffects[7], effectInfo);
}

void slw_shadow::Player::CShadow::JetBoostersVisible(bool in_isEnable)
{
	for (size_t i = 0; i < ms_JetBoosterEffectCount; i++)
		if (JetBoosterEffects[i].IsValid())
			JetBoosterEffects[i].SetVisible(in_isEnable);
}

HOOK(void, __fastcall, AddCallbackHook, ASLR(0x00861B00), slw_shadow::Player::CShadow* in_pThis, void* edx, app::GameDocument& in_rDocument)
{
    originalAddCallbackHook(in_pThis, edx, in_rDocument);

    for (size_t i = 0; i < 10; i++)
        in_pThis->JetBoosterEffects[i] = app::Effect::CEffectHandle();

    in_pThis->SkateSound = app::fnd::SoundHandle();

    auto* pLinkSonicInfo = app::ObjUtil::GetObjectInfo<app::Player::SonicZeldaInfo>(in_rDocument);
    if (!pLinkSonicInfo)
        in_pThis->CreateShadowJetBoosters();
    else
        in_pThis->CreateLancelotJetBoosters();

    for (size_t i = 0; i < 10; i++)
        in_pThis->JetBoosterEffects[i].SetGlobalScaling(0.05f);
}

HOOK(void, __fastcall, UpdateHook, ASLR(0x00861CB0), app::fnd::CActor* in_pThis, void* edx, const app::fnd::SUpdateInfo& in_rUpdateInfo)
{
	originalUpdateHook(in_pThis, edx, in_rUpdateInfo);
	
	auto* pThis = static_cast<slw_shadow::Player::CShadow*>(in_pThis);

    auto* pStateGoc = pThis->GetStateGOC();
    if (!pStateGoc)
        return;

    auto* pVisualGoc = pThis->GetPlayerGOC<app::Player::CVisualGOC>();
    if (!pVisualGoc)
        return;

    const char* pAnimationName = pStateGoc->GetCurrentAnimationName();
    const char* pVisualName = pVisualGoc->GetCurrentVisualName();
    int currentState = pStateGoc->GetCurrentState();

    if (!pThis->GetJetOnStateNames().contains(pAnimationName) ||
        currentState == 120 || currentState == 13 ||  currentState == 15 ||
        !strcmp(pVisualName, "VisualSuperSonic") || !strcmp(pVisualName, "CVisualSpin"))
    {
		pThis->JetBoostersVisible(false);
    }
    else
    {
		pThis->JetBoostersVisible(true);
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