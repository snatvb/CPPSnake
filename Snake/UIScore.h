#pragma once
#include "HUD.h"

class UIComponent;

class UIScore : public UIComponent {
public:

	UIScore(HUD& hud, Core::Position& position)
		: UIComponent(hud, position) {}

	void setScore(int score);
	void draw() override;

private:
	SDL_Rect m_rect;
	SDL_Color m_color = { 255, 255, 255 };
	SDL_Texture* m_texture;
};
