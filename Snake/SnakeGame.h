#pragma once

#include <ctime>
#include "Core.h"
#include "Level.h"
#include "HUD.h"

class SnakeGame
{
public:
	static Size windowSize;

	SnakeGame(const Vector2d<int>& pos, const Size& size, const char* windowTitle);
	SnakeGame(const Vector2d<int>& pos, const Size& size);
	~SnakeGame();

	void init();
	void handleEvents();
	void update();
	void render();
	void clean();

	bool isRunning();

private:
	const Vector2d<int> m_position;
	const char* m_windowTitle = "Title";
	
	bool m_isRunning = false;
	SDL_Window* m_window = nullptr;
	SDL_Renderer* m_renderer = nullptr;
	Level* currentLevel = nullptr;
	HUD* m_hud = nullptr;

	void m_initWindow();
	void m_initRenderer();
	void m_initHUD();
};

