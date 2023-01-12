#include "Button.h"

void Button::handleClick()
{
}

bool Button::isClicked(float mouseX, float mouseY)
{
	return this->containsPoint(mouseX, mouseY);
}
