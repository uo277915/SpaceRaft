#pragma once

#include "Logger.h"
#include "PlayerManager.h"

#include "Tile.h"
#include "ShipFloor.h"
#include "TileImageNotFound.h"
#include "CollisionController.h"
#include "EmptyTile.h"

#include <fstream> 
#include <sstream> 
#include "ShipManager.h"

class FileManager
{
public:
	static FileManager* getInstance();
	void loadPlayer(); 
	void loadShip(ShipManager* shipManager, CollisionController* collisionController, Game* game);
	void loadMap();
	Tile* loadMapObject(string string, float x, float y, CollisionController* collisionController, Game* game);
	void savePlayer();
	void saveShip();

protected:
	static FileManager* instance;
};

