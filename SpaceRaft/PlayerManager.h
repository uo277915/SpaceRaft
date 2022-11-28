#pragma once

#include "Item.h"
#include <vector>

class PlayerManager
{
public:
	static PlayerManager* getInstance();
	void add(int metal, int meat);
	bool use(int metal, int meat);
	void hit(int damage);
	void heal(int health);
	void lowerHunger(int hunger);
	void increaseHunger(int hunger);

	Item* selectedItem;

	int MAX_HEALTH = 100;
	int MAX_HUNGER = 100;

private:
	static PlayerManager* instance;

	int metalAmount;
	int meatAmount;

	int health;
	int hunger;

	std::vector<Item> items;

};

