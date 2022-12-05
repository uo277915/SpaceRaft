#pragma once

#include "Background.h"
#include "ShipManager.h"
#include "CollisionController.h"
#include "TilePlacingPointer.h"
#include "TileRemovePointer.h"
#include "BuildingPlacingPointer.h"

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
	TileRemovePointer* tileRemover;
	BuildingPlacingPointer* buildPointer;

	int controlMoveX = 0;
	int controlMoveY = 0;
};

