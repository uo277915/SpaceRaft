#include "ShipManager.h"

ShipManager::ShipManager()
{
}

void ShipManager::draw()
{
	for (int i = 0; i < ShipManager::SHIP_SIZE; i++) {
		for (int j = 0; j < ShipManager::SHIP_SIZE; j++) {
			map[i][j]->draw();
		}
	}
}

string ShipManager::toString()
{
	string str = "Ship:\n";

	for (int i = 0; i < ShipManager::SHIP_SIZE; i++) {
		for (int j = 0; j < ShipManager::SHIP_SIZE; j++) {
			str += map[i][j]->toString() + "\t";
		}
		str += "\n";
	}

	return str;
}
