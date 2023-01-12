#include "Tile.h"
#include "ShipManager.h"
#include "GameLayer.h"

Tile::Tile(string filename, float x, float y, Game* game) 
	: Craftable(filename, x, y, ShipManager::TILE_SIZE, ShipManager::TILE_SIZE, game)
{

}

void Tile::draw() 
{ 
	GameObject::draw(); 
	if (building != nullptr) {
		building->draw();
	}
}

string Tile::toString()
{
	return "Tile";
}

void Tile::craft()
{
	((GameLayer*)game->gameLayer)->buildTile(this);
}

