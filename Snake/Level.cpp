#include "Level.h"
#include "UIScore.h"
#include "UIGameOver.h"

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
		m_gameOver();
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

inline bool Level::isPaused()
{
	return m_state == State::Pause || m_state == State::GameOver;
}

void Level::update()
{
	if (isPaused()) {
		return;
	}

	Core::GameObject::updateAll();
	Core::GameObject::updatePhysics();
}

void Level::pause()
{
	m_state = State::Pause;
}

void Level::unpause()
{
	if (m_state == State::Pause) {
		m_state = State::Play;
	}
}

void Level::addScore(unsigned int score)
{
	m_score += score;
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

void Level::m_gameOver()
{
	pause();
	auto ui = m_hud.getComponent<UIGameOver>();
	ui->setDisplay(true);
}

void Level::render(SDL_Renderer& renderer)
{
	Core::GameObject::renderAll(renderer);
}
