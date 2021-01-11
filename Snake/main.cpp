#include "SnakeGame.h"
#include <functional>

int main(int argc, char* argv[]) {
	const char* title = "Snake Game";
	Vector2d<int> position(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	Size size(800, 800);
	SnakeGame game(position, size, title);

	game.init();

	const int fps = 100;
	const int frameDelay = 1000 / fps;

	Uint32 frameStart;
	int frameTime;

	while (game.isRunning()) {
		frameStart = SDL_GetTicks();

		game.handleEvents();
		game.update();
		game.render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game.clean();

	return 0;
}
