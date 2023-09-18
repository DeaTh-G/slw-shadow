#pragma once

namespace app::animation
{
	class CharactorAnimationSingle : public CharactorAnimation
	{
	private:
		inline static FUNCTION_PTR(const char*, __thiscall, f_GetCurrentAnimationName, ASLR(0x00414680), CharactorAnimationSingle* This);

	public:
		const char* GetCurrentAnimationName() { return f_GetCurrentAnimationName(this); }
	};
}