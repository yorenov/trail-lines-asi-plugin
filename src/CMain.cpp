#include "dllmain.h"

void CMain::OnUpdate() {
	
	if (!gameInit) {
		if (*reinterpret_cast<unsigned char*>(0xC8D4C0) == 9) {
			gameInit = true;
			CRender::InitializeHook();
		}
	}
	if (gameInit) {
		g_Trail.Process();
		g_Toggle.OnUpdate();
	}
}