#pragma once

#include <SDL/SDL.h>

#include "Ball.h"
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
	void update();
	void render();

	int screenWidth;
	int screenHeight;

	GameState gameState;
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;

	Ball* _ball;
	Environment* _environment;
	Paddle* _paddle;
	
};

