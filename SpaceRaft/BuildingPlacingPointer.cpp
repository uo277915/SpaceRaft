#include "BuildingPlacingPointer.h"
#include "PlayerManager.h"
#include "AudioManager.h"

BuildingPlacingPointer::BuildingPlacingPointer(Game* game) : Pointer(game)
{
}

void BuildingPlacingPointer::loadBuilding(Building* building)
{
	this->buildingToPlace = building;
}


void BuildingPlacingPointer::handleClick(ShipManager* shipManager, CollisionController* collisionController)
{
	if (active) {
		int motionX;
		int motionY;
		SDL_GetMouseState(&motionX, &motionY);

		if (placeable) {
			Tile* tileToBuild = shipManager->map[iToReplace][jToReplace];

			if (buildingToPlace == nullptr) {
				//buildingToPlace = new TileImageNotFound(motionX, motionY, game);
			}
			else {
				buildingToPlace->x = tileToBuild->x;
				buildingToPlace->y = tileToBuild->y;
			}

			shipManager->map[iToReplace][jToReplace]->building = buildingToPlace;
			PlayerManager::getInstance(game)->buildingsDone++;
			AudioManager::getInstance()->PlayBuild();

			active = false;
		}
		else {
			AudioManager::getInstance()->PlayCannotBuild();
		}
	}
}


void BuildingPlacingPointer::update(ShipManager* shipManager)
{
	if (active) {

		auto* map = shipManager->map;

		int motionX;
		int motionY;
		SDL_GetMouseState(&motionX, &motionY);

		for (int i = 0; i < ShipManager::SHIP_SIZE; i++) {
			for (int j = 0; j < ShipManager::SHIP_SIZE; j++) {
				Tile* tile = map[i][j];
				if (tile->containsPoint(motionX, motionY)) {
					this->x = tile->x;
					this->y = tile->y;

					if (tile->built
						&& tile->building == nullptr
						) {
						texture = correct;
						placeable = true;
						iToReplace = i;
						jToReplace = j;
					}
					else {
						texture = wrong;
						placeable = false;
					}
				}
			}
		}
	}
}