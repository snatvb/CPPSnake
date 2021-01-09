#pragma once
#include "Vector2d.cpp"
#include "GameObject.h"

namespace Core {
	class GameObject;

	class Transform
	{
	public:
		using Position = Vector2d<int>;
		using Scale = Vector2d<float>;

		Scale scale;
		Position position;
		Position localPosition;
		GameObject& gameObject;

		Transform(GameObject& gameObject);
		Transform(GameObject& gameObject, const Position& position);

		void move(int x, int y);
		void move(float x, float y);
	};
}
