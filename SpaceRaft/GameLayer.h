#pragma once

#include "Layer.h"
#include "Text.h"
#include "Audio.h" 
#include "Background.h" 
#include "FileManager.h" 
#include "Tile.h" 
#include "Pointer.h" 
#include "TilePlacingPointer.h"
#include "BuildingPlacingPointer.h"

#include <list>
#include "CollisionController.h"


/* Class defining the Game Layer */
class GameLayer : public Layer
{
public:
	//Methods
	/* Constructor for the Game Layer */
	GameLayer(Game* game);
	/* Initializes the Game Layer */
	void init() override;
	/* Processes the user controls */
	void processControls() override;
	/* Updates the game */
	void update() override;
	/* Draws the game */
	void draw() override;
	/* Transform the keys to controls */
	void keysToControls(SDL_Event event);
	void mouseToControls(SDL_Event event);
	void gamePadToControls(SDL_Event event);

	//Variables
	Background* background;
	SDL_GameController* gamePad; // Mando
	ShipManager* shipManager;
	CollisionController* collisionController;
	TilePlacingPointer* tilePointer;
	BuildingPlacingPointer* buildPointer;

	int controlMoveX = 0;
	int controlMoveY = 0;
};

