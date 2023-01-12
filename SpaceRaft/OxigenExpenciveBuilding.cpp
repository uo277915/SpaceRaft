#include "OxigenExpenciveBuilding.h"
#include "PlayerManager.h"

OxigenExpenciveBuilding::OxigenExpenciveBuilding(float x, float y, Game* game)
	: Building("res/img/boat/buildings/oxigen_expensive.png", x, y, game) {

	this->id = 'O';
	initializeCraftable();
}

void OxigenExpenciveBuilding::initializeCraftable() {
	name = "Advanced Oxigen Generator";
	description = "A generator that will give you a lot of oxigen!";

	type = BUILDING;

	priceMetal = 10;
	priceMeat = 5;
	priceAncient = 15;
}

Craftable* OxigenExpenciveBuilding::clone()
{
	return new OxigenExpenciveBuilding(x, y, game);
}

void OxigenExpenciveBuilding::craft()
{
	Building::craft();
	PlayerManager::getInstance(game)->oxigenStep -= 5;
}