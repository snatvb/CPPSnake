#include <string>
#include "UIScore.h"

void UIScore::setScore(int score)
{
	if (m_texture != nullptr) {
		clean();
	}

	m_rect.x = position.x;
	m_rect.y = position.y;
	SDL_Surface* surface = TTF_RenderText_Blended(m_getFont(), ("score: " + std::to_string(score)).c_str(), m_color);
	m_texture = SDL_CreateTextureFromSurface(m_getRenderer(), surface);
	m_rect.w = surface->w;
	m_rect.h = surface->h;
	SDL_FreeSurface(surface);
}

void UIScore::draw()
{
	SDL_RenderCopy(m_getRenderer(), m_texture, nullptr, &m_rect);
}

void UIScore::clean()
{
	SDL_DestroyTexture(m_texture);
}
