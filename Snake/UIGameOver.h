#pragma once
#include "HUD.h"

class UIComponent;

class UIGameOver : public UIComponent {
public:

	UIGameOver(HUD& hud)
		: UIComponent(hud) {}

	void setDisplay(bool display);
	bool isDisplay();
	void draw() override;
	void clean() override;

private:
	SDL_Rect m_rect;
	SDL_Color m_color = { 255, 255, 255 };
	SDL_Texture* m_texture;
	bool m_display = false;
};
