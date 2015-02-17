#pragma once
#include "GameObject.h"
#include <SDL/SDL.h>
class Brick :
	public GameObject
{
public:
	Brick();
	~Brick();

	void draw();
	void update();
	void reset();

	SDL_Renderer* renderer;
	SDL_Texture* brickTexture;
	SDL_Rect brick;

	int x;
	int y;
	float xpos;
	float ypos;
	int brickWidth;
	int brickHeight;
	bool isActive;

private:


};

