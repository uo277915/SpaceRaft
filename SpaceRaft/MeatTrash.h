#pragma once
#include "Trash.h"
class MeatTrash :
    public Trash
{
public:
    MeatTrash(float x, Game* game)
        : Trash("res/img/boat/pickables/meat.png", x, -100, 150, 150, game)
    {
        trashAnimation = new Animation("res/img/boat/pickables/meatAnimation.png", 150, 150, 450, 150, 10, 3, true, game);
    }
    void handleClick() override;
};

