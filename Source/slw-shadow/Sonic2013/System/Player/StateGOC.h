#pragma once

namespace app::Player
{
	class CStateGOC
	{
	private:
		inline static FUNCTION_PTR(const char*, __thiscall, f_GetCurrentAnimationName, ASLR(0x0085B740), CStateGOC* This);
		inline static FUNCTION_PTR(int, __thiscall, f_GetCurrentState, ASLR(0x0085AA90), CStateGOC* This);

	public:
		const char* GetCurrentAnimationName() { return f_GetCurrentAnimationName(this); }
		int GetCurrentState() { return f_GetCurrentState(this); }
	};
}