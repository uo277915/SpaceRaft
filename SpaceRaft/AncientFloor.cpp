#include "AncientFloor.h"

AncientFloor::AncientFloor(float x, float y, Game* game) : Tile("res/img/boat/tiles/ancient_floor.png", x, y, game)
{
	buildable = false;
	built = true;
	hasCollision = false;
	id = "a";

	initializeCraftable();
}

void AncientFloor::initializeCraftable() {
	name = "Ancient Floor";
	description = "A weird looking floor... It looks... Great... Wait! How did i learn to do this?!";

	type = TILE;

	priceMetal = 10;
	priceMeat = 0;
	priceAncient = 5;
}

string AncientFloor::toString()
{
	return "Ancient";
}