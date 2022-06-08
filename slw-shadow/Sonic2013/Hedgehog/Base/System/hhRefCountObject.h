#pragma once

namespace hh
{
    namespace base
    {
        class CRefCountObject
        {
        public:
            int RefCount{};

            virtual void Destructor(size_t deletingFlags) {}
        };
    }
}