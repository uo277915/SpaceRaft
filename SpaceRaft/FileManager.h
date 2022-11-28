#pragma once

#include "Logger.h"

class FileManager
{
public:
	static FileManager* getInstance();
	void loadPlayer();
	void loadShip();
	void loadMap();

	void savePlayer();
	void saveShip();

protected:
	static FileManager* instance;
};

