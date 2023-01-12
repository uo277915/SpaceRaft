#pragma once
#include "Trash.h"
class MetalTrash :
    public Trash
{
public:
    MetalTrash(float x, Game* game)
        : Trash("res/img/boat/pickables/metal.png", x, -100, 150, 150, game) 
    {
        trashAnimation = new Animation("res/img/boat/pickables/metalAnimation.png", 150, 150, 450, 150, 10, 3, true, game);
    }
    void handleClick() override;
};

