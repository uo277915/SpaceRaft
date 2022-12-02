#pragma once
#include "Tile.h"
class RustyFloor :
    public Tile
{
public:
    RustyFloor(float x, float y, Game* game);

    string toString() override;
    void draw() { Tile::draw(); }
};

