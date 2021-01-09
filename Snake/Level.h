#pragma once
#include "Core.h"
#include "Snake.h"
#include "Eat.h"

class Level {
public:
	using Size = Vector2d<unsigned short int>;
	unsigned int score = 0;
	char* name = nullptr;
	float speed = 10;
	Eat* eat = nullptr;
	Snake* snake = nullptr;

	Level(const Size& size);
	~Level();
	
	void render(SDL_Renderer& renderer);
	void init();
	void start();
	bool isPaused();
	void update();
	void pause();
	void unpause();
	void onGameOver(void (*callback)());

private:
	bool m_paused = true;
	const Size m_size;

	void m_handleEat(Eat& eat);
	void m_randomMoveEat();
	void (*m_gameOver)() = nullptr;
};
