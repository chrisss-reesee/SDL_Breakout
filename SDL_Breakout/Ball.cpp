#include "Ball.h"
#include <iostream>


Ball::Ball(SDL_Renderer* renderer, int screenWidth, int screenHeight, GameState* gameState, Paddle* paddle) : _ballHeight(15), _ballWidth(15), _ballSpeed(1.0f),
_xDirection(XDirection::RIGHT), _yDirection(YDirection::DOWN), currentGameState(gameState), paddle(paddle)
{
	// Create Texture
	ballTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, _ballWidth, _ballHeight);
	//Set Blend mode
	SDL_SetTextureBlendMode(ballTexture, SDL_BLENDMODE_BLEND);
	//Create Ball Rect
	SDL_Rect newBall = { screenWidth / 2, screenHeight - 376, _ballHeight, _ballWidth };
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
	if (*currentGameState == GameState::PLAY) {
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
	else if (*currentGameState == GameState::LAUNCH_PHASE) {
		_ball.x = paddle->playerPaddle.x + (paddle->playerPaddle.w / 2);
		_ball.y = paddle->playerPaddle.y - (_ballHeight + 10);
	}

}

void Ball::checkCollision(SDL_Rect* paddle, SDL_Rect* leftBorder, SDL_Rect* topBorder, SDL_Rect* rightBorder, Mix_Chunk* bounceSfx, Environment* environment)
{
	//Paddle Collision Box Definitions

	// If Ball hits Paddle
	if (_ball.y >= paddle->y - _ballHeight && _ball.y <= (paddle->y + paddle->h) && _ball.x >= paddle->x && (_ball.x <= paddle->x + paddle->w) ) {
		_yDirection = YDirection::UP;
		Mix_PlayChannel(-1, bounceSfx, 0);
	}

	// Right Wall Collision Detection
	if (_ball.x >= rightBorder->x - _ball.w) {
		_xDirection = XDirection::LEFT;
		Mix_PlayChannel(-1, bounceSfx, 0);
	}

	// Top Border Collision Detection
	if (_ball.y <= topBorder->y + topBorder->h) {
		_yDirection = YDirection::DOWN;
		Mix_PlayChannel(-1, bounceSfx, 0);
	}

	// Left Border Collision
	if (_ball.x <= leftBorder->x + leftBorder->w) {
		_xDirection = XDirection::RIGHT;
		Mix_PlayChannel(-1, bounceSfx, 0);
	}

	// Ball / Brick Collisions
	for (int i = 0; i < environment->NUMBER_OF_BRICKS; i++) {
		
		if (environment->bricks[i].isActive) {
			// Bottom of Brick Check
			if (SDL_HasIntersection(&_ball, &environment->bricks[i].brick)) {
				if (_ball.y <= (environment->bricks[i].brick.y + environment->bricks[i].brick.h) && _ball.x >= environment->bricks[i].brick.x - _ball.x && _ball.x <= (environment->bricks[i].brick.x + environment->bricks[i].brick.w)- _ball.w) {
					_yDirection = YDirection::DOWN;
					environment->bricks[i].isActive = false;
				} 
				// Right Side of Brick Check
				if (_ball.x <= (environment->bricks[i].brick.x + environment->bricks[i].brick.w) && _ball.x > environment->bricks[i].brick.x && _ball.y >= environment->bricks[i].brick.y && _ball.y <= (environment->bricks[i].brick.y - environment->bricks[i].brick.h)) {
					_xDirection = XDirection::RIGHT;
					environment->bricks[i].isActive = false;
				} 
				//// Left Side of Brick Check
				if (_ball.x >= (environment->bricks[i].brick.x - _ball.w) && _ball.x < (environment->bricks[i].brick.x + environment->bricks[i].brick.w- _ball.w) &&  _ball.y >= environment->bricks[i].brick.y && _ball.y <= (environment->bricks[i].brick.y + environment->bricks[i].brick.h)) {
					_xDirection = XDirection::LEFT;
					environment->bricks[i].isActive = false;
				}
				// Top Brick Check
				if (_ball.y >= (environment->bricks[i].brick.y - _ball.h) && _ball.x >= environment->bricks[i].brick.x && _ball.x <= (environment->bricks[i].brick.x + environment->bricks[i].brick.w)) {
					_yDirection = YDirection::UP;
					environment->bricks[i].isActive = false;
				}
			}
		}
		
	}
}

void Ball::resetBall(float x, float y)
{
	_ball.x = x;
	_ball.y = y;
}
