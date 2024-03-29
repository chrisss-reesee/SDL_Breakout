#pragma once

#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

#include "Ball.h"
#include "Brick.h"
#include "Environment.h"
#include "Paddle.h"
#include "GameStateManager.h"

class GameEngine
{
public:
	GameEngine();
	~GameEngine();

	void run();
	void initSystems();
	void loadMedia();
	void gameLoop();
	void handleInput();
	void update();
	void render();
	void checkGameState();

	int screenWidth;
	int screenHeight;

	GameState gameState;

	const int FPS = 60;
	const int DELAY_TIME = 1000.0f / FPS;

private:
	Uint32 frameStart, frameTime;

	SDL_Window* _window;
	SDL_Renderer* _renderer;

	Ball* _ball;
	Brick* _brick;
	Environment* _environment;
	Mix_Chunk* _bounce;
	Mix_Chunk* _explosion;
	Paddle* _paddle;
	
};

