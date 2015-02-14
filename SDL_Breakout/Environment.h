#pragma once

#include <SDL/SDL.h>
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

private:

};

