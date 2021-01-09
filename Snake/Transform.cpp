#include "Transform.h"

namespace Core {
	Transform::Transform(GameObject& gameObject)
		: gameObject(gameObject)
	{
		scale = Vector2d<float>(1, 1);
	}

	Transform::Transform(GameObject& gameObject, const Position& position)
		: Transform::Transform(gameObject)
	{
		this->position = Position::clone(position);
	}

	void Transform::move(int x, int y)
	{
		position.x += x;
		position.y += y;
	}

	void Transform::move(float x, float y)
	{
		position.x += (int)x;
		position.y += (int)y;
	}
}
