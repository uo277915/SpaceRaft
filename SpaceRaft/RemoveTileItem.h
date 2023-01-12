#pragma once
#include "Item.h"

class RemoveTileItem
	: public Item
{
public:
	RemoveTileItem(Game* game) : Item("res/img/general/items/removeTileItem.png", game) {}
	void use(GameLayer* gamelayer) {}
	void select(GameLayer* gamelayer) override;
	void deselect(GameLayer* gamelayer) override;
};

