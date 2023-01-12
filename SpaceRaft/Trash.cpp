#include "Trash.h"

void Trash::update()
{
	if (!toRemove) {
		y += 1;

		if (y == HEIGHT + this->height) {
			toRemove = true;
		}	
	}

	trashAnimation->update();
}

void Trash::draw()
{
	trashAnimation->draw(x, y);
}