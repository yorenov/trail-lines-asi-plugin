#pragma once

class CRender {
public:
	static void InitializeHook();
	static void OnPresent();
	static void AddMessageJumpQ(const char* text, unsigned int time, unsigned short flag, bool bPreviousBrief);
};