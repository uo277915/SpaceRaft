#include "FoodExpensiveBuilding.h"
#include "PlayerManager.h"

FoodExpensiveBuilding::FoodExpensiveBuilding(float x, float y, Game* game)
	: Building("res/img/boat/buildings/food_expensive.png", x, y, game) {

	this->id = 'F';
	initializeCraftable();
}

void FoodExpensiveBuilding::initializeCraftable() {
	name = "Ancient Food Generator";
	description = "A generator that will give you a lot of food!";

	type = BUILDING;

	priceMetal = 5;
	priceMeat = 15;
	priceAncient = 15;
}

Craftable* FoodExpensiveBuilding::clone()
{
	return new FoodExpensiveBuilding(x, y, game);
}

void FoodExpensiveBuilding::craft()
{
	Building::craft();
	PlayerManager::getInstance(game)->hungerStep -= 5;
}