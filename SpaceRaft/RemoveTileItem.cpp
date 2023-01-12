#include "RemoveTileItem.h"

void RemoveTileItem::select(GameLayer* gamelayer)
{
	gamelayer->tileRemover->active = true;
}

void RemoveTileItem::deselect(GameLayer* gamelayer)
{
	gamelayer->tileRemover->active = false;
}