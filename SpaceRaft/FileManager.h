#pragma once

#include "ShipManager.h"
#include "CollisionController.h"

class FileManager
{
public:
	static FileManager* getInstance();
	void loadPlayer(Game* game);
	void savePlayer(Game* game);
	void loadShip(ShipManager* shipManager, CollisionController* collisionController, Game* game);
	void saveShip(ShipManager* shipManager, Game* game);
	void loadMap();
	Tile* loadMapObject(string string, float x, float y, CollisionController* collisionController, Game* game);
	void resetPlayer(Game* game);

protected:
	static FileManager* fileManagerInstance;
	void copyFiles(string input, string ouput);
};

