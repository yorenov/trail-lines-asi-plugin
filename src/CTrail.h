#pragma once

struct sColor {
	int r;
	int g;
	int b;
};

struct CVector {
	float x, y, z;
};

class CTrail {
private:
	unsigned int length = 50;
	unsigned int wait = 30;
	float speed = 0.3;
	float width = 5;
	std::vector<D3DXVECTOR3> points;
	DWORD timeSinceLastCheck;
	static void GetColor(sColor *pColor, int offset);
public:
	void Process();
	void OnRender();
	void Clear();
};