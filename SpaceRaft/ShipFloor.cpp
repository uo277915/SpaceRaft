#include "ShipFloor.h"
#include "ShipManager.h"

ShipFloor::ShipFloor(float x, float y, Game* game) : Tile("res/img/boat/tiles/ship_floor.png", x, y, game)
{
	buildable = false;
	built = true;
	hasCollision = false;
}

string ShipFloor::toString()
{
	return "S-Floor";
}
