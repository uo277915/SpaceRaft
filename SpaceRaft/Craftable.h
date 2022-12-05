#pragma once
#include "GameObject.h"

class Craftable :
    public GameObject
{
public:
    Craftable(string filename, float x, float y, int width, int height, Game* game);

    string name = "";
    string description = "";
    
    int priceMetal = 0;
    int priceMeat = 0;
    int priceAncient = 0;

    virtual void initializeCraftable();
};

