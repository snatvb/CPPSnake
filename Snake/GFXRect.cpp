#include "GFXRect.h"

Core::GFXRect::GFXRect(GameObject& gfxGameObject, const Vector2d<int> size)
	: GFX(gfxGameObject), size(size)
{
}

void Core::GFXRect::render(SDL_Renderer& renderer)
{
	auto& transform = gameObject.transform;
	SDL_Rect rect;
	rect.x = transform->position.x;
	rect.y = transform->position.y;
	rect.w = (int)(size.x * transform->scale.x);
	rect.h = (int)(size.y * transform->scale.y);
	SDL_SetRenderDrawColor(&renderer, 255, 255, 255, 255);
	if (m_isFill) {
		SDL_RenderFillRect(&renderer, &rect);
	} else {
		SDL_RenderDrawRect(&renderer, &rect);
	}
}

void Core::GFXRect::fill()
{
	m_isFill = true;
}

void Core::GFXRect::unFill()
{
	m_isFill = false;
}

bool Core::GFXRect::isFill()
{
	return m_isFill;
}
