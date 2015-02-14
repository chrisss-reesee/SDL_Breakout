#pragma once
#include <SDL/SDL.h>

class GameObject
{
public:

	virtual void draw(SDL_Renderer* renderer) = 0;
	virtual void update() = 0;
};

