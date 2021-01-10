#pragma once
#include <vector>
#include "Core.h"
#include "UIComponent.h"

class UIComponent;

class HUD {
public:
	HUD(SDL_Renderer& renderer);
	~HUD();

	void init();
	void render();

	template<typename T>
	T* getComponent();
private:
	SDL_Renderer* m_renderer;
	TTF_Font* m_font = nullptr;
	std::vector<UIComponent*> m_components;

	friend class UIComponent;
};

template<typename T>
inline T* HUD::getComponent()
{
	for (auto component : m_components) {
		if (auto uiScore = dynamic_cast<T*>(component)) {
			return uiScore;
		}
	}

	return nullptr;
}
