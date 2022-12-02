#include "Pointer.h"

Pointer::Pointer(Game* game) : GameObject("", 0, 0, ShipManager::SHIP_SIZE, ShipManager::SHIP_SIZE, game)
{
	correct = game->getTexture("res/img/boat/tiles/pointer/green_pointer.png");
	wrong = game->getTexture("res/img/boat/tiles/pointer/red_pointer.png");
	texture = wrong;
	placeable = false;
	active = false;
	this->game = game;
}

void Pointer::update(ShipManager* shipManager)
{
}
