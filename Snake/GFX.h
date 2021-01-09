#pragma once
#include "SDL.h"
#include "GameObject.h"

namespace Core {
	class GameObject;

	class GFX {
	public:
		GameObject& gameObject;
		virtual void render(SDL_Renderer& renderer) = 0;

		GFX(GameObject& gfxOverObject);
	};
}
