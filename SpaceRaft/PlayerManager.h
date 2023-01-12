#pragma once

#include <vector>
#include "Player.h"
#include "Craftable.h"
#include "Item.h"
#include "GameLayer.h"

class PlayerManager
{
public:
	PlayerManager(Game* game);
	static PlayerManager* getInstance(Game* game);
	void initialize(vector<int> data);
	Player* player;
	void createPlayer(Game* game);
	void add(int metal, int meat, int ancient);
	bool use(int metal, int meat, int ancient);
	void hit(int damage);
	void heal(int health);
	void lowerHunger(int hunger);
	void increaseHunger(int hunger);
	void setSpawnPoint(float x, float y);
	void update();

	bool canBuild(Craftable* craftable);
	void build(Craftable* craftable);

	void SelectItem(int item, GameLayer* layer);
	void NextItem(GameLayer* layer);
	void PreviousItem(GameLayer* layer);

	Game* game;

	int selectedItem = 0;

	const float MAX_HEALTH = 100;
	const float MAX_HUNGER = 100;
	const float MAX_OXIGEN = 100;
	const float SPEED = 10;

	float healthStep = -0.25;
	float hungerStep = -0.25;
	float oxigenStep = -0.25;

	int timeUntilBreath = 100;
	int timeUntilHunger = 200;

	const int MAX_TIME_UNTIL_HUNGER = 200;
	const int MAX_TIME_UNTIL_BREATH = 100;

	static PlayerManager* playerManagerInstance;

	int metalAmount = 0;
	int meatAmount = 0;
	int ancientAmount = 0;

	int health = 100;
	int hunger = 50;
	int oxigen = 100;

	std::vector<Item*>* items;

	int spawnX = 0;
	int spawnY = 0;

	int buildingsDone = 0;
};
