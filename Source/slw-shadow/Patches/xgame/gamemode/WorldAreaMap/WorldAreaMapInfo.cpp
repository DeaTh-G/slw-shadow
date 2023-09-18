#include "pch.h"
#include "WorldAreaMapInfo.h"

HOOK(void, __fastcall, LoadHook, ASLR(0x00948520), app::WorldAreaMapInfo* in_pThis, int* edx, app::CObjInfoFileLoader& loader)
{
    originalLoadHook(in_pThis, edx, loader);
 
    loader.Load("Lancelot.pac", 0x4001);
}

HOOK(void, __fastcall, InitializeHook, ASLR(0x00949330), app::WorldAreaMapInfo* in_pThis, void* edx, app::GameDocument& in_rDocument)
{
    originalInitializeHook(in_pThis, edx, in_rDocument);

    hh::ut::PackFile packFile = app::ObjUtil::GetPackFile("Lancelot.pac");

    in_pThis->SonicModel = app::ObjUtil::GetModelResource("chr_Linksonic", packFile);
    in_pThis->SonicSkeleton = app::ObjUtil::GetSkeletonResource("chr_Linksonic", packFile);
}

void slw_shadow::WorldAreaMapInfo::InstallHooks()
{
    INSTALL_HOOK(LoadHook);
    INSTALL_HOOK(InitializeHook);
}