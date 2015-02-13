#pragma once

#include <SDL/SDL.h>

class GameEngine
{
public:
	GameEngine();
	~GameEngine();

	void run();
	void initSystems();
	void gameLoop();
	void exit();

	int screenWidth;
	int screenHeight;

private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
};

