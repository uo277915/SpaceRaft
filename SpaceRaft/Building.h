#pragma once
#include "Craftable.h";

class Building :
	public Craftable
{
public:
	Building(string filename, float x, float y, Game* game);
	void craft() override;

	string id = "-";
	bool hasCollision = false;
};