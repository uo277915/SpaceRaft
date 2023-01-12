#include "Building.h"
#include "GameLayer.h"

Building::Building(string filename, float x, float y, Game* game)
	: Craftable(filename, x, y, ShipManager::TILE_SIZE, ShipManager::TILE_SIZE, game)
{

}


void Building::craft()
{
	((GameLayer*)game->gameLayer)->buildBuilding(this);
}
