#pragma once
#include "Item.h"

class TrashGrabber
	: public Item
{
public:
	TrashGrabber(Game* game) : Item("res/img/general/items/trashGrabber.png", game) {}
	void use(GameLayer* gamelayer) {}
	void select(GameLayer* gamelayer) override;
	void deselect(GameLayer* gamelayer) override;
};

