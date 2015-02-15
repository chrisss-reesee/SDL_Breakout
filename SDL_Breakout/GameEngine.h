#pragma once

#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

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
	void loadMedia();
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
	Mix_Chunk* _bounce;
	Paddle* _paddle;
	
};

