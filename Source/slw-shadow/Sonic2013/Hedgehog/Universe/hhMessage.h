#pragma once

namespace app::fnd
{
    class Message
    {
    private:
        inline static FUNCTION_PTR(Message*, __thiscall, f_Clone, ASLR(0x0049A630), Message* This);
        inline static FUNCTION_PTR(Message*, __thiscall, __dt, ASLR(0x004AC6A0), Message* This, int a2);

    public:
        int Type;
        int field_08;
        int field_0C;
        short field_10;
        short field_12;
        unsigned int field_14;

        inline static FUNCTION_PTR(Message*, __thiscall, __ct, ASLR(0x0049A5F0), Message* This, int type);

        virtual void Clone() { f_Clone(this); }
        virtual ~Message()
        {
            __dt(this, 0);
        }

        Message()
        {
            Type = 0;
            field_08 = 0;
            field_0C = 0;
            field_10 = 0;
            field_12 = 0;
            field_14 = -1;
        }
    };
}