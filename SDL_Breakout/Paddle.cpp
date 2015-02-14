#include "Paddle.h"
#include <iostream>

Paddle::Paddle(SDL_Renderer* renderer) : _paddleWidth(1024/8), _paddleHeight(20)
{
	// Create Paddle Texture
	paddleTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, _paddleWidth, _paddleHeight);
	if (paddleTexture == NULL) {
		std::cout << SDL_GetError() << std::endl;
	}

	// Set Blend Mode
	SDL_SetTextureBlendMode(paddleTexture, SDL_BLENDMODE_BLEND);
	// Set Render Color
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	// Create Rect
	SDL_Rect newPaddle = { 512, 728, _paddleWidth, _paddleHeight };
	_playerPaddle = newPaddle;
}


Paddle::~Paddle()
{
}

void Paddle::draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	SDL_RenderFillRect(renderer, &_playerPaddle);
}

void Paddle::update()
{

}
