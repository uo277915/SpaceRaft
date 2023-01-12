#pragma once
#include "Craftable.h"
#include "Building.h"

class Tile :
    public Craftable
{
public:
    Tile(string filename, float x, float y, Game* game);
    void draw() override;
    virtual string toString();
    void craft() override;

    bool buildable = false;
    bool built = false;
    bool hasCollision = true;

    Building* building = nullptr;
    string id = "?";
};

