#ifndef LEVEL_SELECT_STATE_H
#define LEVEL_SELECT_STATE_H

#include "State.h"
#include "UIBackground.h"
#include "UIImage.h"
#include "UIButton.h"
#include "UILabel.h"

class LevelSelectState : public State
{
private:
	int selectedLevel;

	void updateLevelButtons();
public:
	LevelSelectState();

	void update();
	void draw(sf::RenderWindow* window);

	~LevelSelectState();
};

#endif