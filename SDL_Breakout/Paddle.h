#pragma once
#include "GameObject.h"
#include <SDL/SDL.h>

class Paddle :
	public GameObject
{
public:
	Paddle(SDL_Renderer* renderer, int screenWidth, int screenHeight);
	~Paddle();

	void draw();
	void update();
	void setX(SDL_Event evnt);

	SDL_Renderer* renderer;
	SDL_Texture* paddleTexture;
	SDL_Rect playerPaddle;

private:

	int _paddleWidth;
	int _paddleHeight;
	
	
};

