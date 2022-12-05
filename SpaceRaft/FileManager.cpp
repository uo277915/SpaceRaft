#include "FileManager.h"
#include "GameLayer.h"

#include "Logger.h"
//#include "PlayerManager.h"

#include "Tile.h"
#include "RustyFloor.h"
#include "AncientFloor.h"
#include "EmptyTile.h"
#include "TileImageNotFound.h"

#include "CollisionController.h"
#include "ShipManager.h"

#include <fstream> 
#include <sstream> 

FileManager* FileManager::instance = nullptr;

FileManager* FileManager::getInstance()
{
    if (instance == nullptr) {
        Logger::log(0, "FileManager", "File Manager initialized");
        instance = new FileManager();
    }
    Logger::log(0, "FileManager", "File Manager loaded");
    return instance;
}

void FileManager::loadPlayer()
{
	
    Logger::log(1, "FileManager", "Player data has been loaded...");
}

void FileManager::loadShip(ShipManager* shipManager, CollisionController* collisionController, Game* game)
{
	char character;
	auto* map = shipManager->map;
	string line;
	ifstream streamFile("res/doc/ship.data");
	if (!streamFile.is_open()) {
		cout << "ERROR WHEN OPENING SHIP FILE" << endl;
		return;
	}
	else {
		for (int i = 0; getline(streamFile, line); i++) {
			istringstream streamLine(line);
			
			int foundAt = 0;
			float size = ShipManager::TILE_SIZE;
			for (int j = 0; j < ShipManager::SHIP_SIZE; j++) {

				foundAt = line.find("\t");
				if(foundAt == -1)
				{
					float x = size / 2 + j * size; // x central
					float y = size + i * size; // y suelo
					map[i][j] = loadMapObject(line, x, y, collisionController, game);

					continue;
				}

				string word = line.substr(0, foundAt);
				line = line.substr(foundAt + 1, line.size());

				float x = size / 2 + j * size; // x central
				float y = size + i * size; // y suelo
				map[i][j] = loadMapObject(word, x, y, collisionController, game);
			}
		}
	}
	streamFile.close();

    Logger::log(1, "FileManager", "Ship data has been loaded...");
}

void FileManager::saveShip(ShipManager* shipManager)
{
	char character;
	auto* map = shipManager->map;
	ofstream streamFile("res/doc/ship.data");
	if (!streamFile.is_open()) {
		cout << "ERROR WHEN OPENING SHIP FILE" << endl;
		return;
	}
	else {
		for (int i = 0; i < ShipManager::SHIP_SIZE; i++) {
			for (int j = 0; j < ShipManager::SHIP_SIZE; j++) {
				streamFile << map[i][j]->id;

				auto* building = map[i][j]->building;
				if (building != nullptr) {
					streamFile << building->id;
				}
				else {
					streamFile << "-";
				}

				auto* player = PlayerManager::getInstance()->player;

				if (map[i][j]->containsPoint(player->x, player->y)) {
					streamFile << "1";
				}
				streamFile << "\t";
			}
			streamFile << "\n";
		}
	}
	streamFile.close();

	Logger::log(1, "FileManager", "Ship data has been saved...");
}

Tile* FileManager::loadMapObject(string string, float x, float y, CollisionController* collisionController, Game* game) 
{
	Tile* tile = nullptr;

	// Floors
	if (string.length() >= 1) {
		switch (string[0]) {
		case 'r':
			tile = new RustyFloor(x, y, game);
			break;
		case 'a':
			tile = new AncientFloor(x, y, game);
			break;
		case '0':
			tile = new EmptyTile(x, y, game);
			collisionController->addCollider(tile);
			break;
		}
	}
	
	// Buildings
	if (string.length() >= 2) {
		switch (string[1]) {
		}
	}

	// Has Player
	if (string.length() >= 3) {
		switch (string[2]) {
		case '1':
			PlayerManager::getInstance()->setSpawnPoint(x, y);
			break;
		}
	}

	if (tile == nullptr) {
		tile = new TileImageNotFound(x, y, game);
	}

	return tile;
}

void FileManager::loadMap()
{
    Logger::log(1, "FileManager", "Map data has been loaded...");
}

void FileManager::savePlayer()
{
    Logger::log(1, "FileManager", "Player data has been saved...");
}
