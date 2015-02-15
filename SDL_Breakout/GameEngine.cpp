#include "GameEngine.h"
#include <iostream>

GameEngine::GameEngine() : screenWidth(1024), screenHeight(768), _window(nullptr), _renderer(nullptr), gameState(GameState::PLAY),
						   _ball(nullptr), _environment(nullptr), _paddle(nullptr)
{
}


GameEngine::~GameEngine()
{
	delete _ball;
	_ball = nullptr;
	delete _paddle;
	_paddle = nullptr;
	delete _environment;
	_environment = nullptr;
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
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_TARGETTEXTURE);
	if (_renderer == NULL) {
		std::cout << SDL_GetError() << std::endl;
	}

	// Create Environment
	_environment = new Environment(_renderer);
	_environment->renderer = _renderer;

	//Create Paddle
	_paddle = new Paddle(_renderer, screenWidth, screenHeight);
	_paddle->renderer = _renderer;

	// Create Ball
	_ball = new Ball(_renderer, screenWidth, screenHeight);
	_ball->renderer = _renderer;
}

void GameEngine::gameLoop()
{
	while (gameState == GameState::PLAY) {
		handleInput();
		_ball->checkCollision(&_paddle->playerPaddle, &_environment->leftBorder, &_environment->topBorder, &_environment->rightBorder);
		update();
		render();
		SDL_Delay(6);
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
		case SDL_MOUSEMOTION:
			_paddle->setX(evnt);
			break;
		default:
			break;			
		}
	}
}

void GameEngine::render()
{
	// Clear Screen
	SDL_SetRenderTarget(_renderer, NULL);
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 0);
	SDL_RenderClear(_renderer);

	update();

	// Render to the Screen
	SDL_RenderPresent(_renderer);
}

void GameEngine::update()
{
	_ball->update();
	_environment->update();
	_paddle->update();	
}
