#pragma once
#include "Core.h"
#include "Snake.h"
#include "Eat.h"
#include "HUD.h"

class Level {
public:
	enum class State {
		Play,
		Pause,
		GameOver,
	};

	using Size = Vector2d<unsigned short int>;
	char* name = nullptr;
	float speed = 10;
	Eat* eat = nullptr;
	Snake* snake = nullptr;

	Level(const Size& size, HUD& hud);
	~Level();
	
	void render(SDL_Renderer& renderer);
	void init();
	void start();
	bool isPaused();
	void update();
	void pause();
	void unpause();
	void addScore(unsigned int score);

private:
	State m_state = State::Pause;
	unsigned int m_score = 0;
	const Size m_size;
	HUD& m_hud;

	void m_handleEat(Eat& eat);
	void m_randomMoveEat();
	void m_gameOver();
};
