#pragma once

namespace app::game
{
    struct EffectCreateInfo
    {
    public:
        const char* Name;
        float field_04;
        int field_08;
        int	Padding;
        csl::math::Vector3 Position;
        csl::math::Quaternion Rotation;
        bool field_30;
        int	field_34;
        int	field_38;
        int	field_3C;
        fnd::GOCVisualModel* field_40;
        const char* field_44;
        int	field_48;
        int	field_4C;

        EffectCreateInfo()
        {
            Name = "";
            field_04 = 0;
            field_08 = 0;
            Padding = 0;
            Position = csl::math::Vector3(0, 0, 0);
            Rotation = csl::math::Quaternion(0, 0, 0, 1);
            field_30 = 0;
            field_34 = 0;
            field_38 = 0;
            field_3C = 0;
            field_40 = 0;
            field_44 = 0;
            field_48 = 0;
            field_4C = 0;
        }
    };

    class GOCEffect
    {
    private:
        inline static FUNCTION_PTR(void, __thiscall, f_CreateEffectLoopEx, ASLR(0x004BDDC0), GOCEffect* This, Effect::CEffectHandle* handle, EffectCreateInfo* info);

    public:
        void CreateEffectLoopEx(Effect::CEffectHandle* handle, EffectCreateInfo* info) { f_CreateEffectLoopEx(this, handle, info); }
    };
}