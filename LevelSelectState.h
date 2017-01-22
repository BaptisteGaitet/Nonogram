#ifndef LEVEL_SELECT_STATE_H
#define LEVEL_SELECT_STATE_H

#include "State.h"
#include "UIBackground.h"
#include "UIImage.h"
#include "UIButton.h"
#include "UILabel.h"
#include "UILevelButton.h"
#include "LevelManager.h"

class LevelSelectState : public State
{
private:
	const int LEVELS_PER_PAGE = 9;
	
	int selectedLevel;
	int currentPage;

	void updateLevelInfo();
	void updateLevelButtons();
public:
	LevelSelectState();

	void update();
	void draw(sf::RenderWindow* window);

	~LevelSelectState();
};

#endif