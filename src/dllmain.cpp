#include "includes.h"
#include "memory/scanner.h"
#include "memory.h"
#include "suspender/suspender.h"

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


DWORD WINAPI Thread(HMODULE hModule)
{

    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);

    //const char* DMOLog_Pattern = "53 8B DC 83 EC ?? 83 E4 F8 83 C4 ?? 55 8B 6B ?? 89 6C 24 04 8B EC 64 A1 ?? ?? ?? ?? 6A FF";
    //uintptr_t DMOLog = scanner::find_pattern(DMOProtect_DLL, end, DMOLog_Pattern, 4);

    

    while (true)
    {

        if (GetAsyncKeyState(VK_NUMPAD4) & 1)
        {
            
        }

        if (GetAsyncKeyState(VK_NUMPAD9) & 0x8000)
        {
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
            Beep(500, 500);
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
        HANDLE hThread = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)Thread, hModule, 0, nullptr);
        if (hThread != nullptr)
        {
            CloseHandle(hThread);
        }
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

