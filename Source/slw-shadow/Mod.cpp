#include "pch.h"
#include "ModLoader.h"

extern "C"
{
	void _declspec(dllexport) __cdecl Init(ModInfo_t* modInfo)
	{
		std::string dir = modInfo->CurrentMod->Path;
		dir = dir.substr(0, dir.length() - 7) + "disk\\sonic2013_patch_0\\";

		if (fileExists(dir + "Shadow.pac"))
		{
			// Replace Sonic.pac with Shadow.pac
			WRITE_MEMORY(ASLR(0x00DDDD1C), const char*, "Shadow.pac");

			// Replace Virtualsonic1p.pac with Shadow.pac
			WRITE_MEMORY(ASLR(0x00E02D98), const char*, "Shadow.pac");

			// Replace chr_virtualsonic_1p with chr_Sonic
			WRITE_MEMORY(ASLR(0x00E02E04), const char*, "chr_Sonic");

			// Repalce chr_sonic_spin_1p with chr_sonic_spin
			WRITE_MEMORY(ASLR(0x00E02DDC), const char*, "chr_sonic_spin");

			// Negate the call of app::ObjUtil::GetModelResource(&v4, (int)"chr_virtualsonic_antenna", (int)&v5);
			WRITE_NOP(ASLR(0x008F8C91), 5);

			slw_shadow::Player::CShadow::InstallPatches();
			slw_shadow::Player::CShadow::InstallHooks();

			if (fileExists(dir + "sound\\se_player_shadow.acb"))
			{
				slw_shadow::Player::CVisualHuman::InstallHooks();

				slw_shadow::GameModeStartUp::InstallHooks();
			}
		}

		if (fileExists(dir + "Lancelot.pac"))
		{
			// Replace Linksonic.pac with Lancelot.pac
			WRITE_MEMORY(ASLR(0x00E02C80), const char*, "Lancelot.pac");
			
			slw_shadow::Player::ShadowLancelotInfo::InstallHooks();

			if (*(int*)ASLR(0x00949330) != 0x81EC8B55)
				slw_shadow::WorldAreaMapInfo::InstallHooks();
		}

		if (fileExists(dir + "Rouge.pac"))
		{
			// Replace Tails.pac with Rouge.pac
			WRITE_MEMORY(ASLR(0x00DDDCD0), const char*, "Rouge.pac");
		}

		if (fileExists(dir + "Glider.pac"))
		{
			slw_shadow::Player::VehicleGliderInfo::InstallPatches();
			slw_shadow::Player::VehicleGliderInfo::InstallHooks();

			slw_shadow::Player::CGlider::InstallPatches();
			slw_shadow::Player::CGlider::InstallHooks();
		}

		// Replace Supersonic.pac with Supershadow.pac
		if (fileExists(dir + "Supershadow.pac"))
			WRITE_MEMORY(ASLR(0x00E02CA0), const char*, "Supershadow.pac");
		
		if (fileExists(dir + "Shadow2p.pac"))
		{
			// Replace Virtualsonic2p.pac with Shadow2p.pac
			WRITE_MEMORY(ASLR(0x00E02D84), const char*, "Shadow2p.pac");
			
			slw_shadow::Player::AndroidShadowInfo::InstallHooks();
		}
	}

	void _declspec(dllexport) __cdecl PostInit(ModInfo_t* modInfo)
	{
		auto* self = modInfo->CurrentMod;
		auto* api = modInfo->API;

		auto* other = api->FindMod("5C335265");
		if (other && self->Priority > other->Priority)
		{
			if (*(int*)ASLR(0x00949330) != 0x81EC8B55)
				slw_shadow::WorldAreaMapInfo::InstallHooks();
		}
	}
}