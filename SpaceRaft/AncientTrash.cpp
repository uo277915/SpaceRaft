#include "AncientTrash.h"
#include "PlayerManager.h"
#include "AudioManager.h"

void AncientTrash::handleClick()
{
	int motionX;
	int motionY;
	SDL_GetMouseState(&motionX, &motionY);

	if (this->isClicked(motionX, motionY)) {
		PlayerManager::getInstance(game)->add(0, 0, 1);
		AudioManager::getInstance()->PlayPickTrash();
		toRemove = true;
	}
}
