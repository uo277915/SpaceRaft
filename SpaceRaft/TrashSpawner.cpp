#include "TrashSpawner.h"

#include "MetalTrash.h"
#include "MeatTrash.h"
#include "AncientTrash.h"

TrashSpawner::TrashSpawner(Game* game)
{
	this->game = game;
}

void TrashSpawner::update()
{
	// Creation
	if (timeToSpawn <= 0) {
		srand(time(NULL));
		timeToSpawn = rand() % (MAXTIMETOSPAWN - MINTIMETOSPAWN + 1) + MINTIMETOSPAWN;

		int trashToSpawnPercentage = rand() % 100;
		int randomX = rand() % WIDTH;

		if (trashToSpawnPercentage >= 0 && trashToSpawnPercentage < 40) {
			trash.push_back(new MetalTrash(randomX, game));
		}
		else if (trashToSpawnPercentage >= 50 && trashToSpawnPercentage < 75) {
			trash.push_back(new MeatTrash(randomX, game));
		}
		else if (trashToSpawnPercentage >= 75 && trashToSpawnPercentage < 90){
			trash.push_back(new AncientTrash(randomX, game));
		}
	}
	timeToSpawn--;

	// Move and deletion
	list<Trash*> trashToRemove;

	for (auto const& t : trash) {
		t->update();
		if (t->toRemove) {
			trashToRemove.push_back(t);
		}
	}

	for (auto const& t : trashToRemove) {
		trash.remove(t);
	}

	trashToRemove.clear();
}

void TrashSpawner::draw()
{
	for (auto const& t : trash) {
		t->draw();
	}
}

void TrashSpawner::handleClick()
{
	for (auto const& t : trash) {
		t->handleClick();
	}
}
