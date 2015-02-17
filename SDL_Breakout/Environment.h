#pragma once

#include <SDL/SDL.h>
#include "Brick.h"

class Environment
{
public:
	Environment(SDL_Renderer* renderer);
	~Environment();

	void draw();
	void update();

	SDL_Rect leftBorder;
	SDL_Rect topBorder;
	SDL_Rect rightBorder;

	SDL_Renderer* renderer;
	SDL_Texture* wall; 

	const static int NUMBER_OF_BRICKS = 126;
	Brick bricks[NUMBER_OF_BRICKS];
	SDL_Texture* brickTexture;

private:

	int boardWidth;
	int boardHeight;

};

