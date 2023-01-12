#pragma once
#include "Tile.h"
class AncientFloor :
    public Tile
{
public:
    AncientFloor(float x, float y, Game* game);

    string toString() override;
    void initializeCraftable() override;
    Craftable* clone() override;
    void draw() { Tile::draw(); }

};

