#pragma once
#include "GameObject.h"

extern enum Type {
    TILE,
    BUILDING,
    OTHER
};

class Craftable :
    public GameObject
{
public:
    Craftable(string filename, float x, float y, int width, int height, Game* game);

    string name = "";
    string description = "";
    
    Type type = OTHER;

    int priceMetal = 0;
    int priceMeat = 0;
    int priceAncient = 0;

    virtual void initializeCraftable();
};

