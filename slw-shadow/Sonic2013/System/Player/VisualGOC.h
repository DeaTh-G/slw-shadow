#pragma once

namespace app::Player
{
	class CVisualGOC
	{
	private:
		inline static FUNCTION_PTR(const char*, __thiscall, f_GetCurrentVisualName, ASLR(0x008EF540), CVisualGOC* This);

	public:
		const char* GetCurrentVisualName() { return f_GetCurrentVisualName(this); }
	};
}