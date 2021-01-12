#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "logger.cpp"
#include "Time.h"
#include "TimerCalling.h"
#include "Keyboard.h"
#include "Color.cpp"
#include "Vector2d.cpp"
#include "Collider.h"
#include "GFX.h"
#include "GFXRect.h"
#include "GameObject.h"
#include "Transform.h"

namespace Core {
	using Position = Transform::Position;
	using Scale = Transform::Scale;

	template<typename T, typename... TArgs>
	inline T& invokeGameObject(TArgs&&... args) {
		T* gameObject = new T(std::forward<TArgs>(args)...);
		Core::GameObject::invoke(*gameObject);
		return *gameObject;
	};
}
