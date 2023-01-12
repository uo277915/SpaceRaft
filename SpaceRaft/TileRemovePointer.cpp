#include "TileRemovePointer.h"
#include "TileImageNotFound.h"
#include "PlayerManager.h"
#include "EmptyTile.h"
#include "AudioManager.h"


TileRemovePointer::TileRemovePointer(Game* game) : Pointer(game)
{
	this->tileToPlace = new EmptyTile(0, 0, game);
}

void TileRemovePointer::handleClick(ShipManager* shipManager, CollisionController* collisionController)
{
	if (active) {
		int motionX;
		int motionY;
		SDL_GetMouseState(&motionX, &motionY);

		if (placeable) {
			this->tileToPlace = new EmptyTile(0, 0, game);
			Tile* oldTile = shipManager->map[iToReplace][jToReplace];

			if (tileToPlace == nullptr) {
				tileToPlace = new TileImageNotFound(motionX, motionY, game);
			}
			else {
				tileToPlace->x = oldTile->x;
				tileToPlace->y = oldTile->y;
			}

			shipManager->map[iToReplace][jToReplace] = tileToPlace;
			PlayerManager::getInstance(game)->buildingsDone--;

			if (!oldTile->hasCollision) {
				collisionController->addCollider(shipManager->map[iToReplace][jToReplace]);
			}
			AudioManager::getInstance()->PlayDestroy();
		}
		else {
			AudioManager::getInstance()->PlayCannotBuild();
		}
	}
}

void TileRemovePointer::update(ShipManager* shipManager)
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

					auto* player = PlayerManager::getInstance(game)->player;

					if (tile->built // Is built (not empty)
						&& tile->building == nullptr // Has no building
						&& !map[i][j]->containsPoint(player->x, player->y) // Player is not on top
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
