#include "BuildingPlacingPointer.h"

BuildingPlacingPointer::BuildingPlacingPointer(Game* game) : Pointer(game)
{
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