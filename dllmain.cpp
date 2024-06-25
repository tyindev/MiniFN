#include <Windows.h>
#include <iostream>
#include "SDK/SDK.hpp"
#include "minihook/minhook.h"

DWORD WINAPI InitSwagShit(LPVOID)
{
    AllocConsole();

    FILE* fptr;
    freopen_s(&fptr, "CONOUT$", "w+", stdout);

    SetConsoleTitleA("Mini FN");

    MH_Initialize();

    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dllshits, LPVOID lpReserved)
{
    switch (dllshits)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, InitSwagShit, 0, 0, 0);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
    }
    return TRUE;
}
