#include "dllmain.h"

D3DPRESENT_PARAMETERS* g_pGTAPresent = (D3DPRESENT_PARAMETERS*)0xC9C040;

CMain g_Main;
CRender g_Render;
CTrail g_Trail;
CPed g_Ped;
CToggle g_Toggle;

[[noreturn]] void MainThread() {
    AllocConsole();
    while (true) {
        Sleep(1);
        g_Main.OnUpdate();
    }
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        std::thread(MainThread).detach();
        break;
    }
    return TRUE;

}

