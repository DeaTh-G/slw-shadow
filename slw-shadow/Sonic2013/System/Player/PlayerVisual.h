#pragma once

namespace app::Player
{
	class CPlayerVisual : public fnd::ReferencedObject, public CVisualBase
	{
	public:
		const char* m_pVisualName{};
		short m_Flags1{};
		short m_Flags2{};
		int* m_Effects{};
		int* m_Unit{};
		int* m_pGOCHolder{};
	};
}