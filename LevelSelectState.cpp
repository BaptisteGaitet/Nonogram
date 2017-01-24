#include "LevelSelectState.h"


LevelSelectState::LevelSelectState() : State("levelselect")
{
	selectedLevel = 0;
	currentPage = 0;

	// TEST //
	sf::Vector2i buttonMargin = sf::Vector2i(120, 120);
	sf::Vector2i buttonOffset = sf::Vector2i(16, 16);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::string name = "lvlButton" + std::to_string(j * 3 + i);
			UILevelButton* lvlButton = new UILevelButton(name, sf::IntRect((i * (64 + buttonOffset.x)) + buttonMargin.x, (j * (64 + buttonOffset.y)) + buttonMargin.y, 64, 64), 3);
			lvlButton->setLevelNumber(j * 3 + i);
			if (j * 3 + i == 0)
			{
				lvlButton->setSelected(true);
			}
			uiholder.addUIElement(lvlButton);
		}
	}

	UIBackground* bg = new UIBackground("background", 0, "bg1.png");
	uiholder.addUIElement(bg);
	UIImage* img = new UIImage("image", sf::IntRect(0, 0, 800, 600), 1, "book.png");
	uiholder.addUIElement(img);
	UIButton* btnBack = new UIButton("btn_back", sf::IntRect(100, 500, 64, 64), 2, "btn4.png");
	uiholder.addUIElement(btnBack);
	UIButton* btnLeft = new UIButton("btn_left", sf::IntRect(150, 400, 64, 64), 2, "btnArrowLeft.png");
	uiholder.addUIElement(btnLeft);
	UIButton* btnRight = new UIButton("btn_right", sf::IntRect(250, 400, 64, 64), 2, "btnArrowRight.png");
	uiholder.addUIElement(btnRight);

	UIImage* imgFrame= new UIImage("img_frame", sf::IntRect(400, 60, 300, 300), 3, "sketchFrame.png");
	uiholder.addUIElement(imgFrame);
	UIImage* imgSketch = new UIImage("img_sketch", sf::IntRect(400, 60, 300, 300), 2, "unknownSketch.png");
	uiholder.addUIElement(imgSketch);
	UILabel* lblDescription = new UILabel("lbl_description", sf::Vector2f(420, 360), 24, 2, "Unknown.");
	uiholder.addUIElement(lblDescription);
	UIButton* btnSolve = new UIButton("btn_solve", sf::IntRect(550, 500, 128, 64), 2, "btnSolve.png");
	uiholder.addUIElement(btnSolve);
	//////////

	updateLevelInfo();
	updateLevelButtons();
}

void LevelSelectState::update()
{
	uiholder.update();

	UIButton* btnBack = (UIButton*)uiholder.getUIElement("btn_back");
	if (btnBack->getClic())
	{
		setNextStateId("title");
	}

	UIButton* btnSolve = (UIButton*)uiholder.getUIElement("btn_solve");
	if (btnSolve->getClic())
	{
		setNextStateId("game");
	}

	for (int i = 0; i < 9; i++)
	{
		std::string btnId = "lvlButton" + std::to_string(i);
		UILevelButton* btn = (UILevelButton*)uiholder.getUIElement(btnId);
		if (btn->getClic())
		{
			selectedLevel = btn->getLevelNumber();
			LevelManager::getInstance().setSelectedLevel(btn->getLevelNumber());
			btn->setSelected(true);
			updateLevelInfo();
		}
		else if (btn->getLevelNumber() != selectedLevel)
		{
			btn->setSelected(false);
		}
	}

	UIButton* btnLeft = (UIButton*)uiholder.getUIElement("btn_left");
	UIButton* btnRight = (UIButton*)uiholder.getUIElement("btn_right");
	if (btnLeft->getClic())
	{
		currentPage--;
		updateLevelButtons();
		std::cout << currentPage << "\n";
	}
	if (btnRight->getClic())
	{
		currentPage++;
		updateLevelButtons();
		std::cout << currentPage << "\n";
	}
}

void LevelSelectState::draw(sf::RenderWindow* window)
{
	uiholder.draw(window);
}

void LevelSelectState::updateLevelInfo()
{
	if (LevelManager::getInstance().getLevel(selectedLevel)->getBeaten())
	{
		UIImage* img = (UIImage*)uiholder.getUIElement("img_sketch");
		img->changeImage(LevelManager::getInstance().getLevel(selectedLevel)->getImagePath());
		UILabel* lbl = (UILabel*)uiholder.getUIElement("lbl_description");
		lbl->setString(LevelManager::getInstance().getLevel(selectedLevel)->getDescription());
	}
	else
	{
		UIImage* img = (UIImage*)uiholder.getUIElement("img_sketch");
		img->changeImage("unknownSketch.png");
		UILabel* lbl = (UILabel*)uiholder.getUIElement("lbl_description");
		lbl->setString("Unknown.");
	}
}

void LevelSelectState::updateLevelButtons()
{
	UIButton* btnLeft = (UIButton*)uiholder.getUIElement("btn_left");
	UIButton* btnRight = (UIButton*)uiholder.getUIElement("btn_right");
	btnLeft->setEnabled(true);
	btnRight->setEnabled(true);
	if (currentPage == 0)
	{
		btnLeft->setEnabled(false);
	}
	if (!LevelManager::getInstance().hasLevel((currentPage + 1) * LEVELS_PER_PAGE))
	{
		btnRight->setEnabled(false);
	}

	for (int i = 0; i < 9; i++)
	{
		std::string btnId = "lvlButton" + std::to_string(i);
		UILevelButton* btn = (UILevelButton*)uiholder.getUIElement(btnId);
		btn->setLevelNumber(currentPage * LEVELS_PER_PAGE + i);
		if (!LevelManager::getInstance().hasLevel(btn->getLevelNumber()))
		{
			btn->setEnabled(false);
		}
		else
		{
			btn->setEnabled(true);
		}
	}
}

LevelSelectState::~LevelSelectState()
{
}
