#include "Level.h"
#include "UIScore.h"

Level::Level(const Size& size, HUD& hud)
	: m_size(Size::clone(size)), m_hud(hud)
{
}

Level::~Level()
{
	delete snake;
	delete eat;
}

void Level::init()
{
	Core::Position position(
		20,
		100
	);

	snake = new Snake(position);
	snake->setSpeed(speed);
	snake->subscribeOnDie([this]() {
		pause();
	});
	Core::GameObject::invoke(*snake);


	Core::Position eatPosition(
		100,
		100
	);
	eat = new Eat(eatPosition, Snake::SEGMENT_SIZE, [&](Eat& eat) {
		m_handleEat(eat);
		});

	m_randomMoveEat();
	Core::GameObject::invoke(*eat);
}

void Level::start()
{
	init();
	unpause();
}

bool Level::isPaused()
{
	return m_paused;
}

void Level::update()
{
	if (m_paused) {
		return;
	}

	Core::GameObject::updateAll();
	Core::GameObject::updatePhysics();
}

void Level::pause()
{
	m_paused = true;
}

void Level::unpause()
{
	m_paused = false;
}

void Level::addScore(unsigned int score)
{
	m_score += score;
	//TODO: update hud
	auto uiScore = m_hud.getComponent<UIScore>();
	uiScore->setScore(m_score);
}

void Level::m_handleEat(Eat& eat)
{
	addScore(eat.score);
	snake->grow();
	m_randomMoveEat();
}

void Level::m_randomMoveEat()
{
	Core::Position position(
		rand() % m_size.x,
		rand() % m_size.y
	);
	position.x -= position.x % Snake::SEGMENT_SIZE;
	position.y -= position.y % Snake::SEGMENT_SIZE;
	eat->transform->position = position;
	eat->score = rand() % 2 + 1;
}

void Level::onGameOver(void(*callback)())
{
	m_gameOver = callback;
}

void Level::render(SDL_Renderer& renderer)
{
	Core::GameObject::renderAll(renderer);
}
