#pragma once
#include "Game.h"
#include "Trash.h"

class TrashSpawner
{
public:
	TrashSpawner(Game* game);
	void update();
	void draw();

	void handleClick();

	Game* game;
	list<Trash*> trash;
	
	int timeToSpawn = 50;

	const int MINTIMETOSPAWN = 75;
	const int MAXTIMETOSPAWN = 150;
};

