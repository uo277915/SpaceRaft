#include "AncientFloor.h"

AncientFloor::AncientFloor(float x, float y, Game* game) : Tile("res/img/boat/tiles/ancient_floor.png", x, y, game)
{
	buildable = false;
	built = true;
	hasCollision = false;
	id = "a";
}

string AncientFloor::toString()
{
	return "Ancient";
}