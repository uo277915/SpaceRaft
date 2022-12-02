#include "Background.h"

Background::Background(string filename, float x, float y, Game* game)
    : GameObject(filename, x, y, WIDTH, HEIGHT, game) {

}

Background::Background(string filename, float x, float y, float vy, Game* game)
    : GameObject(filename, x, y, WIDTH, HEIGHT, game) {

    this->vy = vy;
    if (vy != 0) {
        backgroundAux = new Background(filename, x, y - HEIGHT, game);
    }
}

void Background::update() {

    if (vy != 0) {
        y += vy;
        backgroundAux->y += vy;

        if (y + height / 2 < 0) {
            y = HEIGHT + height / 2;
        }
        if (backgroundAux->y + height / 2 < 0) {
            backgroundAux->y = HEIGHT + height / 2;
        }

        if (y - height / 2 > HEIGHT) {
            y = 0 - height / 2;
        }
        if (backgroundAux->y - height / 2 > HEIGHT) {
            backgroundAux->y = 0 - height / 2;
        }
    }
}

void Background::draw() {
    GameObject::draw(); // llamar al metodo del hijo

    if (backgroundAux != NULL) {
        backgroundAux->draw();
    }

}