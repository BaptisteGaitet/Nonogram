#include "SettingsState.h"


SettingsState::SettingsState() : State("settings")
{
	// TEST //

	UIBackground* bg = new UIBackground("background", 0, "bg5.png");
	uiholder.addUIElement(bg);
	UIImage* img = new UIImage("image", sf::IntRect(0, 0, 800, 600), 1, "book.png");
	uiholder.addUIElement(img);
	UIButton* btnBack = new UIButton("btn_back", sf::IntRect(100, 500, 64, 64), 2, "btn4.png");
	uiholder.addUIElement(btnBack);
	UILabel* lblMusic = new UILabel("lbl_music", sf::IntRect(120, 80, 100, 30), 2, "Music volume");
	uiholder.addUIElement(lblMusic);
	UISlider* sldMusic = new UISlider("sld_music", sf::IntRect(120, 120, 250, 20), 3);
	uiholder.addUIElement(sldMusic);
	UILabel* lblSfx= new UILabel("lbl_sfx", sf::IntRect(120, 160, 100, 30), 2, "Sound effects volume");
	uiholder.addUIElement(lblSfx);
	UISlider* sldSfx = new UISlider("sld_sfx", sf::IntRect(120, 200, 250, 20), 3);
	uiholder.addUIElement(sldSfx);

	//////////
}

// Updates the state
void SettingsState::update()
{
	uiholder.update();

	UIButton* btnBack = (UIButton*)uiholder.getUIElement("btn_back");
	if (btnBack->getClic())
	{
		setNextStateId("title");
	}
}

// Draws the state
void SettingsState::draw(sf::RenderWindow* window)
{
	uiholder.draw(window);
}


SettingsState::~SettingsState()
{
}
