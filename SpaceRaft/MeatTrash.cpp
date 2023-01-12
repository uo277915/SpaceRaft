#include "MeatTrash.h"
#include "PlayerManager.h"
#include "AudioManager.h"

void MeatTrash::handleClick()
{
	int motionX;
	int motionY;
	SDL_GetMouseState(&motionX, &motionY);

	if (this->isClicked(motionX, motionY)) {
		PlayerManager::getInstance(game)->add(0, 5, 0);
		AudioManager::getInstance()->PlayPickTrash();
		toRemove = true;
	}
}
