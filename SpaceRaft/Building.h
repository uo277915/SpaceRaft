#pragma once
#include "Craftable.h";

class Building :
	public Craftable
{
public:
	Building(string filename, float x, float y, int width, int height, Game* game);

	string id = "-";
	bool hasCollision = false;
};

