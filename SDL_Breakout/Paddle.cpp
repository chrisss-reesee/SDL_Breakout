#include "Paddle.h"
#include <iostream>

Paddle::Paddle(SDL_Renderer* renderer) : _paddleWidth(1024 / 10), _paddleHeight(20), renderer(renderer)
{
	// Create Paddle Texture
	paddleTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, _paddleWidth, _paddleHeight);
	if (paddleTexture == NULL) {
		std::cout << SDL_GetError() << std::endl;
	}

	// Set Blend Mode
	SDL_SetTextureBlendMode(paddleTexture, SDL_BLENDMODE_BLEND);
	// Create Rect
	SDL_Rect newPaddle = { 512, 728, _paddleWidth, _paddleHeight };
	_playerPaddle = newPaddle;
}

Paddle::~Paddle()
{
}

void Paddle::draw()
{
	// Draw The Paddle
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &_playerPaddle);
	SDL_RenderCopy(renderer, paddleTexture, NULL, NULL);
}

void Paddle::update()
{
	draw();
}

void Paddle::setX(SDL_Event evnt)
{
	_playerPaddle.x = evnt.motion.x;
}
