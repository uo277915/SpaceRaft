#pragma once

#include "Logger.h"
#include "PlayerManager.h"

#include "Tile.h"
#include "RustyFloor.h"
#include "AncientFloor.h"
#include "EmptyTile.h"
#include "TileImageNotFound.h"

#include "CollisionController.h"
#include "ShipManager.h"

#include <fstream> 
#include <sstream> 

class FileManager
{
public:
	static FileManager* getInstance();
	void loadPlayer();
	void savePlayer();
	void loadShip(ShipManager* shipManager, CollisionController* collisionController, Game* game);
	void saveShip(ShipManager* shipManager);
	void loadMap();
	Tile* loadMapObject(string string, float x, float y, CollisionController* collisionController, Game* game);

protected:
	static FileManager* instance;
};

