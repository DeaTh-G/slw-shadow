#pragma once
#include <unordered_set>
#define M_PI 3.1415927f

namespace app::Player
{
	static std::unordered_set<std::string_view> JetOnStates =
	{
		"AUTORUNNING", "LANDRUNNING", "JOG", "RUN", "JET",
		"BRAKE_L_END", "BRAKE_L_LOOP", "BRAKE_L_START", "BRAKE_L_TURN",
		"BRAKE_R_END", "BRAKE_R_LOOP", "BRAKE_R_START", "BRAKE_R_TURN",
		"SKATE", "SKATE_BRAKE", "SKATE_CURVE_L", "SKATE_CURVE_R",
		"DASH_NORMAL", "DASH", "DASH_L", "DASH_R", "DASHRING",
		"DASH_BURNOUT_DASH_FV", "DASH_BURNOUT_DASH_SV_L", "DASH_BURNOUT_DASH_SV_R",
		"KICK", "KICK_START" "KICK_LOOP",
	};

	class SonicZeldaInfo : public CObjInfo
	{
	public:
		static void InstallHooks();
	};

	class VirtualSonicInfo : public CObjInfo
	{
	public:
		hh::gfx::res::ResModel ModelP1;
		hh::gfx::res::ResModel ModelP2;
		hh::gfx::res::ResModel SpinModelP1;
		hh::gfx::res::ResModel SpinModelP2;
		int AntennaModelP1;
		int AntennaModelP2;

		static void InstallHooks();
	};

	class CSonic : public CPlayer
	{
	public:
		Effect::CEffectHandle JetBoosterEffects[10];
		INSERT_PADDING(8);
		fnd::SoundHandle SkateSound{};
		INSERT_PADDING(4);
		bool IsAlternateSkateSound{};
		INSERT_PADDING(15);

		static void InstallPatches();
		static void InstallHooks();

		void CreateShadowJetBoosters(game::GOCEffect* gocEffect)
		{
			if (!gocEffect)
				return;

			game::EffectCreateInfo effectInfo{};
			effectInfo.Name = "ef_dl3_gossipstone_fire";
			effectInfo.field_04 = 1;
			effectInfo.field_08 = 1;
			effectInfo.field_30 = true;
			effectInfo.field_40 = SonicVisual;

			math::Transform transform{};

			SonicVisual->GetNodeTransform(0, "Foot_L", &transform);
			effectInfo.Rotation =
				csl::math::Quaternion(-transform.Rotation.X, -transform.Rotation.Y,
					-transform.Rotation.Z, transform.Rotation.W);
			effectInfo.field_44 = "Foot_L";

			// Create Left Back Booster
			effectInfo.Position = csl::math::Vector3(1.2f, -0.08f, 0.525f);
			gocEffect->CreateEffectLoopEx(&JetBoosterEffects[0], &effectInfo);

			// Create Left 2nd Booster
			effectInfo.Position = csl::math::Vector3(1.2f, -0.06f, 0);
			gocEffect->CreateEffectLoopEx(&JetBoosterEffects[1], &effectInfo);

			SonicVisual->GetNodeTransform(0, "Toe_L", &transform);
			Eigen::Quaternionf q(transform.Rotation.W, transform.Rotation.X,
				transform.Rotation.Y, transform.Rotation.Z);
			q = Eigen::AngleAxisf(0.5f * M_PI, Eigen::Vector3f::UnitX()) * q;
			effectInfo.Rotation = csl::math::Quaternion(q.y(), q.z(), q.w(), q.x());
			effectInfo.field_44 = "Toe_L";

			// Create Left 3rd Booster
			effectInfo.Position = csl::math::Vector3(-0.225f, -0.02f, 0.26f);
			gocEffect->CreateEffectLoopEx(&JetBoosterEffects[2], &effectInfo);

			// Create Left 4th Booster
			effectInfo.Position = csl::math::Vector3(0.29f, -0.01f, 0.26f);
			gocEffect->CreateEffectLoopEx(&JetBoosterEffects[3], &effectInfo);

			q = Eigen::AngleAxisf(-0.25f * M_PI, Eigen::Vector3f::UnitX()) * q;
			effectInfo.Rotation = csl::math::Quaternion(q.y(), q.z(), q.w(), q.x());

			// Create Left Front Booster
			effectInfo.Position = csl::math::Vector3(0.68f, 0.02f, 0);
			gocEffect->CreateEffectLoopEx(&JetBoosterEffects[4], &effectInfo);

			SonicVisual->GetNodeTransform(0, "Foot_R", &transform);
			effectInfo.Rotation =
				csl::math::Quaternion(-transform.Rotation.X, -transform.Rotation.Y,
					transform.Rotation.Z, -transform.Rotation.W);
			effectInfo.field_44 = "Foot_R";

			// Create Right Back Booster
			effectInfo.Position = csl::math::Vector3(1.2f, 0.08f, 0.525f);
			gocEffect->CreateEffectLoopEx(&JetBoosterEffects[5], &effectInfo);

			// Create Right 2nd Booster
			effectInfo.Position = csl::math::Vector3(1.2f, 0.06f, 0);
			gocEffect->CreateEffectLoopEx(&JetBoosterEffects[6], &effectInfo);

			SonicVisual->GetNodeTransform(0, "Toe_R", &transform);
			q = Eigen::Quaternionf(transform.Rotation.W, transform.Rotation.X,
				transform.Rotation.Y, transform.Rotation.Z);
			q = Eigen::AngleAxisf(0.5f * M_PI, Eigen::Vector3f::UnitX()) * q;
			effectInfo.Rotation = csl::math::Quaternion(q.y(), q.z(), q.w(), q.x());
			effectInfo.field_44 = "Toe_R";

			// Create Right 3rd Booster
			effectInfo.Position = csl::math::Vector3(-0.225f, 0, 0.26f);
			gocEffect->CreateEffectLoopEx(&JetBoosterEffects[7], &effectInfo);

			// Create Right 4th Booster
			effectInfo.Position = csl::math::Vector3(0.29f, -0.01f, 0.26f);
			gocEffect->CreateEffectLoopEx(&JetBoosterEffects[8], &effectInfo);

			q = Eigen::AngleAxisf(-0.25f * M_PI, Eigen::Vector3f::UnitX()) * q;
			effectInfo.Rotation = csl::math::Quaternion(q.y(), q.z(), q.w(), q.x());

			// Create Right Front Booster
			effectInfo.Position = csl::math::Vector3(0.68f, -0.04f, 0);
			gocEffect->CreateEffectLoopEx(&JetBoosterEffects[9], &effectInfo);
		}

