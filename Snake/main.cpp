#include "SnakeGame.h"
#include <functional>

int main(int argc, char* argv[]) {
	const char* title = "Snake Game";
	Vector2d<int> position(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	Size size(800, 800);
	SnakeGame game(position, size, title);

	game.init();

	while (game.isRunning()) {
		game.handleEvents();
		game.update();
		game.render();
	}

	game.clean();

	return 0;
}
