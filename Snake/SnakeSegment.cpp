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
	Logger::debug("hrum hrum");
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

SnakeSegment::Direction SnakeSegment::getDirection()
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
	if (m_direction == Direction::Left) {
		return direction != Direction::Right;
	}

	if (m_direction == Direction::Top) {
		return direction != Direction::Bottom;
	}

	if (m_direction == Direction::Right) {
		return direction != Direction::Left;
	}

	if (m_direction == Direction::Right) {
		return direction != Direction::Left;
	}

	if (m_direction == Direction::Bottom) {
		return direction != Direction::Top;
	}

	return true;
}
