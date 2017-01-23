#include "LevelManager.h"


LevelManager::LevelManager()
{
	selectedLevel = 0;
}

LevelManager& LevelManager::getInstance()
{
	static LevelManager instance;
	return instance;
}

void LevelManager::addLevel(Level* _level)
{
	levels.push_back(_level);
}

Level* LevelManager::getLevel(int index)
{
	return levels.at(index);
}

int LevelManager::getLevelCount()
{
	return levels.size();
}

bool LevelManager::hasLevel(int _index)
{
	return (_index < levels.size());
}

void LevelManager::setSelectedLevel(int _index)
{
	if (hasLevel(_index))
		selectedLevel = _index;
}

int LevelManager::getSelectedLevel()
{
	return selectedLevel;
}

LevelManager::~LevelManager()
{
}
