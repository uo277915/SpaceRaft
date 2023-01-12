#include "RustyFloor.h"
#include "ShipManager.h"

RustyFloor::RustyFloor(float x, float y, Game* game) : Tile("res/img/boat/tiles/rusty_floor.png", x, y, game)
{
	buildable = false;
	built = true;
	hasCollision = false;
	id = "r";

	initializeCraftable();
}

void RustyFloor::initializeCraftable() {
	name = "Rusty Floor";
	description = "A simple and easy to build floor made of scrap metal";

	type = TILE;

	priceMetal = 5;
	priceMeat = 0;
	priceAncient = 0;
}

Craftable* RustyFloor::clone()
{
	return new RustyFloor(x, y, game);
}

string RustyFloor::toString()
{
	return "Rusty";
}
