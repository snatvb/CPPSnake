#include "GameObject.h"
#include "logger.h"

std::vector<Core::GameObject*> Core::GameObject::m_gameObjects;
std::list<Core::GameObject*> Core::GameObject::m_newInvoked;

void Core::GameObject::updateAll()
{
	for (auto gameObject : Core::GameObject::m_gameObjects) {
		(*gameObject).update();
	}
}

void Core::GameObject::renderAll(SDL_Renderer& renderer)
{
	for (auto gameObject : Core::GameObject::m_gameObjects) {
		if (gameObject->m_invoked && gameObject->gfx != nullptr) {
			gameObject->gfx->render(renderer);
		}
	}

	for (auto gameObject : Core::GameObject::m_newInvoked) {
		Core::GameObject::m_gameObjects.push_back(gameObject);
		gameObject->onInvoke();
		gameObject->m_invoked = true;
		Logger::debug("invoked");
	}

	Core::GameObject::m_newInvoked.clear();
}

void Core::GameObject::invoke(Core::GameObject& gameObject)
{
	Logger::debug("Add to invoke");
	Core::GameObject::m_newInvoked.push_back(&gameObject);
}

void Core::GameObject::onInvoke()
{
}

void Core::GameObject::update()
{
}

void Core::GameObject::updatePhysics()
{
	Core::Collider::calculateCollides(m_gameObjects);
}

void Core::GameObject::onCollide(Collider& collider)
{
}

std::string Core::GameObject::toString()
{
	return "GameObject";
}

Core::GameObject::GameObject()
{
	Logger::debug("GameObject Constructor");
	gfx = nullptr;
	transform = new Core::Transform(*this);
}

Core::GameObject::~GameObject()
{
	Logger::debug("Destructor");
	if (m_invoked) {
		m_gameObjects.erase(std::remove(
			m_gameObjects.begin(),
			m_gameObjects.end(),
			this
		), m_gameObjects.end());
		Logger::debug("Invoked destroyed");
	}

	if (gfx != nullptr) {
		delete gfx;
	}

	if (collider != nullptr) {
		delete collider;
	}

	for (auto child : childs) {
		delete child;
	}

	delete transform;
}
