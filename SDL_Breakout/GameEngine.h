#pragma once

#include <SDL/SDL.h>

#include "Environment.h"
#include "Paddle.h"

enum class GameState { PLAY, EXIT };

class GameEngine
{
public:
	GameEngine();
	~GameEngine();

	void run();
	void initSystems();
	void gameLoop();
	void handleInput();
	void render();

	int screenWidth;
	int screenHeight;

	GameState gameState;
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	Environment* _environment;
	Paddle* _paddle;
	
};

