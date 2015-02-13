#include <SDL/SDL.h>
#include "GameEngine.h"

int main(int argc, char** argv) {

	GameEngine gameEngine;
	gameEngine.run();

	SDL_Quit();
	return 0;
}