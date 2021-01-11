#include "Core.h"
#include "HUD.h"
#include "UIScore.h"
#include "UIGameOver.h"

HUD::HUD(SDL_Renderer& renderer, Size& size)
	: m_renderer(&renderer), size(size)
{
}

HUD::~HUD()
{
	for (auto component : m_components) {
		component->clean();
		delete component;
	}

	TTF_CloseFont(m_font);
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
	m_components.push_back(new UIGameOver(*this));
}

void HUD::render()
{
	for (auto component : m_components) {
		component->draw();
	}
}
