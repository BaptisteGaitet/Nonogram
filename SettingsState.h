#ifndef SETTINGS_STATE_H
#define SETTINGS_STATE_H

#include "State.h"
#include "UIBackground.h"
#include "UIImage.h"
#include "UIButton.h"
#include "UILabel.h"
#include "UISlider.h"

class SettingsState : public State
{
public:
	SettingsState();

	void update();
	void draw(sf::RenderWindow* window);

	~SettingsState();
};

#endif