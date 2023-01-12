#include "FileManager.h"
#include "GameLayer.h"

#include "Logger.h"
//#include "PlayerManager.h"

#include "Tile.h"
#include "RustyFloor.h"
#include "AncientFloor.h"
#include "EmptyTile.h"
#include "TileImageNotFound.h"

#include "FoodCheapBuilding.h"
#include "FoodExpensiveBuilding.h"
#include "OxigenCheapBuilding.h"
#include "OxigenExpenciveBuilding.h"

#include "CollisionController.h"
#include "ShipManager.h"

#include "PlayerManager.h"

#include <fstream> 
#include <sstream> 

FileManager* FileManager::fileManagerInstance = nullptr;

FileManager* FileManager::getInstance()
{
    if (fileManagerInstance == nullptr) {
        Logger::log(0, "FileManager", "File Manager initialized");
        fileManagerInstance = new FileManager();
    }
    Logger::log(0, "FileManager", "File Manager loaded");
    return fileManagerInstance;
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

void FileManager::saveShip(ShipManager* shipManager, Game* game)
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

				auto* player = PlayerManager::getInstance(game)->player;

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
			PlayerManager::getInstance(game)->buildingsDone++;
			break;
		case 'a':
			tile = new AncientFloor(x, y, game);
			PlayerManager::getInstance(game)->buildingsDone++;
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
		case 'f':
			if (tile != nullptr) {
				tile->building = new FoodCheapBuilding(tile->x, tile->y, tile->game);
				tile->built = true;
				tile->buildable = false;
				PlayerManager::getInstance(game)->hungerStep -= 1;
				PlayerManager::getInstance(game)->buildingsDone++;
			}
			break;
		case 'F':
			if (tile != nullptr) {
				tile->building = new FoodExpensiveBuilding(tile->x, tile->y, tile->game);
				tile->built = true;
				tile->buildable = false;
				PlayerManager::getInstance(game)->hungerStep -= 5;
				PlayerManager::getInstance(game)->buildingsDone++;
			}
			break;
		case 'o':
			if (tile != nullptr) {
				tile->building = new OxigenCheapBuilding(tile->x, tile->y, tile->game);
				tile->built = true;
				tile->buildable = false;
				PlayerManager::getInstance(game)->oxigenStep -= 1;
				PlayerManager::getInstance(game)->buildingsDone++;
			}
			break;
		case 'O':
			if (tile != nullptr) {
				tile->building = new OxigenExpenciveBuilding(tile->x, tile->y, tile->game);
				tile->built = true;
				tile->buildable = false;
				PlayerManager::getInstance(game)->oxigenStep -= 5;
				PlayerManager::getInstance(game)->buildingsDone++;
			}
			break;
		}
	}

	// Has Player
	if (string.length() >= 3) {
		switch (string[2]) {
		case '1':
			PlayerManager::getInstance(game)->setSpawnPoint(x, y);
			break;
		}
	}

	if (tile == nullptr) {
		tile = new TileImageNotFound(x, y, game);
	}

	return tile;
}

void FileManager::resetPlayer(Game* game)
{
	copyFiles("res/doc/initship.data", "res/doc/ship.data");
	copyFiles("res/doc/initplayer.data", "res/doc/player.data");
}

void FileManager::copyFiles(string inputFilename, string outputFilename)
{
		std::ifstream input(inputFilename);
		std::ofstream output(outputFilename);
		if (input && output) {
			std::string line;
			while (std::getline(input, line)) {
				output << line << std::endl;
			}
		}
		else {
			cerr << "PROBLEM COPYING FILES" << endl;
		}
		input.close();
		output.close();
}

void FileManager::loadMap()
{
    Logger::log(1, "FileManager", "Map data has been loaded...");
}

void FileManager::loadPlayer(Game* game)
{
	char character;
	string line;
	ifstream streamFile("res/doc/player.data");

	if (!streamFile.is_open()) {
		cout << "ERROR WHEN OPENING PLAYER FILE" << endl;
		return;
	}
	else {
		vector<int> data = {};
		for (int i = 0; getline(streamFile, line); i++) {
			istringstream streamLine(line);

			int foundAt = 0;
			for (int j = 0; j < 3; j++) {

				foundAt = line.find("\t");

				string word = line.substr(0, foundAt);
				line = line.substr(foundAt + 1, line.size());

				data.push_back(stoi(word));

			}
		}
		PlayerManager::getInstance(game)->initialize(data);
	}
	streamFile.close();

	Logger::log(1, "FileManager", "Player data has been loaded...");
}

void FileManager::savePlayer(Game* game)
{
	char character;
	ofstream streamFile("res/doc/player.data");
	if (!streamFile.is_open()) {
		cout << "ERROR WHEN OPENING PLAYER FILE" << endl;
		return;
	}
	else {
		auto* player = PlayerManager::getInstance(game);

		streamFile << std::to_string(player->health) + "\t";
		streamFile << std::to_string(player->hunger) + "\t";
		streamFile << std::to_string(player->oxigen) + "\t";

		streamFile << "\n";

		streamFile << std::to_string(player->metalAmount) + "\t";
		streamFile << std::to_string(player->meatAmount) + "\t";
		streamFile << std::to_string(player->ancientAmount) + "\t";

		streamFile << "\n";
	}
	streamFile.close();

    Logger::log(1, "FileManager", "Player data has been saved...");
}
