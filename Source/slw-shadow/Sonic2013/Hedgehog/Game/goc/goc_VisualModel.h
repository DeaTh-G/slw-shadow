#pragma once

namespace app::fnd
{
	class GOCVisualModel
	{
	private:
		inline static FUNCTION_PTR(void, __thiscall, f_GetNodeTransform, ASLR(0x004951F0), GOCVisualModel* This, int a2, const char* nodeName, math::Transform* transform);
		inline static FUNCTION_PTR(void, __thiscall, f_SetMaterialColor, ASLR(0x00495140), GOCVisualModel* This, float* a2);

	public:
		void GetNodeTransform(int a1, const char* nodeName, math::Transform* transform) { f_GetNodeTransform(this, a1, nodeName, transform); }
		void SetMaterialColor(float* color) { f_SetMaterialColor(this, color); }
	};
}