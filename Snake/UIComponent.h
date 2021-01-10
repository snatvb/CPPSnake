#pragma once
#include "HUD.h"

class HUD;

class UIComponent {
public:
	Core::Position position;

	UIComponent(HUD& hud, Core::Position& position);

	virtual void draw() = 0;

protected:
	HUD& m_hud;

	SDL_Renderer* m_getRenderer();
	TTF_Font* m_getFont();
};
