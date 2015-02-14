#include "Environment.h"


Environment::Environment(SDL_Renderer* renderer)
{
	wall = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,668, 1024);
	SDL_SetTextureBlendMode(wall, SDL_BLENDMODE_BLEND);
	SDL_SetRenderTarget(renderer, wall);
	// Set Draw Color
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	//Create Left Border
	SDL_Rect newLeftBorder = { 0, 120, 20, 668 };
	leftBorder = newLeftBorder;

	//Create Top Border
	SDL_Rect newTopBorder = { 0, 100, 1024, 20 };
	topBorder = newTopBorder;

	//Create Right Border
	SDL_Rect newRightBorder = { 1004, 120, 20, 668 };
	rightBorder = newRightBorder;

	
}


Environment::~Environment()
{

}

void Environment::drawBackground(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	
	SDL_RenderFillRect(renderer, &leftBorder);
	SDL_RenderFillRect(renderer, &topBorder);
	SDL_RenderFillRect(renderer, &rightBorder);
	
}