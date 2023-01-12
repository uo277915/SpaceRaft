#pragma once
#include "Item.h"

class RemoveBuildingItem :
    public Item
{
public:
	RemoveBuildingItem(Game* game) : Item("res/img/general/items/removeBuildingItem.png", game) {}
	void use(GameLayer* gamelayer) override {}
	void select(GameLayer* gamelayer) override;
	void deselect(GameLayer* gamelayer) override;
};

