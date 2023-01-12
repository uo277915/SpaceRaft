#include "OxigenCheapBuilding.h"
#include "PlayerManager.h"

OxigenCheapBuilding::OxigenCheapBuilding(float x, float y, Game* game)
	: Building("res/img/boat/buildings/oxigen_cheap.png", x, y, game) {

	this->id = 'o';
	initializeCraftable();
}

void OxigenCheapBuilding::initializeCraftable() {
	name = "Simple Oxigen Generator";
	description = "A generator that will give you a little bit of oxigen!";

	type = BUILDING;

	priceMetal = 5;
	priceMeat = 5;
	priceAncient = 10;
}

Craftable* OxigenCheapBuilding::clone()
{
	return new OxigenCheapBuilding(x, y, game);
}

void OxigenCheapBuilding::craft()
{
	Building::craft();
	PlayerManager::getInstance(game)->oxigenStep -= 1;
}