#pragma once

#include <SDL/SDL.h>
class Environment
{
public:
	Environment(SDL_Renderer* renderer);
	~Environment();

	void drawBackground(SDL_Renderer* renderer);

	SDL_Rect leftBorder;
	SDL_Rect topBorder;
	SDL_Rect rightBorder;

	SDL_Texture* wall;

private:

};

