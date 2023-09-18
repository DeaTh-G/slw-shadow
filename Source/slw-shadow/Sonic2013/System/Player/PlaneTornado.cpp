#include "pch.h"

HOOK(void, __fastcall, VehicleTornadoInfoLoadHook, ASLR(0x008F8F10), int* a1, int* edx, app::CObjInfoFileLoader& loader)
{
    originalVehicleTornadoInfoLoadHook(a1, edx, loader);
    loader.Load("Glider.pac", -1);
}

HOOK(void, __fastcall, CPlaneTornadoAddCallbackHook, ASLR(0x008EB820), app::Player::CPlaneTornado* This, void* edx, int* a2)
{
    originalCPlaneTornadoAddCallbackHook(This, edx, a2);

    app::fnd::GOCVisualModel* gocVisualModel = (app::fnd::GOCVisualModel*)app::GameObject::GetGOC((int*)This, (char*)ASLR(0x00D617C8));
    app::game::GOCEffect* gocEffect = (app::game::GOCEffect*)app::GameObject::GetGOC((int*)This, (char*)ASLR(0x00D642B4));

    app::Player::CreateGliderBoosters(gocVisualModel, gocEffect);
}

void app::Player::VehicleTornadoInfo::InstallPatches()
{
    // Replace Tornado.pac with Glider.pac in app::Player::VehicleTornadoInfo::Initialize
    WRITE_MEMORY_WITH_TYPE(ASLR(0x008F8FCB), uintptr_t, (uintptr_t)app::Player::GliderPacName);
}

void app::Player::VehicleTornadoInfo::InstallHooks() { INSTALL_HOOK(VehicleTornadoInfoLoadHook); }

void app::Player::CPlaneTornado::InstallPatches()
{
    // Raise effect slots for CPlaneTornado from 1 to 3
    WRITE_MEMORY(ASLR(0x008EBCA7), 0x03);

    // Remove effect From CPlaneTornado
    WRITE_MEMORY(ASLR(0x00E01234), 0x00);
}

void app::Player::CPlaneTornado::InstallHooks() { INSTALL_HOOK(CPlaneTornadoAddCallbackHook); }