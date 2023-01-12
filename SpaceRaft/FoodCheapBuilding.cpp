#include "FoodCheapBuilding.h"
#include "PlayerManager.h"

FoodCheapBuilding::FoodCheapBuilding(float x, float y, Game* game)
	: Building("res/img/boat/buildings/food_cheap.png", x, y, game) {

	this->id = 'f';
	initializeCraftable();
}

void FoodCheapBuilding::initializeCraftable() {
	name = "Simple Food Generator";
	description = "A generator that will give you a little bit of food!";

	type = BUILDING;

	priceMetal = 5;
	priceMeat = 10;
	priceAncient = 5;
}

Craftable* FoodCheapBuilding::clone()
{
	return new FoodCheapBuilding(x, y, game);
}

void FoodCheapBuilding::craft()
{
	Building::craft();
	PlayerManager::getInstance(game)->hungerStep -= 1;
}
