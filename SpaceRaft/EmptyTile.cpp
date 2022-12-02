#include "EmptyTile.h"
#include "ShipManager.h"

EmptyTile::EmptyTile(float x, float y, Game* game) : Tile("", x, y, game)
{
	buildable = true;
	built = false;
	hasCollision = true;
	id = "0";
}

string EmptyTile::toString()
{
	return "Empty";
}