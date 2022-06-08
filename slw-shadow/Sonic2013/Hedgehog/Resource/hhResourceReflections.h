#pragma once

namespace app
{
	namespace res
	{
        class ResShadowModel
        {
        private:
            inline static FUNCTION_PTR(ResShadowModel*, __thiscall, __ct, ASLR(0x00908330), ResShadowModel* This, int a2);

            int field_00{};
            int field_04{};
            int field_08{};
            
        public:
            ResShadowModel() {};

            ResShadowModel(int a1) { __ct(this, a1); }
        };
	}
}

namespace hh::gfx::res
{
    class ResModel 
    {
    private:
        int* field_00{};
    };
}