#include "SnakeSegment.h"
#include "SnakeGame.h"

SnakeSegment::SnakeSegment(Snake& snake, const Core::Position& position, short int segmentSize)
	: m_segmentSize(segmentSize)
{
	parent = &snake;
	transform->position = Core::Position::clone(position);
}

void SnakeSegment::onInvoke()
{
	auto rect = new Core::GFXRect(*this, Vector2d<int>(m_segmentSize, m_segmentSize));
	rect->fill();
	gfx = rect;
	collider = new Core::Collider(*this);
}

void SnakeSegment::update()
{
	if (transform->position.x >= SnakeGame::windowSize.x) {
		transform->position.x = 0;
	} else if (transform->position.x < 0) {
		transform->position.x = SnakeGame::windowSize.x - Snake::SEGMENT_SIZE;
	}


	if (transform->position.y >= SnakeGame::windowSize.y) {
		transform->position.y = 0;
	}
	else if (transform->position.y < 0) {
		transform->position.y = SnakeGame::windowSize.y - Snake::SEGMENT_SIZE;
	}
}

void SnakeSegment::onCollide(Core::Collider& collider)
{
	if (SnakeSegment* segment = dynamic_cast<SnakeSegment*>(&collider.gameObject)) {
		if (Snake* snake = dynamic_cast<Snake*>(parent)) {
			snake->onSegmentCollide(*segment);
		}
	}
}

void SnakeSegment::move()
{
	int step = (int)Snake::SEGMENT_SIZE;
	switch (m_direction) {
	case Direction::Left:
		transform->move(step * -1, 0);
		break;

	case Direction::Top:
		transform->move(0, step * -1);
		break;

	case Direction::Right:
		transform->move(step, 0);
		break;

	case Direction::Bottom:
		transform->move(0, step);
		break;
	}
}

void SnakeSegment::setDirection(Direction direction)
{
	if (m_isValidDirection(direction)) {
		m_direction = direction;
	}
}

void SnakeSegment::setDirection(SnakeSegment& segment)
{
	m_direction = segment.m_direction;
}

Direction SnakeSegment::getDirection()
{
	return m_direction;
}

void SnakeSegment::takeNextSegmentDirection()
{
	if (nextSegment != nullptr) {
		m_direction = nextSegment->m_direction;
	}
}


std::string SnakeSegment::toString()
{
	return "SnakeSegment";
}

inline bool SnakeSegment::m_isValidDirection(Direction direction)
{
	switch (m_direction)
	{
	case Direction::Left:
		return direction != Direction::Right;
	case Direction::Top:
		return direction != Direction::Bottom;
	case Direction::Right:
		return direction != Direction::Left;
	case Direction::Bottom:
		return direction != Direction::Top;
	default:
		return true;
	}
}
