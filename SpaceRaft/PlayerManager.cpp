#include "PlayerManager.h"

#include "TrashGrabber.h"
#include "RemoveBuildingItem.h"
#include "RemoveTileItem.h"
#include "FileManager.h"

PlayerManager* PlayerManager::playerManagerInstance = nullptr;

PlayerManager* PlayerManager::getInstance(Game* game)
{
    if (playerManagerInstance == nullptr) {
        playerManagerInstance = new PlayerManager(game);
    }
    return playerManagerInstance;
}

void PlayerManager::initialize(vector<int> data)
{
    if (data.size() >= 6) {
        health = data[0];
        hunger = data[1];
        oxigen = data[2];

        metalAmount = data[3];
        meatAmount = data[4];
        ancientAmount = data[5];
    }
    else {
        cerr << "ERROR LOADING PLAYER DATA" << endl;
    }
}

PlayerManager::PlayerManager(Game* game) {
    items = new vector<Item*>();
    items->push_back(new TrashGrabber(game));
    items->push_back(new RemoveBuildingItem(game));
    items->push_back(new RemoveTileItem(game));

    this->game = game;
}

void PlayerManager::createPlayer(Game* game)
{
    player = new Player(WIDTH/2, HEIGHT/2, game);
}

void PlayerManager::add(int metal, int meat, int ancient)
{
    metalAmount += metal;
    meatAmount += meat;
    ancientAmount += ancient;
}

bool PlayerManager::use(int metal, int meat, int ancient)
{
    if (metalAmount - metal >= 0 && meatAmount - meat >= 0) {
        metalAmount -= metal;
        meatAmount -= meat;
        ancientAmount -= ancient;

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
void PlayerManager::update()
{
    if (buildingsDone != 0) {
        oxigenStep += buildingsDone * 0.25;
        hungerStep += buildingsDone * 0.25;
        healthStep += buildingsDone * 0.25;

        buildingsDone = 0;
    }

    timeUntilBreath--;

    if (timeUntilBreath <= 0) {
        timeUntilBreath = MAX_TIME_UNTIL_BREATH;
        oxigen-=oxigenStep;
        if (oxigen <= 0) {
            oxigen = 0;
        } if (oxigen >= MAX_OXIGEN) {
            oxigen = MAX_OXIGEN;
        }

        if (oxigen <= 0) {
            health-=healthStep;
            if (health <= 0) {
                health = 0;
            } if (health >= MAX_HEALTH) {
                health = MAX_HEALTH;
            }
        }
    }

    timeUntilHunger--;

    if (timeUntilHunger <= 0) {
        timeUntilHunger = MAX_TIME_UNTIL_HUNGER;
        hunger-=hungerStep;
        if (hunger <= 0) {
            hunger = 0;
        } if (hunger >= MAX_HUNGER) {
            hunger = MAX_HUNGER;
        }

        if (hunger <= 0) {
            health-=healthStep;
            if (health <= 0) {
                health = 0;
            } if (health >= MAX_HEALTH) {
                health = MAX_HEALTH;
            }
        }
    }

    if (health <= 0) {
        FileManager::getInstance()->resetPlayer(game);
        exit(0);
    }

    player->update();
}

bool PlayerManager::canBuild(Craftable* craftable)
{
    if (craftable->priceMetal <= metalAmount && 
        craftable->priceMeat <= meatAmount && 
        craftable->priceAncient <= ancientAmount
        ) {
        return true;
    }
    return false;
}

void PlayerManager::build(Craftable* craftable)
{
    if (canBuild(craftable)) {
        metalAmount -= craftable->priceMetal;
        meatAmount -= craftable->priceMeat;
        ancientAmount -= craftable->priceAncient;
    }
}

void PlayerManager::SelectItem(int item, GameLayer* layer)
{
    if (item < items->size()) {
        items->at(selectedItem)->deselect(layer);
        selectedItem = item;
        items->at(selectedItem)->select(layer);
    }
}

void PlayerManager::NextItem(GameLayer* layer)
{
    if (selectedItem <= 0) {
        SelectItem(items->size() - 1, layer);
    }
    else
    {
        SelectItem(selectedItem-1, layer);
    }
}

void PlayerManager::PreviousItem(GameLayer* layer)
{
    if (selectedItem >= items->size() - 1) {
        SelectItem(0, layer);
    }
    else
    {
        SelectItem(selectedItem + 1, layer);
    }
}
