#include "Eat.h"

Eat::Eat(Core::Transform::Position& position, short int size, std::function<void(Eat& eat)> onEat)
	: GameObject(), m_onEat(onEat)
{
	transform->position = position.clone();
	gfx = new Core::GFXRect(*this, Size(size, size));
	collider = new Core::Collider(*this);
}

void Eat::onCollide(Core::Collider& collider)
{
	m_onEat(*this);
}

std::string Eat::toString()
{
	return "Eat";
}

