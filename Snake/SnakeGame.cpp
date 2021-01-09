#include "SnakeGame.h"


SnakeGame::SnakeGame(const Vector2d<int>* pos, const Size* size, const char* windowTitle)
	: SnakeGame::SnakeGame(pos, size)
{
	m_windowTitle = windowTitle;
}

SnakeGame::SnakeGame(const Vector2d<int>* pos, const Size* size)
{
	m_size = size;
	m_position = pos;
}

SnakeGame::~SnakeGame()
{
	delete currentLevel;
}

void SnakeGame::init()
{
	srand((unsigned int)time(NULL));
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		Logger::debug("Game initializing...");

		m_initWindow();
		m_initRenderer();
		m_isRunning = true;
		Core::Time::init();
		currentLevel = new Level(Level::Size(m_size->x, m_size->y));
		currentLevel->start();
	}
	else {
		m_isRunning = false;
	}
}

void SnakeGame::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		m_isRunning = false;
		break;

	case SDL_KEYDOWN:
		Core::Keyboard::handleDown(event.key);
		break;

	case SDL_KEYUP:
		Core::Keyboard::handleUp();
		break;

	default:
		break;
	}
}

void SnakeGame::update()
{
	Core::Time::update();
	currentLevel->update();
}

void SnakeGame::render()
{
	SDL_RenderClear(m_renderer);
	currentLevel->render(*m_renderer);
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	SDL_RenderPresent(m_renderer);
}

void SnakeGame::clean()
{
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
	Logger::debug("Game cleaned");
}

bool SnakeGame::isRunning()
{
	return m_isRunning;
}

void SnakeGame::m_initWindow()
{
	m_window = SDL_CreateWindow(
		m_windowTitle,
		m_position->x,
		m_position->y,
		m_size->x,
		m_size->y,
		0 // flag
	);

	if (m_window) {
		Logger::debug("Window created");
	}
}

void SnakeGame::m_initRenderer()
{
	m_renderer = SDL_CreateRenderer(m_window, -1, 0);

	if (m_renderer) {
		SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
		Logger::debug("Renderer initialized");
	}
}