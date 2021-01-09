#pragma once
#include <functional>
#include "Core.h"

class Eat : public Core::GameObject {
public:
	int score = 1;

	Eat(Core::Transform::Position& position, short int size, std::function<void(Eat& eat)> onEat);

	void onCollide(Core::Collider& collider) override;

	std::string toString() override;

private:
	std::function<void(Eat& eat)> m_onEat;
};
