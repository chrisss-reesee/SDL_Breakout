#pragma once
#include "GameObject.h"
#include <SDL/SDL.h>

class Paddle :
	public GameObject
{
public:
	Paddle(SDL_Renderer* renderer);
	~Paddle();

	void draw(SDL_Renderer* renderer);
	void update();

	SDL_Texture* paddleTexture;

private:

	int _paddleWidth;
	int _paddleHeight;

	
	SDL_Rect _playerPaddle;
};

