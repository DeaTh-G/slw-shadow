#pragma once

namespace app::animation
{
	enum ETriggerValueType
	{
		eTriggerValueType_Enum,
		eTriggerValueType_Int,
		eTriggerValueType_Float,
		eTriggerValueType_String
	};

	typedef union
	{
		int m_Int;
		float m_Float;
		const char* m_String;
	} CallbackParam;
}