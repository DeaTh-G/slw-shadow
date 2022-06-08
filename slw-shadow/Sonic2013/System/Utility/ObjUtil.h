#pragma once

namespace app::ObjUtil
{
    inline static FUNCTION_PTR(int*, __cdecl, GetPackFile, ASLR(0x0073D830), int* file, const char* name);
    inline static FUNCTION_PTR(int*, __cdecl, GetModelResource, ASLR(0x0073D490), void* dataPtr, const char* name, int* packFile);
    inline static FUNCTION_PTR(int*, __cdecl, GetSkeletonResource, ASLR(0x0073D670), void* dataPtr, const char* name, int packFile);
    inline static FUNCTION_PTR(int*, __cdecl, GetAnimationScriptResource, ASLR(0x0073D7B0), void* dataPtr, const char* name, int packFile);
    inline static FUNCTION_PTR(int*, __cdecl, GetShadowModel, ASLR(0x0073D2F0), res::ResShadowModel* dataPtr, const char* name, int packFile);
}