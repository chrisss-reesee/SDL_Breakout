#pragma once
#include <SDL/SDL.h>

class GameObject
{
public:

	virtual void draw() = 0;
	virtual void update() = 0;
};

