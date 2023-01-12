#include "RemoveBuildingItem.h"

void RemoveBuildingItem::select(GameLayer* gamelayer)
{
	gamelayer->buildRemover->active = true;
}

void RemoveBuildingItem::deselect(GameLayer* gamelayer)
{
	gamelayer->buildRemover->active = false;
}