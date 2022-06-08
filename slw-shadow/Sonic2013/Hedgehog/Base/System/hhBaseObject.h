#pragma once

namespace app::fnd
{
    class BaseObject
    {
    public:
        virtual void Destructor(size_t deletingFlags) {};
    };
}