#pragma once

#include "Item.h"
#include <vector>
#include "Player.h"

class PlayerManager
{
public:
	static PlayerManager* getInstance();
	Player* player;
	void createPlayer(Game* game);
	void add(int metal, int meat);
	bool use(int metal, int meat);
	void hit(int damage);
	void heal(int health);
	void lowerHunger(int hunger);
	void increaseHunger(int hunger);
	void setSpawnPoint(float x, float y);

	Item* selectedItem;

	const int MAX_HEALTH = 100;
	const int MAX_HUNGER = 100;

private:
	static PlayerManager* instance;

	int metalAmount;
	int meatAmount;

	int health;
	int hunger;

	std::vector<Item> items;

	int spawnX = 0;
	int spawnY = 0;
};

