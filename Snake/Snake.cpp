#include "Snake.h"

Snake::Snake(Core::Position& position) : GameObject()
{
	Logger::debug("Snake Constructor");
	transform->position = position;
}

Snake::~Snake()
{
}

void Snake::onInvoke()
{
	SnakeSegment& head = *new SnakeSegment(*this, transform->position, Snake::SEGMENT_SIZE);
	m_head = &head;
	childs.push_back(&head);
	GameObject::invoke(head);
	Logger::debug("Snake inited", transform->position.toString());
}

void Snake::update()
{
	m_handleInput();
	if (m_isGrowing) {
		m_addSection();
		m_isGrowing = false;
	}
	else {
		m_move();
	}
}

void Snake::subscribeOnDie(std::function<void()> handler)
{
	m_onDie = handler;
}

void Snake::onSegmentCollide(SnakeSegment& segment)
{
	Logger::debug("Snake died");
	if (m_onDie != nullptr) {
		m_onDie();
	}
}

void Snake::setSpeed(float speed)
{
	m_speed = speed;
}

void Snake::grow()
{
	m_isGrowing = true;
}

void Snake::m_addSection()
{
	Core::Position position = m_head->transform->position.clone();
	SnakeSegment& section = *new SnakeSegment(*this, position, Snake::SEGMENT_SIZE);
	section.setDirection(*m_head);
	section.move();
	section.prevSegment = m_head;
	m_head->nextSegment = &section;
	m_head = &section;
	childs.push_back(&section);
	GameObject::invoke(section);
}

void Snake::m_handleInput()
{
	if (Core::Keyboard::isPressed(SDL_KeyCode::SDLK_w)) {
		m_direction = SnakeSegment::Direction::Top;
	}
	else if (Core::Keyboard::isPressed(SDL_KeyCode::SDLK_s)) {
		m_direction = SnakeSegment::Direction::Bottom;
	}
	else if (Core::Keyboard::isPressed(SDL_KeyCode::SDLK_a)) {
		m_direction = SnakeSegment::Direction::Left;
	}
	else if (Core::Keyboard::isPressed(SDL_KeyCode::SDLK_d)) {
		m_direction = SnakeSegment::Direction::Right;
	}
}

void Snake::m_move()
{
	if (m_moveCooldown <= 0) {
		m_head->setDirection(m_direction);
		m_head->move();
		m_moveTail();
		m_moveCooldown = 1 / m_speed;
	}

	m_moveCooldown -= (float)Core::Time::delta.count();
}

void Snake::m_moveTail()
{
	for (auto* child : childs) {
		if (SnakeSegment* segment = dynamic_cast<SnakeSegment*>(child)) {
			if (segment == m_head) {
				continue;
			}

			segment->move();
			segment->takeNextSegmentDirection();
		}
	}
}
