#pragma once
#include "GameObject.h"
#include "Paddle.h"
#include <SDL/SDL_mixer.h>
#include <string>
#include "GameStateManager.h"
#include "Environment.h"


enum class XDirection {LEFT, RIGHT};
enum class YDirection {UP, DOWN};

class Ball :
	public GameObject
{
public:
	Ball(SDL_Renderer* renderer, int screenWidth, int screenHeight, GameState* gameState, Paddle* paddle);
	~Ball();
	
	void draw();
	void update();
	void checkCollision(SDL_Rect* paddle, SDL_Rect* leftBorder, SDL_Rect* topBorder, SDL_Rect* rightBorder, Mix_Chunk* bounceSfx, Environment* environment);
	float getBallYPos() { return _ball.y; }
	void resetBall(float x, float y);

	SDL_Renderer* renderer;
	SDL_Texture* ballTexture;
	GameState* currentGameState;
	Paddle* paddle;

	
private:

	void movement();
	
	XDirection _xDirection;
	YDirection _yDirection;

	SDL_Rect _ball;

	float _ballWidth;
	float _ballHeight;
	float _ballSpeed;

};

