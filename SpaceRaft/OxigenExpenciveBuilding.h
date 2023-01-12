#pragma once
#include "Building.h"
class OxigenExpenciveBuilding
	: public Building
{
public:
	OxigenExpenciveBuilding(float x, float y, Game* game);
	void initializeCraftable();
	Craftable* clone() override;
	void craft() override;
};

