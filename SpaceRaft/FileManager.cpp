#include "FileManager.h"

FileManager* FileManager::instance = nullptr;

FileManager* FileManager::getInstance()
{
    if (instance == nullptr) {
        Logger::log(0, "FileManager", "File Manager initialized");
        instance = new FileManager();
    }
    Logger::log(0, "FileManager", "File Manager loaded");
    return instance;
}

void FileManager::loadPlayer()
{
    Logger::log(1, "FileManager", "Player data has been loaded...");
}

void FileManager::loadShip()
{
    Logger::log(1, "FileManager", "Ship data has been loaded...");
}

void FileManager::loadMap()
{
    Logger::log(1, "FileManager", "Map data has been loaded...");
}

void FileManager::savePlayer()
{
    Logger::log(1, "FileManager", "Player data has been saved...");
}

void FileManager::saveShip()
{
    Logger::log(1, "FileManager", "Ship data has been saved...");
}
