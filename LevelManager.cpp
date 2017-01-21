#include "LevelManager.h"


LevelManager::LevelManager()
{
}

LevelManager& LevelManager::getInstance()
{
	static LevelManager instance;
	return instance;
}

void LevelManager::addLevel(Level _level)
{
	levels.push_back(_level);
}

Level LevelManager::getLevel(int index)
{
	return levels.at(index);
}

int LevelManager::getLevelCount()
{
	return levels.size();
}

LevelManager::~LevelManager()
{
}
