#pragma once
#include "Trash.h"
class AncientTrash :
    public Trash
{
public:
    AncientTrash(float x, Game* game)
        : Trash("res/img/boat/pickables/ancient.png", x, -100, 150, 150, game)
    {
        trashAnimation = new Animation("res/img/boat/pickables/ancientAnimation.png", 150, 150, 450, 150, 10, 3, true, game);
    }
    void handleClick() override;
};

