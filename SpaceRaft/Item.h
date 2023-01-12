#pragma once
#include "GameLayer.h"

class Item
	: public GameObject
{
public:
	Item(string filename, Game* game) : GameObject(filename, 0, 0, 1, 1, game) {}
	virtual void use(GameLayer* gamelayer) {}
	virtual void select(GameLayer* gamelayer) {}
	virtual void deselect(GameLayer* gamelayer) {}
	void draw(float x, float y, float width, float height);

	int id = -1;
	bool obtained = false;
};

