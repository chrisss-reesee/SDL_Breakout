#include "GameEngine.h"
#include <iostream>

GameEngine::GameEngine() : screenWidth(1024), screenHeight(768), _window(nullptr), _renderer(nullptr), gameState(GameState::LAUNCH_PHASE),
						   _ball(nullptr), _environment(nullptr), _bounce(nullptr), _brick(nullptr), _explosion(nullptr), _paddle(nullptr)
{
}

GameEngine::~GameEngine()
{
	delete _brick;
	_brick = nullptr;
	Mix_FreeChunk(_explosion);
	_explosion = nullptr;
	Mix_FreeChunk(_bounce);
	_bounce = nullptr;
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
	loadMedia();
	gameLoop();
}

void GameEngine::initSystems()
{
	// Initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	// Initialize SDL_Mixer
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

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

}

void GameEngine::loadMedia()
{
	// Graphics ///////////////////////////////////////////////////////
	// Create Environment
	_environment = new Environment(_renderer);
	_environment->renderer = _renderer;

	//Create Paddle
	_paddle = new Paddle(_renderer, screenWidth, screenHeight);
	_paddle->renderer = _renderer;

	// Create Ball
	_ball = new Ball(_renderer, screenWidth, screenHeight, &gameState, _paddle);
	_ball->renderer = _renderer;

	_brick = new Brick();
	_brick->renderer = _renderer;

	// Audio //////////////////////////////////////////////////////////
	// Ball Ricochet SFX
	_bounce = Mix_LoadWAV("bounce.wav");
	if (_bounce == NULL) {
		std::cout << Mix_GetError() << std::endl;
	}
	// Ball Explode SFX
	_explosion = Mix_LoadWAV("explosion.wav");
	if (_explosion == NULL) {
		std::cout << Mix_GetError() << std::endl;
	}
}

void GameEngine::gameLoop()
{
	while (gameState != GameState::EXIT) {

		frameStart = SDL_GetTicks();

		handleInput();
		_ball->checkCollision(&_paddle->playerPaddle, &_environment->leftBorder, &_environment->topBorder, &_environment->rightBorder, _bounce, _environment);
		update();
		render();
		checkGameState();
		
		frameTime = SDL_GetTicks() - frameStart;

		if (frameTime < DELAY_TIME) {
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}
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
		case SDL_KEYDOWN:
			if (evnt.key.keysym.scancode == SDL_SCANCODE_SPACE && gameState == GameState::LAUNCH_PHASE) {
				gameState = GameState::PLAY;
			}
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
	
	_environment->update();
	_paddle->update();
	_ball->update();

}

void GameEngine::checkGameState()
{
	// Ball Goes Past Paddle
	if (_ball->getBallYPos() > screenHeight) {
		Mix_PlayChannel(-1, _explosion, 0);
		gameState = GameState::LAUNCH_PHASE;

	}
}
