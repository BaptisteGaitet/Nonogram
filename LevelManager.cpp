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

void LevelManager::loadLevels()
{
	std::ifstream file;
	std::string line;
	file.open(LEVELS_FILE);

	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			int rows = 0;
			int columns = 0;
			std::string path = "";
			std::string description = "";
			std::vector<std::string> sections;
			sections.push_back("");
			int sectionCount = 0;

			// Get header content
			for (int i = 0; i < line.size(); i++)
			{
				if (line.at(i) == '/')
				{
					sectionCount++;
					sections.push_back("");
				} else if (line.at(i) == '\\' && line.at(i + 1) == 'n')
				{
					sections.at(sectionCount) += ("\n");
					i++;
				}
				else
				{
					sections.at(sectionCount) += line.at(i);
				}
			}

			// Register content
			rows = atoi(sections.at(0).c_str());
			columns = atoi(sections.at(1).c_str());
			path = sections.at(2);
			description = sections.at(3);

			// Get nonogram
			bool * nonogram = new bool[rows * columns];
			for (int i = 0; i < rows; i++)
			{
				std::getline(file, line);
				for (int j = 0; j < columns; j++)
				{
					if (line.at(j) == '1')
					{
						nonogram[i * rows + j] = true;
					}
					else if (line.at(j) == '0')
					{
						nonogram[i * rows + j] = false;
					}
				}
			}

			// Create Nonogram
			Nonogram * nono = new Nonogram(rows, columns, nonogram);

			// Create level
			Level * lvl = new Level(path, description, nono, false);

			// AddLevel
			addLevel(lvl);
		}
	}
	else
	{
		std::cout << "LevelManager: Can't open file: " + LEVELS_FILE + "\n";
	}

	file.close();
}

LevelManager::~LevelManager()
{
}
