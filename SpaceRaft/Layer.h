#pragma once

#include "Logger.h"
#include "Game.h"
class Game;

/* Class describing a Layer */
class Layer
{
public:
	//Methods
	/* Contructor for the Layer */
	Layer(Game* game);
	/* Initializes the Layer */
	virtual void init() {};
	/* Processes the user controls */
	virtual void processControls() {};
	/* Updates the Layer */
	virtual void update() {};
	/* Draws the Layer */
	virtual void draw() {};

	//Variables
	Game* game;
};
