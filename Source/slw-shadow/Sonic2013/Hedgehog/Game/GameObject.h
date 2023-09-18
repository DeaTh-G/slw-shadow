#pragma once

namespace app
{
    class GameObject : public hh::base::CRefCountObject, public fnd::CLeafActor
    {
    private:
        inline static FUNCTION_PTR(bool, __thiscall, f_ActorProc, ASLR(0x0049D0A0), CActor* This, int id, void* data);
        inline static FUNCTION_PTR(bool, __thiscall, f_ProcessMessage, ASLR(0x0049CD10), CActor* This, fnd::Message& message);
        inline static FUNCTION_PTR(void, __thiscall, __ct, ASLR(0x0049CD60), GameObject* This);
        inline static FUNCTION_PTR(void, __thiscall, __dt, ASLR(0x0049D070), GameObject* This, size_t flags);
        inline static FUNCTION_PTR(GameObject*, __cdecl, f_new, ASLR(0x0049CAD0), size_t size);

    public:
        int field_24[0x2B]{};

        GameObject() { __ct(this); }

        GameObject(size_t dummy) {}

        void Destructor(size_t deletingFlags) override
        {
            __dt(this, deletingFlags);
        }

        virtual void AddCallback(GameDocument* gameDocument) {};
        virtual void RemoveCallback(GameDocument* gameDocument) {};
        virtual void UpdatePhase(const int& updateInfo, int phase) {};
        bool ActorProc(int id, void* data) override { return f_ActorProc(this, id, data); }
        bool ProcessMessage(fnd::Message& message) override { return f_ProcessMessage(this, message); };

        void* operator new(size_t size) { return f_new(size); }

        void operator delete(void* obj)
        {
            (*(*(csl::fnd::IAllocator***)ASLR(0x00FD3FC4) + 3))->Free(obj);
        }

        static csl::fnd::IAllocator* GetAllocator()
        {
            return (*(*(csl::fnd::IAllocator***)ASLR(0x00FD3FC4) + 3));
        }

        inline static FUNCTION_PTR(int*, __thiscall, GetGOC, ASLR(0x0049D430), int* This, char* componentName);
    };
}