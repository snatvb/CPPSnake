#pragma once
#include "SDL.h"
#include "GameObject.h"
#include "Vector2d.cpp"
#include "Color.cpp"

namespace Core {

	class GFXRect : public GFX {
	public:
		Vector2d<int> size;
		Color color;

		GFXRect(GameObject& gfxGameObject, const Vector2d<int> size);

		void render(SDL_Renderer& renderer) override;
		void fill();
		void unFill();
		bool isFill();

	private:
		bool m_isFill = false;
	};
}
