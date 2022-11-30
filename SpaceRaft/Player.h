#pragma once

#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(float x, float y, Game* game);
	void draw();
	void update();
	void moveX(float vx);
	void moveY(float vy);

	float speed = 3;
};