#include "Brick.h"
#include <iostream>



Brick::Brick() : brickWidth(60), brickHeight(20), x(55), y(200), isActive(true)
{
	brickTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, brickWidth, brickHeight);
	//Create Brick
	SDL_Rect newBrick = { x, y, brickWidth, brickHeight };
	brick = newBrick;
}


Brick::~Brick()
{
	
}

void Brick::draw()
{
	// Draw The Bricks
	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
	SDL_RenderFillRect(renderer, &brick);	
	SDL_RenderCopy(renderer, brickTexture, NULL, NULL);
}

void Brick::update()
{
	draw();
}

void Brick::reset()
{

}
