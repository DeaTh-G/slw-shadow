#pragma once

namespace app::fnd
{
    class GOCTransform
    {
    private:
        inline static FUNCTION_PTR(void, __thiscall, __dt, ASLR(0x00494B90), GOCTransform* This, size_t deletingFlags);

    public:
        int Data[0x78]{};

        ~GOCTransform() { __dt(this, 0); }
    };
}