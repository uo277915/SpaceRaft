#include "BuildingRemovePointer.h"
#include "EmptyTile.h"
#include "PlayerManager.h"
#include "AudioManager.h"


BuildingRemovePointer::BuildingRemovePointer(Game* game) : Pointer(game)
{
	this->tileToPlace = new EmptyTile(0, 0, game);
}

void BuildingRemovePointer::handleClick(ShipManager* shipManager, CollisionController* collisionController)
{
	if (active) {
		int motionX;
		int motionY;
		SDL_GetMouseState(&motionX, &motionY);

		if (placeable) {
			shipManager->map[iToReplace][jToReplace]->building = nullptr;
			PlayerManager::getInstance(game)->buildingsDone--;
			AudioManager::getInstance()->PlayDestroy();
		}
		else {
			AudioManager::getInstance()->PlayCannotBuild();
		}
	}
}

void BuildingRemovePointer::update(ShipManager* shipManager)
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

					if (tile->building != nullptr) {

						iToReplace = i;
						jToReplace = j;

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
