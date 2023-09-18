#pragma once

namespace app::game
{
    class GOCAnimationScript : public GOCAnimationSingle
    {
    private:
        inline static FUNCTION_PTR(void, __thiscall, f_RegisterCallback, ASLR(0x004B3400), GOCAnimationScript* This, int id, animation::AnimationCallback* pCallback);
        inline static FUNCTION_PTR(void, __thiscall, f_UnregisterCallback, ASLR(0x004B3410), GOCAnimationScript* This, int id);

    public:
        void RegisterCallback(int id, animation::AnimationCallback* pCallback) { f_RegisterCallback(this, id, pCallback); }
        void UnregisterCallback(int id) { f_UnregisterCallback(this, id); }
    };
}