#pragma once

namespace app::fnd
{
	class HandleBase
	{
	private:
		inline static FUNCTION_PTR(bool, __thiscall, f_IsValid, ASLR(0x004999F0), HandleBase* This);

	public:
		bool IsValid() { return f_IsValid(this); }
	};

	template<class T>
	class Handle : public HandleBase {};
}