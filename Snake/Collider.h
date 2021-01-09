#pragma once
#include <vector>
#include "GameObject.h"
#include "logger.cpp"

namespace Core {
	class GameObject;

	class Collider {
	public:
		GameObject& gameObject;

		Collider(GameObject& gameObject);

		static void calculateCollides(std::vector<GameObject*> gameObjects);
	};
}
