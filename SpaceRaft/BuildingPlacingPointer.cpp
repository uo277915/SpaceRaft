#include "BuildingPlacingPointer.h"

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
			Building* oldBuilding = shipManager->map[iToReplace][jToReplace]->building;

			if (buildingToPlace == nullptr) {
				//buildingToPlace = new TileImageNotFound(motionX, motionY, game);
			}
			else {
				buildingToPlace->x = oldBuilding->x;
				buildingToPlace->y = oldBuilding->y;
			}

			if (!buildingToPlace->hasCollision) {
				collisionController->removeCollider(shipManager->map[iToReplace][jToReplace]);
			}
			shipManager->map[iToReplace][jToReplace]->building = buildingToPlace;

			active = false;
		}
		else {
			active = false;
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