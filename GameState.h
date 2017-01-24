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
	const int VICTORY_TIME = 20;
	const int CELL_CHANGE_TIME = 2;
	const int LEVEL_TIME = 108000;
	const int CELL_SIZE = 24;
	bool warning;
	bool focus;
	bool solved;
	bool failed;
	Level* level;
	int currentLevel;
	int timer;
	int cellChangeTimer;
	int victoryTimer;

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