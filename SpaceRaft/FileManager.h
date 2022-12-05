#pragma once

#include "ShipManager.h"
#include "CollisionController.h"

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
	static FileManager* fileManagerInstance;
};

