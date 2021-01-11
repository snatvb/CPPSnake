#pragma once
#include "Core.h"
#include "Direction.h"
#include "Snake.h"

class Snake;


class SnakeSegment : public Core::GameObject {
public:
	SnakeSegment* prevSegment = nullptr;
	SnakeSegment* nextSegment = nullptr;

	SnakeSegment(Snake& snake, const Core::Position& position, short int segmentSize);
	
	void onInvoke() override;
	void update() override;
	void onCollide(Core::Collider& collider) override;
	void move();
	void setDirection(Direction direction);
	void setDirection(SnakeSegment& segment);
	Direction getDirection();
	void takeNextSegmentDirection();
	std::string toString();

private:
	short int m_segmentSize = 0;
	Direction m_direction = Direction::Right;

	bool m_isValidDirection(Direction direction);
};
