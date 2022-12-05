#include "PlayerManager.h"

PlayerManager* PlayerManager::playerManagerInstance = nullptr;

PlayerManager* PlayerManager::getInstance()
{
    if (playerManagerInstance == nullptr) {
        playerManagerInstance = new PlayerManager();
    }
    return playerManagerInstance;
}

void PlayerManager::createPlayer(Game* game)
{
    player = new Player(WIDTH/2, HEIGHT/2, game);
}

void PlayerManager::add(int metal, int meat)
{
    metalAmount += metal;
    meatAmount += meat;
}

bool PlayerManager::use(int metal, int meat)
{
    if (metalAmount - metal >= 0 && meatAmount - meat >= 0) {
        metalAmount -= metal;
        meatAmount -= meat;

        return true;
    }
    return false;
}

void PlayerManager::hit(int damage)
{
    health -= damage;
}

void PlayerManager::heal(int health)
{
    this->health += health;
}

void PlayerManager::lowerHunger(int hunger)
{
    this->hunger -= hunger;
}

void PlayerManager::increaseHunger(int hunger)
{
    this->hunger += hunger;
}

void PlayerManager::setSpawnPoint(float x, float y)
{
    spawnX = x;
    spawnY = y;
    player->x = x;
    player->y = y;
}
/*
bool PlayerManager::canBuild(Craftable* craftable)
{
    if (craftable->priceMetal < metalAmount
        && craftable->priceMeat < meatAmount
        && craftable->priceAncient < ancientAmount
        ) {
        return true;
    }
    return false;
}*/