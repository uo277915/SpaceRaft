#include "FileManager.h"
#include "GameLayer.h"

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
		// Por l�nea
		for (int i = 0; getline(streamFile, line); i++) {
			//map[i] = new Tile* [15];
			istringstream streamLine(line);
			//mapWidth = line.length() * 40; // Ancho del mapa en pixels
			// Por car�cter (en cada l�nea)
			
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

			/*
			for (int j = 0; !streamLine.eof(); j++) {
				streamLine >> character; // Leer character 
				cout << character;
				float x = 40 / 2 + j * 40; // x central
				float y = 32 + i * 32; // y suelo
				map[i][j] = loadMapObject(character, x, y, game);
			}
			*/
		}
	}
	streamFile.close();

    Logger::log(1, "FileManager", "Ship data has been loaded...");
}

Tile* FileManager::loadMapObject(string string, float x, float y, CollisionController* collisionController, Game* game) 
{
	Tile* tile = nullptr;

	// Floors
	if (string.length() >= 1) {
		switch (string[0]) {
		case 'f':
			tile = new ShipFloor(x, y, game);
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

void FileManager::saveShip()
{
    Logger::log(1, "FileManager", "Ship data has been saved...");
}
