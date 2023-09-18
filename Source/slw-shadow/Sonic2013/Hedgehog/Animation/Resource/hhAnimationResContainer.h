#pragma once

namespace app::animation
{
    class AnimationResContainer
    {
    private:
        inline static FUNCTION_PTR(void, __thiscall, f_LoadFromBuffer, ASLR(0x00412CA0), AnimationResContainer* This, int* a2, int a3);
        inline static FUNCTION_PTR(void, __thiscall, __ct, ASLR(0x00412D90), AnimationResContainer* This, csl::fnd::IAllocator* pAllocator);
        inline static FUNCTION_PTR(void, __thiscall, __dt, ASLR(0x00412D70), AnimationResContainer* This);

        int field_00;
        int field_04;
        int field_08;
        int field_0C;
        int field_10;
        int field_14;
        int field_18;
        int field_1C;
        int field_20;
        int field_24;
        int field_28;
        int field_2C;
        int field_30;
        int field_34;
        int field_38;

    public:
        AnimationResContainer(csl::fnd::IAllocator* pAllocator) { __ct(this, pAllocator); }
        ~AnimationResContainer() { __dt(this); }

        void LoadFromBuffer(int* a1, int a2) { f_LoadFromBuffer(this, a1, a2); }
    };
}