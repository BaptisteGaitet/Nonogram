#ifndef LEVEL_MANAGER_H
#define LEVEL_MANAGER_H

#include "Level.h"
#include <vector>

class LevelManager
{
private:
	LevelManager();
	LevelManager(LevelManager &const);
	void operator=(LevelManager &const);

	std::vector<Level> levels;
public:
	static LevelManager& getInstance();

	void addLevel(Level _level);
	Level getLevel(int index);
	int getLevelCount();

	~LevelManager();
};

#endif