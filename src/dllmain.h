#pragma once
// trash including :(

#include <thread>
#include <vector>
#include <Windows.h>
#include <cstring>
#include <d3dx9.h>
#include <d3dx9math.h>

#include "CMain.h"
#include "CRender.h"
#include "CTrail.h"
#include "CPed.h"
#include "CToggle.h"

#include "direct3d9/CDirect3DData.h"
#include "direct3d9/d3drender.h"
#include "direct3d9/proxyIDirect3D9.h"
#include "direct3d9/proxyIDirect3DDevice9.h"

extern D3DPRESENT_PARAMETERS* g_pGTAPresent;
extern CMain g_Main;
extern CRender g_Render;
extern CTrail g_Trail;
extern CPed g_Ped;
extern CToggle g_Toggle;