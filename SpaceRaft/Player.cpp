#include "Player.h"
#include "ShipManager.h"

Player::Player(float x, float y, Game* game) : GameObject("res/img/general/player.png", x, y, 75, 150, game)
{
	playerAnimation = new Animation("res/img/general/playerAnimation.png", 75, 150, 225, 150, 5, 3, true, game);
}

void Player::update()
{
	playerAnimation->update();
}

void Player::moveX(float vx)
{
	this->vx = vx * speed;
}

void Player::moveY(float vy)
{
	this->vy = vy * speed;
}

void Player::draw()
{
	playerAnimation->drawDown(x, y);
}
