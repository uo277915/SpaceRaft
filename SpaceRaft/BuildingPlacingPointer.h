#pragma once

#include "Pointer.h"
#include "ShipManager.h"

class BuildingPlacingPointer :
	public Pointer
{
public:
	BuildingPlacingPointer(Game* game);

	void update(ShipManager* shipManager);
};

