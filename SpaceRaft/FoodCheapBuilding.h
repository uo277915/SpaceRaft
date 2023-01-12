#pragma once
#include "Building.h"
class FoodCheapBuilding :
    public Building
{
public:
    FoodCheapBuilding(float x, float y, Game* game);
    void initializeCraftable();
    Craftable* clone() override;
    void craft() override;
};

