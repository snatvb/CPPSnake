#pragma once
#include <functional>
#include "Core.h"
#include "SnakeSegment.h"

class SnakeSegment;

class Snake : public Core::GameObject {
public:
	static const short int INIT_LENGTH = 3;
	static const short int SEGMENT_SIZE = 20;

	Snake(Core::Position& position);
	~Snake();

	void onInvoke() override;
	void update() override;
	void subscribeOnDie(std::function<void()> handler);
	void onSegmentCollide(SnakeSegment& segment);
	void setSpeed(float speed);
	void grow();

private:
	SnakeSegment* m_head = nullptr;
	SnakeSegment::Direction m_direction = SnakeSegment::Direction::Right;
	float m_moveCooldown = 0;
	float m_speed = 1;
	bool m_isGrowing = false;

	std::function<void()> m_onDie = nullptr;

	void m_handleInput();
	void m_move();
	void m_moveTail();
	void m_addSection();
};
