#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "State.h"
#include "UIBackground.h"
#include "UIImage.h"
#include "UIButton.h"
#include "UILabel.h"
#include "UINonogramCell.h"
#include "Level.h"
#include "LevelManager.h"

class GameState :
	public State
{
private:
	const int LEVEL_TIME = 108000;
	const int CELL_SIZE = 24;
	bool warning;
	Level* level;
	int currentLevel;
	int timer;

	void initCells();
	void deleteCells();
public:
	GameState();

	void update();
	void draw(sf::RenderWindow* window);
	void setLevel(Level* level);

	~GameState();
};

#endif