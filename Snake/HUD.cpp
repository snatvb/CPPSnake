#include "Core.h"
#include "HUD.h"
#include "UIScore.h"

HUD::HUD(SDL_Renderer& renderer)
	: m_renderer(&renderer)
{
}

HUD::~HUD()
{
	for (auto component : m_components) {
		delete component;
	}
}

void HUD::init()
{
	if (TTF_Init() == -1) {
		Logger::debug("Error SDL_ttf initialize");
	}
	m_font = TTF_OpenFont("fonts/Roboto-Light.ttf", 18);

	auto scorePosition = Core::Position(10, 10);
	auto score = new UIScore(*this, scorePosition);
	score->setScore(0);
	m_components.push_back(score);
}

void HUD::render()
{
	for (auto component : m_components) {
		component->draw();
	}
	/*SDL_Color white = { 255, 255, 255 };

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(m_font, "test", white);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);
	SDL_FreeSurface(surfaceMessage);

	int pos = 10;
	SDL_QueryTexture(texture, nullptr, nullptr, &pos, &pos);
	SDL_Rect rect;
	rect.x = pos;
	rect.y = pos;
	rect.w = 100;
	rect.h = 100;
	SDL_RenderCopy(m_renderer, texture, nullptr, &rect);
	SDL_DestroyTexture(texture);*/
}
