#include "Tile.h"
#include "ShipManager.h"

Tile::Tile(string filename, float x, float y, Game* game) : GameObject(filename, x, y, ShipManager::TILE_SIZE, ShipManager::TILE_SIZE, game)
{

}

string Tile::toString()
{
	return "Tile";
}

