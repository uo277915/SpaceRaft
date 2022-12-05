#include "Craftable.h"

void Craftable::initializeCraftable()
{
	name = "";
	description = "";

	priceMetal = 0;
	priceMeat = 0;
	priceAncient = 0;
}

Craftable::Craftable(string filename, float x, float y, int width, int height, Game* game)
	: GameObject(filename, x, y, height, width, game)
{

}
