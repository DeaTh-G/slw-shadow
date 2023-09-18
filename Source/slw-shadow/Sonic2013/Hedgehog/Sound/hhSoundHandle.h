#pragma once

namespace app::fnd
{
	class SoundHandle : public Handle<SoundHandleObj>
	{
	protected:
		int Data[3]{};
		
	private:
		inline static FUNCTION_PTR(void, __thiscall, f_Stop, ASLR(0x004A1FE0), SoundHandle* This, float fade);

	public:
		SoundHandle()
		{
			for (size_t i = 0; i < 3; i++)
				Data[i] = 0;
		}

		void Stop(float fade) { f_Stop(this, fade); }
	};
}