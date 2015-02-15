#include "Ball.h"


Ball::Ball(SDL_Renderer* renderer, int screenWidth, int screenHeight) : _ballHeight(12), _ballWidth(12), _ballSpeed(2.0f),
_xDirection(XDirection::RIGHT), _yDirection(YDirection::DOWN)
{
	// Create Texture
	ballTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, _ballWidth, _ballHeight);
	//Set Blend mode
	SDL_SetTextureBlendMode(ballTexture, SDL_BLENDMODE_BLEND);
	//Create Ball Rect
	SDL_Rect newBall = { screenWidth / 2, screenHeight - 75, _ballHeight, _ballWidth };
	_ball = newBall;
}

Ball::~Ball()
{
}

void Ball::draw()
{
	// Draw The Paddle
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &_ball);
	SDL_RenderCopy(renderer, ballTexture, NULL, NULL);
}

void Ball::update()
{
	movement();
	draw();
}

void Ball::movement()
{
	if (_xDirection == XDirection::RIGHT) {
		if (_yDirection == YDirection::DOWN) {
			_ball.x += _ballSpeed;
			_ball.y += _ballSpeed;
		}
		else if (_yDirection == YDirection::UP) {
			_ball.x += _ballSpeed;
			_ball.y -= _ballSpeed;
		}
	}
	else if (_xDirection == XDirection::LEFT) {
		if (_yDirection == YDirection::DOWN) {
			_ball.x -= _ballSpeed;
			_ball.y += _ballSpeed;
		}
		else if (_yDirection == YDirection::UP) {
			_ball.x -= _ballSpeed;
			_ball.y -= _ballSpeed;
		}
	}
}

void Ball::checkCollision()
{

}
