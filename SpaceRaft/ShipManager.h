#pragma once
#include "Tile.h"
class ShipManager
{
public:
	ShipManager();
	void draw();
	string toString();

	const static int SHIP_SIZE = 50;
	const static int TILE_SIZE = 100;
	Tile* map[SHIP_SIZE][SHIP_SIZE];
};

