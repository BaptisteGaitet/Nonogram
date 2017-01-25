#ifndef LEVEL_MANAGER_H
#define LEVEL_MANAGER_H

#include "Level.h"
#include <vector>
#include <fstream>

class LevelManager
{
private:
	const std::string LEVELS_FILE = "nonograms.txt";

	LevelManager();
	LevelManager(LevelManager &const);
	void operator=(LevelManager &const);

	std::vector<Level*> levels;
	int selectedLevel;
public:
	static LevelManager& getInstance();

	void addLevel(Level* _level);
	Level* getLevel(int index);
	int getLevelCount();
	bool hasLevel(int _index);
	void setSelectedLevel(int _index);
	int getSelectedLevel();

	void loadLevels();

	~LevelManager();
};

#endif