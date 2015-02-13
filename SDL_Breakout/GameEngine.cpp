#include "GameEngine.h"
#include <iostream>


GameEngine::GameEngine() : screenWidth(1024), screenHeight(768), _window(nullptr), _renderer(nullptr)
{
}


GameEngine::~GameEngine()
{
	SDL_DestroyRenderer(_renderer);
	_renderer = nullptr;
	SDL_DestroyWindow(_window);
	_window = nullptr;
	SDL_Quit();
}

void GameEngine::run()
{
	initSystems();
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
