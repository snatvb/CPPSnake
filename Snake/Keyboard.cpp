#include "Keyboard.h"

SDL_Keycode Core::Keyboard::m_keycode = SDLK_UNKNOWN;

void Core::Keyboard::handleDown(const SDL_KeyboardEvent& event)
{
	Core::Keyboard::m_keycode = event.keysym.sym;
}

void Core::Keyboard::handleUp()
{
	Core::Keyboard::m_keycode = SDLK_UNKNOWN;
}

bool Core::Keyboard::isPressed(SDL_Keycode keycode)
{
	return Core::Keyboard::m_keycode == keycode;
}

SDL_Keycode Core::Keyboard::getKeycodePressed()
{
	return m_keycode;
}

