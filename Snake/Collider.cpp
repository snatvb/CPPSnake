#include "Collider.h"

Core::Collider::Collider(GameObject& gameObject)
	: gameObject(gameObject)
{
}

void Core::Collider::calculateCollides(std::vector<GameObject*> gameObjects)
{
	for (auto* gameObject : gameObjects) {
		if (gameObject == nullptr || gameObject->collider == nullptr) {
			continue;
		}

		for (auto* otherGameObject : gameObjects) {
			if (otherGameObject == nullptr || otherGameObject->collider == nullptr || otherGameObject == gameObject) {
				continue;
			}
			if (gameObject->transform->position == otherGameObject->transform->position) {
				Logger::debug(gameObject->toString(), otherGameObject->toString());
				gameObject->onCollide(*otherGameObject->collider);
			}
		}
	}
}
