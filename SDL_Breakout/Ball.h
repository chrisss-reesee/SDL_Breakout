#pragma once
#include "GameObject.h"
class Ball :
	public GameObject
{
public:
	Ball(SDL_Renderer* renderer, int screenWidth, int screenHeight);
	~Ball();
	
	void draw();
	void update();

	SDL_Renderer* renderer;
	SDL_Texture* ballTexture;

private:
	
	float _ballWidth;
	float _ballHeight;

	SDL_Rect _ball;
};