		void CreateLancelotJetBoosters(game::GOCEffect* gocEffect)
		{
			if (!gocEffect)
				return;

			game::EffectCreateInfo effectInfo{};
			effectInfo.Name = "ef_dl3_gossipstone_fire";
			effectInfo.field_04 = 1;
			effectInfo.field_08 = 1;
			effectInfo.field_30 = true;
			effectInfo.field_40 = SonicVisual;

			math::Transform transform{};

			SonicVisual->GetNodeTransform(0, "Foot_L", &transform);
			effectInfo.Rotation =
				csl::math::Quaternion(-transform.Rotation.X, -transform.Rotation.Y,
					-transform.Rotation.Z, transform.Rotation.W);
			effectInfo.field_44 = "Foot_L";

			// Create Left Back Booster
			effectInfo.Position = csl::math::Vector3(1.2f, -0.06f, 0.12f);
			gocEffect->CreateEffectLoopEx(&JetBoosterEffects[0], &effectInfo);

			// Create Left 2nd Booster
			effectInfo.Position = csl::math::Vector3(1.2f, -0.02f, -1.115f);
			gocEffect->CreateEffectLoopEx(&JetBoosterEffects[1], &effectInfo);

			// Create Left 3rd Booster
			effectInfo.Position = csl::math::Vector3(1.2f, 0.02f, -1.82f);
			gocEffect->CreateEffectLoopEx(&JetBoosterEffects[2], &effectInfo);

			Eigen::Quaternionf q(transform.Rotation.W, -transform.Rotation.X,
				-transform.Rotation.Y, -transform.Rotation.Z);
			q = Eigen::AngleAxisf(1.25f * M_PI, Eigen::Vector3f::UnitX()) * q;
			effectInfo.Rotation = csl::math::Quaternion(q.y(), q.z(), q.w(), q.x());

			// Create Left Front Booster
			effectInfo.Position = csl::math::Vector3(1, 0.02f, -2.3f);
			gocEffect->CreateEffectLoopEx(&JetBoosterEffects[3], &effectInfo);

			SonicVisual->GetNodeTransform(0, "Foot_R", &transform);
			effectInfo.Rotation =
				csl::math::Quaternion(-transform.Rotation.X, -transform.Rotation.Y,
					transform.Rotation.Z, -transform.Rotation.W);
			effectInfo.field_44 = "Foot_R";

			// Create Right Back Booster
			effectInfo.Position = csl::math::Vector3(1.2f, 0.06f, 0.12f);
			gocEffect->CreateEffectLoopEx(&JetBoosterEffects[4], &effectInfo);

			// Create Right 2nd Booster
			effectInfo.Position = csl::math::Vector3(1.2f, 0.02f, -1.115f);
			gocEffect->CreateEffectLoopEx(&JetBoosterEffects[5], &effectInfo);

			// Create Right 3rd Booster
			effectInfo.Position = csl::math::Vector3(1.2f, -0.02f, -1.82f);
			gocEffect->CreateEffectLoopEx(&JetBoosterEffects[6], &effectInfo);

			q = Eigen::Quaternionf(-transform.Rotation.W, -transform.Rotation.X,
				-transform.Rotation.Y, transform.Rotation.Z);
			q = Eigen::AngleAxisf(1.25f * M_PI, Eigen::Vector3f::UnitX()) * q;
			effectInfo.Rotation = csl::math::Quaternion(q.y(), q.z(), q.w(), q.x());

			// Create Right Front Booster
			effectInfo.Position = csl::math::Vector3(1, 0.02f, -2.3f);
			gocEffect->CreateEffectLoopEx(&JetBoosterEffects[7], &effectInfo);
		}

		void JetBoostersVisible(bool isEnable)
		{
			for (size_t i = 0; i < 10; i++)
			{
				if (((Effect::CEffectHandle*)((int*)&JetBoosterEffects[i] - 2))->IsValid())
				{
					((Effect::CEffectHandle*)((int*)&JetBoosterEffects[i] - 2))->SetVisible(isEnable);
				}
			}
		}
	};
}