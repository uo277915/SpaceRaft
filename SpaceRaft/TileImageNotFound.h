#pragma once
#include "Tile.h"
class TileImageNotFound :
    public Tile
{
public:

    TileImageNotFound(float x, float y, Game* game);

    string toString() override;
    void draw() { Tile::draw(); }
};

