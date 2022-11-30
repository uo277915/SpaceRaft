#include "Player.h"

Player::Player(float x, float y, Game* game) : GameObject("res/img/general/player.png", x, y, 50, 100, game)
{

}

void Player::update()
{
    
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
	SDL_Rect source;
	source.x = 0;
	source.y = 0;
	source.w = fileWidth;
	source.h = fileHeight;

	SDL_Rect destination;
	destination.x = x - width / 2;
	destination.y = y - height;
	destination.w = width;
	destination.h = height;

	SDL_RenderCopyEx(game->renderer,
		texture, &source, &destination, 0, NULL, SDL_FLIP_NONE);
}
