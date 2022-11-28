#pragma once
#include "Layer.h"
#include "GameObject.h"
#include "Background.h"

class MainMenuLayer :
    public Layer
{
public:
	MainMenuLayer(Game* game);
	void init() override;
	void draw() override;
	void processControls() override;
	void keysToControls(SDL_Event event);
	void mouseToControls(SDL_Event event);
	void gamePadToControls(SDL_Event event);
	bool controlContinue;
	SDL_GameController* gamePad; // Mando
	Background* background;
	GameObject* button;

};

