#pragma once

namespace app::Player
{
	static const char* GliderPacName = "Glider.pac";
	static app::Effect::CEffectHandle GliderBoosterEffects[2]{};

	static void CreateGliderBoosters(app::fnd::GOCVisualModel* gocVisualModel, app::game::GOCEffect* gocEffect)
	{
		if (!gocVisualModel || !gocEffect)
			return;

		app::game::EffectCreateInfo effectInfo{};
		effectInfo.Name = "ef_dl1_stagefire_lp";
		effectInfo.field_04 = 1;
		effectInfo.field_08 = 1;
		effectInfo.field_30 = true;
		effectInfo.field_40 = gocVisualModel;

		effectInfo.Position = csl::math::Vector3(0, 0, -3);
		effectInfo.Rotation = csl::math::Quaternion(0.707, 0, 0, -0.707);

		// Create Left Booster
		effectInfo.field_44 = "pBoost_L";
		gocEffect->CreateEffectLoopEx(&GliderBoosterEffects[0], &effectInfo);

		// Create Right Booster
		effectInfo.field_44 = "pBoost_R";
		gocEffect->CreateEffectLoopEx(&GliderBoosterEffects[1], &effectInfo);

		for (size_t i = 0; i < 2; i++)
			GliderBoosterEffects[i].SetGlobalScaling(0.65f);
	}

	class VehicleTornadoInfo : public CObjInfo
	{
	public:
		int Model{};
		int Skeleton{};
		animation::AnimationResContainer AnimationContainer { pAllocator };
		res::ResShadowModel ShadowModel{};

		static void InstallPatches();
		static void InstallHooks();
	};

	class CPlaneTornado : public CPlayerVehicle
	{
		char Data[0x170];

	public:
		static void InstallPatches();
		static void InstallHooks();
	};
}