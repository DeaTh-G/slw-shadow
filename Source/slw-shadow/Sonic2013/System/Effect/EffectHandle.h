#pragma once

namespace app::Effect
{
	class CEffectHandle
	{
	protected:
		int Data[3]{};

	private:
		inline static FUNCTION_PTR(bool, __thiscall, f_IsValid, ASLR(0x0047EE50), CEffectHandle* This);
		inline static FUNCTION_PTR(void, __thiscall, f_SetGlobalScaling, ASLR(0x0047EEC0), CEffectHandle* This, float scale);
		inline static FUNCTION_PTR(void, __thiscall, f_SetVisible, ASLR(0x0047EF60), CEffectHandle* This, bool isVisible);

	public:
		CEffectHandle()
		{
			for (size_t i = 0; i < 3; i++)
				Data[i] = 0;
		}

		bool IsValid() { return f_IsValid(this); }
		void SetGlobalScaling(float scale) { f_SetGlobalScaling(this, scale); }
		void SetVisible(bool isVisible) { f_SetVisible(this, isVisible); }
	};
}
