#pragma once
#include "GameObject.h"
#include "Paddle.h"
#include <SDL/SDL_mixer.h>

enum class XDirection {LEFT, RIGHT};
enum class YDirection {UP, DOWN};

class Ball :
	public GameObject
{
public:
	Ball(SDL_Renderer* renderer, int screenWidth, int screenHeight);
	~Ball();
	
	void draw();
	void update();
	void checkCollision(SDL_Rect* paddle, SDL_Rect* leftBorder, SDL_Rect* topBorder, SDL_Rect* rightBorder, Mix_Chunk* bounceSfx);

	SDL_Renderer* renderer;
	SDL_Texture* ballTexture;
	

private:

	void movement();
	
	XDirection _xDirection;
	YDirection _yDirection;

	SDL_Rect _ball;

	float _ballWidth;
	float _ballHeight;
	float _ballSpeed;

};

