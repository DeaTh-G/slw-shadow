#pragma once

namespace csl::math
{
    class alignas(16) Vector3
    {
    public:
        float X;
        float Y;
        float Z;
    };

    class alignas(16) Quaternion
    {
    public:
        float X;
        float Y;
        float Z;
        float W;
    };
}

namespace app::math
{
    class Transform
    {
    public:
        csl::math::Vector3 Position;
        csl::math::Quaternion Rotation;
        csl::math::Vector3 Scale;
        bool IsDirty;
    };
}