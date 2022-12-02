#pragma once
#include "Pointer.h"
#include "CollisionController.h"
class TileRemovePointer :
    public Pointer
{
	TileRemovePointer(Game* game);
	void handleClick(ShipManager* shipManager, CollisionController* collisionController);

	void update(ShipManager* shipManager);
	Tile* tileToPlace = nullptr;

	int iToReplace = -1;
	int jToReplace = -1;
};

