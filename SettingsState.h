#ifndef SETTINGS_STATE_H
#define SETTINGS_STATE_H

#include "State.h"
#include "UIBackground.h"
#include "UIImage.h"
#include "UIButton.h"
#include "UILabel.h"
#include "UISlider.h"
#include "LevelManager.h"
#include "AudioManager.h"

class SettingsState : public State
{
private:
	bool warning;
public:
	SettingsState();

	void update();
	void draw(sf::RenderWindow* window);

	~SettingsState();
};

#endif