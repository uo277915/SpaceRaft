#include "RustyFloor.h"
#include "ShipManager.h"

RustyFloor::RustyFloor(float x, float y, Game* game) : Tile("res/img/boat/tiles/rusty_floor.png", x, y, game)
{
	buildable = false;
	built = true;
	hasCollision = false;
	id = "r";
}

string RustyFloor::toString()
{
	return "Rusty";
}
