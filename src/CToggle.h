#pragma once

class CToggle {
private:
	bool enabled = false;
	bool keyPressed = false;
	int activateButton = VK_F2;
public:
	[[nodiscard]] bool IsEnabled() const { return enabled; }
	void OnUpdate();
};