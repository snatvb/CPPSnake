#pragma once

#include <ctime>
#include "Core.h"
#include "Level.h"

class SnakeGame
{
public:
	SnakeGame(const Vector2d<int>* pos, const Size* size, const char* windowTitle);
	SnakeGame(const Vector2d<int>* pos, const Size* size);
	~SnakeGame();

	void init();
	void handleEvents();
	void update();
	void render();
	void clean();

	bool isRunning();

private:
	const Size* m_size;
	const Vector2d<int>* m_position;
	const char* m_windowTitle = "Title";
	
	bool m_isRunning = false;
	SDL_Window* m_window = nullptr;
	SDL_Renderer* m_renderer = nullptr;
	Level* currentLevel = nullptr;

	void m_initWindow();
	void m_initRenderer();
};

