#pragma once

#include "Pointer.h"
#include "ShipManager.h"
#include "CollisionController.h"

class BuildingPlacingPointer :
	public Pointer
{
public:
	BuildingPlacingPointer(Game* game);
	void loadBuilding(Building* building);
	void handleClick(ShipManager* shipManager, CollisionController* collisionController);

	void update(ShipManager* shipManager);
	Building* buildingToPlace = nullptr;

	int iToReplace = -1;
	int jToReplace = -1;
};

