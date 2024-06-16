#include "dllmain.h"

void CPed::GetPosition(D3DXVECTOR3* pPos) {
	auto* xyzStructAddr = (DWORD*)((*(DWORD*)(0xB6F5F0)) + 0x14);
	pPos->x = *(float*)((*xyzStructAddr) + 0x30);
	pPos->y = *(float*)((*xyzStructAddr) + 0x34);
	pPos->z = *(float*)((*xyzStructAddr) + 0x38);
}