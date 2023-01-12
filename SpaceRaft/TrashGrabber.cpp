#include "TrashGrabber.h"

void TrashGrabber::select(GameLayer* gamelayer)
{
	gamelayer->grabbable = true;
}

void TrashGrabber::deselect(GameLayer* gamelayer)
{
	gamelayer->grabbable = false;
}
