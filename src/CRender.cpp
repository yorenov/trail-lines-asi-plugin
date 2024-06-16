#include "dllmain.h"

void CRender::InitializeHook() {
	pDirect3D9 = new proxyIDirect3D9(*(IDirect3D9**)0xC97C20);
	*(IDirect3D9**)0xC97C20 = pDirect3D9;
	pPresentParam = *(D3DPRESENT_PARAMETERS*)0xC9C040;
	*(IDirect3DDevice9**)0xC97C28 = new proxyIDirect3DDevice9(*(IDirect3DDevice9**)0xC97C28);
}

void CRender::OnPresent() {
	if (SUCCEEDED(render->BeginRender())) {
		
		g_Trail.OnRender();

		CD3DRender::EndRender();
	}
}

void CRender::AddMessageJumpQ(const char* text, unsigned int time, unsigned short flag, bool bPreviousBrief)
{
	((void(__cdecl*)(const char*, unsigned int, unsigned short, bool))0x69F1E0)(text, time, flag, bPreviousBrief);
}