#pragma once

#include "Pointer.h"
#include "ShipManager.h"
#include "CollisionController.h"

class TilePlacingPointer : public Pointer
{
public:
	TilePlacingPointer(Game* game);
	void loadTile(Tile* tile);
	void handleClick(ShipManager* shipManager, CollisionController* collisionController);

	void update(ShipManager* shipManager);
	Tile* tileToPlace = nullptr;

	int iToReplace = -1;
	int jToReplace = -1;
};

