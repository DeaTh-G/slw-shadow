#include "pch.h"

using namespace app::Player;

bool IsDLCRestorationOn = false;

extern "C"
{
	void _declspec(dllexport) __cdecl Init(ModInfo* modInfo)
	{
		IsDLCRestorationOn = GetModuleHandle(L"DLC-Restoration.dll");

		std::string dir = modInfo->CurrentMod->Path;
		dir = dir.substr(0, dir.length() - 7) + "disk\\sonic2013_patch_0\\";

		if (fileExists(dir + "Shadow.pac"))
		{
			// Replace Sonic.pac with Shadow.pac
			WRITE_MEMORY(ASLR(0x00DDDD1C), 0x53, 0x68, 0x61, 0x64, 0x6F, 0x77, 0x2E, 0x70, 0x61, 0x63);

			// Replace Virtualsonic1p.pac with Shadow.pac
			WRITE_MEMORY(ASLR(0x00E02D98), 0x53, 0x68, 0x61, 0x64, 0x6F, 0x77, 0x2E, 0x70, 0x61, 0x63, 0x00);

			// Replace chr_virtualsonic_1p with chr_Sonic
			WRITE_MEMORY(ASLR(0x00E02E04), 0x63, 0x68, 0x72, 0x5F, 0x53, 0x6F, 0x6E, 0x69, 0x63, 0x00);

			// Repalce chr_sonic_spin_1p with chr_sonic_spin
			WRITE_MEMORY(ASLR(0x00E02DDC), 0x63, 0x68, 0x72, 0x5F, 0x73, 0x6F, 0x6E, 0x69, 0x63, 0x5F, 0x73, 0x70, 0x69, 0x6E, 0x00);

			// Negate the call of app::ObjUtil::GetModelResource(&v4, (int)"chr_virtualsonic_antenna", (int)&v5);
			WRITE_MEMORY(ASLR(0x008F8C91), 0x90, 0x90, 0x90, 0x90, 0x90);

			CVisualSonic::InstallHooks();

			CSonic::InstallPatches();
			CSonic::InstallHooks();

			if (fileExists(dir + "sound\\se_player_shadow.acb"))
			{
				CVisualHuman::InstallHooks();

				app::GameModeStartUp::InstallHooks();
			}
		}

		if (fileExists(dir + "Lancelot.pac"))
		{
			// Replace Linksonic.pac with Lancelot.pac
			WRITE_MEMORY(ASLR(0x00E02C80), 0x4C, 0x61, 0x6E, 0x63, 0x65, 0x6C, 0x6F, 0x74, 0x2E, 0x70, 0x61, 0x63, 0x00);
			
			SonicZeldaInfo::InstallHooks();

			if (*(int*)ASLR(0x00949330) != 0x81EC8B55)
				app::WorldAreaMapInfo::InstallHooks();
		}

		if (fileExists(dir + "Rouge.pac"))
		{
			// Replace Tails.pac with Rouge.pac
			WRITE_MEMORY(ASLR(0x00DDDCD0), 0x52, 0x6F, 0x75, 0x67, 0x65, 0x2E, 0x70, 0x61, 0x63);
		}

		if (fileExists(dir + "Glider.pac"))
		{
			VehicleTornadoInfo::InstallPatches();
			VehicleTornadoInfo::InstallHooks();

			CPlaneTornado::InstallPatches();
			CPlaneTornado::InstallHooks();
		}

		// Replace Supersonic.pac with Supershadow.pac
		if (fileExists(dir + "Supershadow.pac"))
			WRITE_MEMORY(ASLR(0x00E02CA0), 0x53, 0x75, 0x70, 0x65, 0x72, 0x73, 0x68, 0x61, 0x64, 0x6F, 0x77, 0x2E, 0x70, 0x61, 0x63);
		
		if (fileExists(dir + "Shadow2p.pac"))
		{
			// Replace Virtualsonic2p.pac with Shadow2p.pac
			WRITE_MEMORY(ASLR(0x00E02D84), 0x53, 0x68, 0x61, 0x64, 0x6F, 0x77, 0x32, 0x70, 0x2E, 0x70, 0x61, 0x63, 0x00);
			
			app::Player::VirtualSonicInfo::InstallHooks();
		}
	}

	void _declspec(dllexport) __cdecl PostInit(ModInfo* modInfo)
	{
		if (!IsDLCRestorationOn && GetModuleHandle(L"DLC-Restoration.dll"))
			if (*(int*)ASLR(0x00949330) != 0x81EC8B55)
				app::WorldAreaMapInfo::InstallHooks();
	}
}