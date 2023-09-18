#pragma once

namespace app
{
	class GameMode
	{
	public:
		inline static FUNCTION_PTR(bool, __stdcall, LoadFile, ASLR(0x004AC840), const char* fileName, fnd::FileLoaderParam* loader);
	};
}