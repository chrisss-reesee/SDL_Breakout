#pragma once
#include "GameObject.h"
class Ball :
	public GameObject
{
public:
	Ball();
	~Ball();
	
	void draw();
	void update();
};

