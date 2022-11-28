#include "PlayerManager.h"

PlayerManager* PlayerManager::instance = nullptr;

PlayerManager* PlayerManager::getInstance()
{
    if (instance == nullptr) {
        instance = new PlayerManager();
    }
    return instance;
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

