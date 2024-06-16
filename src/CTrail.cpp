#include "dllmain.h"

void CTrail::Process() {

	if (!g_Toggle.IsEnabled()) return;

	D3DXVECTOR3 pos;
	CPed::GetPosition(&pos);

	if (!points.empty())
		points[points.size() - 1] = pos;
	if (GetTickCount() - timeSinceLastCheck >= wait) {
		timeSinceLastCheck = GetTickCount();
		points.push_back(pos);
		if (points.size() > length)
			points.erase(points.begin());
	}
}

void CTrail::OnRender() {

	if (points.empty() || !g_Toggle.IsEnabled()) return;
	for (int i = 0; i < points.size() - 1; i++) {
		D3DXVECTOR3 firstPos(points[i]);
		D3DXVECTOR3 secondPos(points[i + 1]);

		if (IsPointOnScreen(&firstPos, 0) && IsPointOnScreen(&secondPos, 0)) {
			sColor color{};
            GetColor(&color, i);

			D3DXVECTOR3 s_firstPos, s_secondPos;
			CalcScreenCoors(&firstPos, &s_firstPos);
			CalcScreenCoors(&secondPos, &s_secondPos);

			render->Line(s_firstPos.x, s_firstPos.y, s_secondPos.x, s_secondPos.y, width, false, D3DCOLOR_ARGB(255, color.r, color.g, color.b));
		}
	}

}

void CTrail::Clear() {
	points.clear();
}

void CTrail::GetColor(sColor *pColor, int offset) {
	int tick = (int)(GetTickCount() / 1000) + offset;

	pColor->r = (int)round(sin(tick * 0.3) * 127 + 128);
	pColor->g = (int)round(sin(tick * 0.3 + 2) * 127 + 128);
	pColor->b = (int)round(sin(tick * 0.3 + 4) * 127 + 128);
}