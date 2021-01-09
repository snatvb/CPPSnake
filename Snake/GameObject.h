#pragma once
#include <vector>
#include <list>
#include <string>
#include "Transform.h"
#include "GFX.h"
#include "Collider.h"
#include "SDL.h"

namespace Core {
	class GFX;
	class Collider;
	class Transform;

	class GameObject
	{
	public:
		Transform* transform;
		GFX* gfx = nullptr;
		GameObject* parent = nullptr;
		Collider* collider = nullptr;
		std::vector<GameObject*> childs;

		static void updateAll();
		static void updatePhysics();
		static void renderAll(SDL_Renderer& renderer);
		static void invoke(GameObject& gameObject);

		virtual void onInvoke();
		virtual void update();
		virtual void onCollide(Collider& collider);
		virtual std::string toString();

		GameObject();
		~GameObject();
	private:
		static std::vector<GameObject*> m_gameObjects;
		static std::list<GameObject*> m_newInvoked;
		bool m_invoked = false;
	};
}
