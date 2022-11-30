#include "TileImageNotFound.h"

TileImageNotFound::TileImageNotFound(float x, float y, Game* game) : Tile("res/img/boat/tiles/error.png", x, y, game)
{
}

string TileImageNotFound::toString()
{
	return "Error";
}