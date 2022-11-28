#pragma once
#include "Layer.h"
#include "GameObject.h"
#include "Background.h"

class StoryLayer :
    public Layer
{
public:
	StoryLayer(Game* game);
	void init() override;
	void draw() override;
	void processControls() override;
	void keysToControls(SDL_Event event);
	void mouseToControls(SDL_Event event);
	void gamePadToControls(SDL_Event event);
	void nextBackground();
	bool controlContinue;
	SDL_GameController* gamePad; // Mando

	list<Background*> backgrounds;
	Background* background;

	std::list<Background*>::iterator bgIterator;
	int currentBG = -1;
};

