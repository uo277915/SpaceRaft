#pragma once
#include "Button.h"
#include "Animation.h"

class Trash :
    public Button
{
public:
    Trash(string filename, float x, float y, int width, int height, Game* game) 
        : Button(filename, x, y, width, height, game) {}
    void update();
    void draw() override;

    bool toRemove = false;
    Animation* trashAnimation;
};

