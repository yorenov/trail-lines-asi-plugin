#include "dllmain.h"

void CToggle::OnUpdate() {
	if (!keyPressed && GetKeyState(activateButton) & 0x8000) {
		enabled = !enabled;
		CRender::AddMessageJumpQ(enabled ? "~g~ON" : "~r~OFF", 500, 0, false);
	}
	keyPressed = GetKeyState(activateButton);
}