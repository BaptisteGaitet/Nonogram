#ifndef LEVEL_SELECT_STATE_H
#define LEVEL_SELECT_STATE_H

#include "State.h"
#include "UIBackground.h"
#include "UIImage.h"
#include "UIButton.h"

class LevelSelectState : public State
{
public:
	LevelSelectState();

	void update();
	void draw(sf::RenderWindow* window);

	~LevelSelectState();
};

#endif