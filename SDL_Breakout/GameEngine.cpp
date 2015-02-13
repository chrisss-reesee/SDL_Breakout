#include "GameEngine.h"
#include <iostream>

GameEngine::GameEngine() : screenWidth(1024), screenHeight(768), _window(nullptr), _renderer(nullptr), gameState(GameState::PLAY)
{
}


GameEngine::~GameEngine()
{
	SDL_DestroyRenderer(_renderer);
	_renderer = nullptr;
	SDL_DestroyWindow(_window);
	_window = nullptr;
}

void GameEngine::run()
{
	initSystems();
	gameLoop();
}

void GameEngine::initSystems()
{
	// Initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	// Create SDL Window
	_window = SDL_CreateWindow("SDL2 Breakout", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_OPENGL);
	if (_window == NULL) {
		std::cout << SDL_GetError() << std::endl;
	}

	// Create Renderer
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	if (_renderer == NULL) {
		std::cout << SDL_GetError() << std::endl;
	}
}

void GameEngine::gameLoop()
{
	while (gameState == GameState::PLAY) {
		handleInput();
	}

}


void GameEngine::handleInput()
{
	SDL_Event evnt;

	while (SDL_PollEvent(&evnt)) {
		switch (evnt.type)
		{
		case SDL_QUIT:
			gameState = GameState::EXIT;
			break;
		default:
			break;			
		}
	}
}