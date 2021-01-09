#pragma once
#include "SDL.h"

namespace Core {
	class Keyboard {
	public:
		static void handleDown(const SDL_KeyboardEvent& event);
		static void handleUp();
		static bool isPressed(SDL_Keycode keycode);
	private:
		static SDL_Keycode m_keycode;
	};
}
