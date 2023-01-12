#pragma once
#include "Building.h"
class FoodExpensiveBuilding :
    public Building
{
public:
    FoodExpensiveBuilding(float x, float y, Game* game);
    void initializeCraftable();
    Craftable* clone() override;
    void craft() override;
};

