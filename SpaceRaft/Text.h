#pragma once

#include "Game.h"

/* Class defining a text */
class Text
{
public:
	//Methods
	/* Constructor for the Text */
	Text(string content, float x, float y, Game* game);
	/* Draws the text */
	void draw();

	//Variables
	string content;
	int x;
	int y;
	int width;
	int height;
	Game* game;
};

