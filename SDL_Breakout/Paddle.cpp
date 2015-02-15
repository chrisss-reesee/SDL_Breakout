#include "Paddle.h"
#include <iostream>

Paddle::Paddle(SDL_Renderer* renderer, int screenWidth, int ScreenHeight) : renderer(renderer), _paddleWidth(screenWidth / 10), _paddleHeight(20)
{
	// Create Paddle Texture
	paddleTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, _paddleWidth, _paddleHeight);
	if (paddleTexture == NULL) {
		std::cout << SDL_GetError() << std::endl;
	}

	// Set Blend Mode
	SDL_SetTextureBlendMode(paddleTexture, SDL_BLENDMODE_BLEND);
	// Create Rect
	SDL_Rect newPaddle = { screenWidth / 2, ScreenHeight - 40, _paddleWidth, _paddleHeight };
	playerPaddle = newPaddle;
}

Paddle::~Paddle()
{
}

void Paddle::draw()
{
	// Draw The Paddle
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &playerPaddle);
	SDL_RenderCopy(renderer, paddleTexture, NULL, NULL);
}

void Paddle::update()
{
	draw();
}

void Paddle::setX(SDL_Event evnt)
{
	if (evnt.motion.x < 20) {
		playerPaddle.x = 20;
	}
	else if (evnt.motion.x > (1004 - _paddleWidth)) {
		playerPaddle.x = (1004 - _paddleWidth);
	}
	else {
		playerPaddle.x = evnt.motion.x;
	}
}
