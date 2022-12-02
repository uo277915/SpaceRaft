#pragma once

#include "GameObject.h"

/* Class that controls the background */
class Background : public GameObject
{
public:
	//Methods
	/* Constructor for a static background */
	Background(string filename, float x, float y, Game* game);
	/* Constructor for an animated background */
	Background(string filename, float x, float y, float vy, Game* game);
	/* Draws the background on screen */
	void draw() override;
	/* Updates the background */
	void update();

	//Variables
	Background* backgroundAux = nullptr;
};