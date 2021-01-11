#pragma once
#include <vector>
#include <map>
#include <functional>
#include "SDL.h"

namespace Core {
	class Keyboard {
	public:
		using Subscriber = std::function<void()>;
		using Subscribers = std::map<SDL_Keycode, std::vector<Subscriber>>;

		static void handleDown(const SDL_KeyboardEvent& event);
		static void handleUp();
		static bool isPressed(SDL_Keycode keycode);
		static SDL_Keycode getKeycodePressed();

	private:
		static SDL_Keycode m_keycode;
	};
}
