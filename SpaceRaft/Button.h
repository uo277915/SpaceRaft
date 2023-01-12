#pragma once
#include "GameObject.h"

class Button : public GameObject
{
public:
	Button(string filename, float x, float y, int width, int height, Game* game)
		: GameObject(filename, x, y, width, height, game) {}
	virtual void handleClick();
	bool isClicked(float mouseX, float mouseY);
};

