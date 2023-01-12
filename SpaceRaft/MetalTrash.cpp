#include "MetalTrash.h"
#include "PlayerManager.h"
#include "AudioManager.h"

void MetalTrash::handleClick()
{
	int motionX;
	int motionY;
	SDL_GetMouseState(&motionX, &motionY);

	if (this->isClicked(motionX, motionY)) {
		PlayerManager::getInstance(game)->add(5, 0, 0);
		AudioManager::getInstance()->PlayPickTrash();
		toRemove = true;
	}
}
