#pragma once
#include "Game.h"

class GameObject
{

public:
	//Methods
	/* Constructor for the Actor */
	GameObject(string filename, float x, float y, int width, int height, Game* game);
	/* Destructor for the Actor */
	~GameObject();
	/* Draws the actor */
	virtual void draw();
	/* Checks whether it overlaps another actor */
	bool isOverlap(GameObject* actor);
	/* Checks whether an actor is in render */
	bool isInRender();

	bool containsPoint(int pointX, int pointY);

	//Variables
	SDL_Texture* texture;
	int x;
	int y;
	float vx;
	float vy;
	int width;
	int height;
	int fileWidth;
	int fileHeight;
	Game* game;
};

