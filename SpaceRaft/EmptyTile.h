#pragma once
#include "Tile.h"
class EmptyTile :
    public Tile
{
public: 
        EmptyTile(float x, float y, Game* game);

        string toString() override;
        void draw() {}
};

