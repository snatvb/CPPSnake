#pragma once
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
	void setSpeed(float speed);
	void grow();
	void onCollide(void (*callback)());

private:
	SnakeSegment* m_head = nullptr;
	Vector2d<__int8> m_direction;
	float m_moveCooldown = 0;
	float m_speed = 1;
	bool m_isGrowing = false;

	void (*m_collide)() = nullptr;

	void m_handleInput();
	void m_move();
	void m_moveTail();
	void m_addSection();
};
