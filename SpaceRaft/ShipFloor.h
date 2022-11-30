#pragma once
#include "Tile.h"
class ShipFloor :
    public Tile
{
public:
    ShipFloor(float x, float y, Game* game);

    string toString() override;
    void draw() { Tile::draw(); }
};

