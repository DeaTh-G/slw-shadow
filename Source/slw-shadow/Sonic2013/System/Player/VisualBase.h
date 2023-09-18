#pragma once

namespace app::Player
{
	class CVisualBase
	{
	private:
		inline static FUNCTION_PTR(bool, __thiscall, f_PlaySE, ASLR(0x008EFD50), CVisualBase* This, fnd::SoundHandle* handle, const char* cueName);
	
	public:
		CPlayer* m_pOwner{};
		CVisualGOC* m_pVisual{};
		game::GOCSound* m_pSound{};

	public:
		virtual ~CVisualBase() = default;

		bool PlaySE(fnd::SoundHandle* handle, const char* cueName) { return f_PlaySE(this, handle, cueName); }

		void StopSE(fnd::SoundHandle* handle) { handle->Stop(0); }
	};
}