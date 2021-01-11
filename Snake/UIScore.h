#pragma once
#include "HUD.h"

class UIComponent;

class UIScore : public UIComponent {
public:

	UIScore(HUD& hud, Core::Position& position)
		: UIComponent(hud, position) {}
	~UIScore();

	void setScore(int score);
	void draw() override;
	void clean() override;

private:
	SDL_Rect m_rect;
	SDL_Color m_color = { 255, 255, 255 };
	SDL_Texture* m_texture;
};
