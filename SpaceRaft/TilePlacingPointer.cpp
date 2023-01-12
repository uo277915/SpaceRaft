#include "TilePlacingPointer.h"
#include "TileImageNotFound.h"
#include "GameLayer.h"
#include "PlayerManager.h"
#include "AudioManager.h"

TilePlacingPointer::TilePlacingPointer(Game* game) : Pointer(game) 
{
}

void TilePlacingPointer::loadTile(Tile* tile)
{
	this->tileToPlace = tile;
}

void TilePlacingPointer::handleClick(ShipManager* shipManager, CollisionController* collisionController)
{
	if (active) {
		int motionX;
		int motionY;
		SDL_GetMouseState(&motionX, &motionY);

		if (placeable) {
			Tile* oldTile = shipManager->map[iToReplace][jToReplace];

			if (tileToPlace == nullptr) {
				tileToPlace = new TileImageNotFound(motionX, motionY, game);
			}
			else {
				tileToPlace->x = oldTile->x;
				tileToPlace->y = oldTile->y;
			}

			if (!tileToPlace->hasCollision) {
				collisionController->removeCollider(shipManager->map[iToReplace][jToReplace]);
			}
			shipManager->map[iToReplace][jToReplace] = tileToPlace;
			PlayerManager::getInstance(game)->buildingsDone++;

			active = false;
			AudioManager::getInstance()->PlayBuild();
		}
		else {
			AudioManager::getInstance()->PlayCannotBuild();
		}
	}
}

void TilePlacingPointer::update(ShipManager* shipManager)
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

					if (tile->buildable
						&& ((i + 1 < ShipManager::SHIP_SIZE && map[i + 1][j]->built)
							|| (i - 1 >= 0 && map[i - 1][j]->built)
							|| (j + 1 < ShipManager::SHIP_SIZE && map[i][j + 1]->built)
							|| (j - 1 >= 0 && map[i][j - 1]->built))
						//&& PlayerManager::getInstance()->canBuild(tile)
						) {

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
