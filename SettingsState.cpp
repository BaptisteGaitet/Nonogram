#include "SettingsState.h"


SettingsState::SettingsState() : State("settings")
{
	warning = false;
	// TEST //

	UIBackground* bg = new UIBackground("background", 0, "bg5.png");
	uiholder.addUIElement(bg);
	UIImage* img = new UIImage("image", sf::IntRect(0, 0, 800, 600), 1, "book.png");
	uiholder.addUIElement(img);
	UIImage* sketch = new UIImage("sketch", sf::IntRect(400, 50, 300, 500), 1, "settingsSketch.png");
	uiholder.addUIElement(sketch);

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

	UILabel* lblFull= new UILabel("lbl_full", sf::IntRect(120, 280, 100, 30), 2, "Fullscreen");
	uiholder.addUIElement(lblFull);
	UIButton* btnFullOn = new UIButton("btn_full_on", sf::IntRect(270, 272, 64, 64), 2, "btnFullOn.png");
	uiholder.addUIElement(btnFullOn);
	UIButton* btnFullOff = new UIButton("btn_full_off", sf::IntRect(270, 272, 64, 64), 2, "btnFullOff.png");
	uiholder.addUIElement(btnFullOff);

	UILabel* lblReset = new UILabel("lbl_reset", sf::IntRect(120, 400, 100, 30), 2, "Reset save");
	uiholder.addUIElement(lblReset);
	UIButton* btnBomb= new UIButton("btn_bomb", sf::IntRect(270, 392, 64, 64), 2, "btnBomb.png");
	uiholder.addUIElement(btnBomb);

	UIImage* imgWarning = new UIImage("img_warning", sf::IntRect(250, 100, 300, 400), 3, "sheet.png");
	imgWarning->setEnabled(false);
	uiholder.addUIElement(imgWarning);
	UILabel* lblWarning = new UILabel("lbl_warning", sf::IntRect(280, 200, 100, 40), 4, "Are you sure ?");
	lblWarning->setEnabled(false);
	uiholder.addUIElement(lblWarning);
	UIButton* btnYes = new UIButton("btn_yes", sf::IntRect(290, 350, 64, 64), 4, "btnYes.png");
	btnYes->setEnabled(false);
	uiholder.addUIElement(btnYes);
	UIButton* btnNo = new UIButton("btn_no", sf::IntRect(450, 350, 64, 64), 4, "btnNo.png");
	btnNo->setEnabled(false);
	uiholder.addUIElement(btnNo);

	//////////
}

// Updates the state
void SettingsState::update()
{
	uiholder.update();
	if (!warning)
	{
		UIButton* btnBack = (UIButton*)uiholder.getUIElement("btn_back");
		if (btnBack->getClic())
		{
			setNextStateId("title");
		}

		UIButton* btnFullOff = (UIButton*)uiholder.getUIElement("btn_full_off");
		UIButton* btnFullOn = (UIButton*)uiholder.getUIElement("btn_full_on");
		if (WindowManager::getInstance().getFullscreen())
		{
			btnFullOn->setEnabled(true);
			btnFullOff->setEnabled(false);
		}
		else
		{
			btnFullOn->setEnabled(false);
			btnFullOff->setEnabled(true);
		}

		if (btnFullOff->getClic())
		{
			WindowManager::getInstance().setFullscreen(true);
		}

		if (btnFullOn->getClic())
		{
			WindowManager::getInstance().setFullscreen(false);
		}

		UIButton* btnBomb = (UIButton*)uiholder.getUIElement("btn_bomb");
		UIImage* imgWarning = (UIImage*)uiholder.getUIElement("img_warning");
		UILabel* lblWarning = (UILabel*)uiholder.getUIElement("lbl_warning");
		UIButton* btnYes = (UIButton*)uiholder.getUIElement("btn_yes");
		UIButton* btnNo = (UIButton*)uiholder.getUIElement("btn_no");
		if (btnBomb->getClic())
		{
			warning = true;

			imgWarning->setEnabled(true);
			lblWarning->setEnabled(true);
			btnYes->setEnabled(true);
			btnNo->setEnabled(true);
		}
	}
	else
	{
		UIButton* btnYes = (UIButton*)uiholder.getUIElement("btn_yes");
		UIButton* btnNo = (UIButton*)uiholder.getUIElement("btn_no");
		UIImage* imgWarning = (UIImage*)uiholder.getUIElement("img_warning");
		UILabel* lblWarning = (UILabel*)uiholder.getUIElement("lbl_warning");
		if (btnYes->getClic())
		{
			imgWarning->setEnabled(false);
			lblWarning->setEnabled(false);
			btnYes->setEnabled(false);
			btnNo->setEnabled(false);
			warning = false;
		}
		else if (btnNo->getClic())
		{
			imgWarning->setEnabled(false);
			lblWarning->setEnabled(false);
			btnYes->setEnabled(false);
			btnNo->setEnabled(false);
			warning = false;
		}
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
