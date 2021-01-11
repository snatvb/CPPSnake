#include "UIGameOver.h"

inline SDL_Rect getCenterRect(HUD& hud, SDL_Surface& surface) {
	SDL_Rect rect;
	rect.x = (hud.size.x / 2) - (surface.w / 2);
	rect.y = (hud.size.y / 2) - (surface.h / 2);
	rect.w = surface.w;
	rect.h = surface.h;

	return rect;
}

void UIGameOver::setDisplay(bool display)
{
	if (display) {
		SDL_Surface* surface = TTF_RenderText_Blended(m_getFont(), "Game Over", m_color);
		m_texture = SDL_CreateTextureFromSurface(m_getRenderer(), surface);
		m_rect = getCenterRect(m_hud, *surface);
		SDL_FreeSurface(surface);
	}
	else {
		clean();
	}
	m_display = display;
}

bool UIGameOver::isDisplay()
{
	return m_display;
}

void UIGameOver::draw()
{
	if (m_display) {
		SDL_RenderCopy(m_getRenderer(), m_texture, nullptr, &m_rect);
	}
}

void UIGameOver::clean()
{
	SDL_DestroyTexture(m_texture);
}
