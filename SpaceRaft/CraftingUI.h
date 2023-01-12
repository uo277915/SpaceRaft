#pragma once
#include "Craftable.h"
#include <vector>
#include "Button.h"

class CraftingUI
{
public:
	CraftingUI(Game* game);
	void draw();
	void handleClick();
	void keysToControls(SDL_Event event);

	Game* game;
	int selectedItem = 0;
	bool active = false;
	vector<Craftable*> craftables;
	Button* button;
};

