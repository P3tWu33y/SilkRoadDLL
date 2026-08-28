#include "includes.h"
#include "memory/scanner.h"
#include "memory.h"
#include "suspender/suspender.h"
#include "globals.h"
#include <atomic>
#include <thread>

#pragma comment(linker, "/export:GetFileVersionInfoA=C:\\Windows\\System32\\version.GetFileVersionInfoA")
#pragma comment(linker, "/export:GetFileVersionInfoByHandle=C:\\Windows\\System32\\version.GetFileVersionInfoByHandle")
#pragma comment(linker, "/export:GetFileVersionInfoExW=C:\\Windows\\System32\\version.GetFileVersionInfoExW")
#pragma comment(linker, "/export:GetFileVersionInfoSizeA=C:\\Windows\\System32\\version.GetFileVersionInfoSizeA")
#pragma comment(linker, "/export:GetFileVersionInfoSizeExW=C:\\Windows\\System32\\version.GetFileVersionInfoSizeExW")
#pragma comment(linker, "/export:GetFileVersionInfoSizeW=C:\\Windows\\System32\\version.GetFileVersionInfoSizeW")
#pragma comment(linker, "/export:GetFileVersionInfoW=C:\\Windows\\System32\\version.GetFileVersionInfoW")
#pragma comment(linker, "/export:VerQueryValueA=C:\\Windows\\System32\\version.VerQueryValueA")
#pragma comment(linker, "/export:VerQueryValueW=C:\\Windows\\System32\\version.VerQueryValueW")

ThreadSuspender suspender;
std::atomic_bool VacSwitch{ false };


void PrintName(const std::uint16_t* name)
{
    if (!name)
        return;

    for (int i = 0; i < 13; ++i)
    {
        if (name[i] == 0)
            break;

        std::cout << static_cast<char>(name[i]);
    }
}

void PrintAllEntities()
{
    Entity* hero = GetHero();

    if (!hero) {
        std::cout << "hero == nullptr\n";
        return;
    }

    EntityListNode* head = GetEntityListHead();

    std::cout << "Head node: 0x"
        << std::hex
        << reinterpret_cast<std::uintptr_t>(head)
        << std::dec
        << '\n';

    if (!head)
        return;

    EntityListNode* node = head;

    constexpr int MAX_ENTITIES = 400;

    for (int i = 0; i < MAX_ENTITIES; ++i)
    {
        if (!node)
        {
            std::cout << "node == nullptr\n";
            break;
        }

        Entity* entity = entityFromNode(node);

        std::cout << "\n[" << i << "]\n";

        std::cout << "Node:   0x"
            << std::hex
            << reinterpret_cast<std::uintptr_t>(node)
            << '\n';

        std::cout << "Entity: 0x"
            << reinterpret_cast<std::uintptr_t>(entity)
            << '\n';

        std::cout << "Name ptr: 0x"
            << reinterpret_cast<std::uintptr_t>(entity->name)
            << std::dec
            << '\n';


        if (entity->name)
        {
            std::wcout << L"Name: ["
                << reinterpret_cast<const wchar_t*>(entity->name)
                << L"]\n";

            std::cout << "Name: [";
            PrintName(entity->name);
            std::cout << "]\n";
        }
        else
        {
            std::cout << "Name pointer is NULL\n";
        }

        // We set the entities coordinates to ours.
        entity->x = hero->x;
        entity->y = hero->y;

        std::cout << "Next:   0x"
            << std::hex
            << reinterpret_cast<std::uintptr_t>(node->next)
            << std::dec
            << '\n';

        node = node->next;

        if (node == head)
        {
            std::cout << "\nReturned to head.\n";
            break;
        }
    }
}

void VacuumAll()
{
    while (true)
    {
        if (VacSwitch.load()) {
            Entity* hero = GetHero();

            if (!hero) {
                std::cout << "hero == nullptr\n";
                return;
            }

            EntityListNode* head = GetEntityListHead();

            if (!head)
                return;

            //std::cout << "Head node: 0x"
            //    << std::hex
            //    << reinterpret_cast<std::uintptr_t>(head)
            //    << std::dec
            //    << '\n';

            EntityListNode* node = head;

            constexpr int MAX_ENTITIES = 400;

            for (int i = 0; i < MAX_ENTITIES; ++i)
            {
                if (!node)
                {
                    //std::cout << "node == nullptr\n";
                    break;
                }

                Entity* entity = entityFromNode(node);

                // We set the entities coordinates to ours.
                entity->x = hero->x;
                entity->y = hero->y;

                // We go to the next node
                node = node->next;

                if (node == head)
                {
                    //std::cout << "\nReturned to head.\n";
                    break;
                }
            }
        }
        Sleep(1);
    }
}

DWORD WINAPI Thread(HMODULE hModule)
{

    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);

    std::thread ourThread(VacuumAll);

    //const char* DMOLog_Pattern = "53 8B DC 83 EC ?? 83 E4 F8 83 C4 ?? 55 8B 6B ?? 89 6C 24 04 8B EC 64 A1 ?? ?? ?? ?? 6A FF";
    //uintptr_t DMOLog = scanner::find_pattern(DMOProtect_DLL, end, DMOLog_Pattern, 4);

    

    while (true)
    {

        if (GetAsyncKeyState(VK_NUMPAD4) & 1)
        {
            
        }

        if (GetAsyncKeyState(VK_NUMPAD9) & 0x8000)
        {
            system("cls");
            PrintAllEntities();
            Beep(500, 500);
        }

        if (GetAsyncKeyState(VK_NUMPAD7) & 0x8000)
        {
            Beep(500, 500);
        }

        if (GetAsyncKeyState(VK_NUMPAD8) & 0x8000)
        {
            Beep(500, 500);
        }

        if (GetAsyncKeyState(VK_NUMPAD1) & 0x8000)
        {

            bool newState = !VacSwitch.load();
            VacSwitch.store(newState);

            if (newState)
            {
                Beep(500, 500);
            }
            else
            {
                Beep(250, 250);
            }
            
        }

        if (GetAsyncKeyState(VK_NUMPAD2) & 0x8000)
        {
            Beep(500, 500);
        }

        if (GetAsyncKeyState(VK_NUMPAD3) & 0x8000)
        {
            Beep(500, 500);
        }

        if (GetAsyncKeyState(VK_NUMPAD5) & 0x8000)
        {
            Beep(500, 500);
        }


        if (GetAsyncKeyState(VK_NUMPAD6) & 0x8000)
        {
            Beep(500, 500);
        }

        if (GetAsyncKeyState(VK_F9) & 0x8000)
        {
            Sleep(1000);
        }


        // exit condition: if you want to cleanly shutdown the thread, check a flag here.
        Sleep(1);
    }

    fclose(f);
    FreeConsole();
    FreeLibraryAndExitThread(hModule, 0);
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        HANDLE hThread = CreateThread(
            nullptr,
            0,
            (LPTHREAD_START_ROUTINE)Thread,
            hModule,
            0,
            nullptr
        );

        if (hThread)
            CloseHandle(hThread);

        break;
    }

    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
        break;
    }
    return TRUE;
}



