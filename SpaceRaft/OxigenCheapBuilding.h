#pragma once
#include "Building.h"
class OxigenCheapBuilding
	: public Building
{
public:
	OxigenCheapBuilding(float x, float y, Game* game);
	void initializeCraftable();
	Craftable* clone() override;
	void craft() override;
};

