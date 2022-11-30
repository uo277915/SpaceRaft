#pragma once
#include "GameObject.h"
#include "ShipManager.h"
#include "TileImageNotFound.h"

class Pointer :
    public GameObject
{
public:
	Pointer(Game* game);
	void draw() { if (active) { GameObject::draw(); } }
	virtual void update(ShipManager* shipManager);
	void handleClick(ShipManager* shipManager) {}

	SDL_Texture* wrong;
	SDL_Texture* correct;

	bool placeable;
	bool active = false;

	Game* game;
};

