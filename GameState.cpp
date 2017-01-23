#include "GameState.h"

GameState::GameState() : State("game")
{
	timer = 108000;
	currentLevel = 0;
	level = LevelManager::getInstance().getLevel(0);
	initCells();

	UIBackground* bg = new UIBackground("background", 0, "bg2.png");
	uiholder.addUIElement(bg);
	UIImage* imgTimer = new UIImage("img_timer", sf::IntRect(10, 10, 256, 128), 1, "timerFrame.png");
	uiholder.addUIElement(imgTimer);
	UIImage* imgBack = new UIImage("img_back", sf::IntRect(10, 500, 128, 128), 1, "backButtonFrame.png");
	uiholder.addUIElement(imgBack);
	UILabel* lblTimer = new UILabel("lbl_timer", sf::IntRect(20, 20, 100, 50), 2, "29:29");
	uiholder.addUIElement(lblTimer);
	UIButton* btnBack = new UIButton("btn_back", sf::IntRect(40, 520, 64, 64), 2, "btn4.png");
	uiholder.addUIElement(btnBack);

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
}

void GameState::update()
{
	uiholder.update();

	if (!warning)
	{
		UIButton* btnBack = (UIButton*)uiholder.getUIElement("btn_back");

		UIImage* imgWarning = (UIImage*)uiholder.getUIElement("img_warning");
		UILabel* lblWarning = (UILabel*)uiholder.getUIElement("lbl_warning");
		UIButton* btnYes = (UIButton*)uiholder.getUIElement("btn_yes");
		UIButton* btnNo = (UIButton*)uiholder.getUIElement("btn_no");
		if (btnBack->getClic())
		{
			warning = true;

			imgWarning->setEnabled(true);
			lblWarning->setEnabled(true);
			btnYes->setEnabled(true);
			btnNo->setEnabled(true);
		}

		if (LevelManager::getInstance().getSelectedLevel() != currentLevel)
		{
			currentLevel = LevelManager::getInstance().getSelectedLevel();
			setLevel(LevelManager::getInstance().getLevel(currentLevel));
		}

		for (int i = 0; i < level->getNonogram()->getWidth(); i++)
		{
			for (int j = 0; j < level->getNonogram()->getHeight(); j++)
			{
				std::string name = "cell" + std::to_string(i * level->getNonogram()->getWidth() + j);
				UINonogramCell* cell = (UINonogramCell*)uiholder.getUIElement(name);
				if (cell->getMistake())
				{
					WindowManager::getInstance().screenShake(10);
					timer /= 2;
				}
			}
		}

		UILabel* lblTimer = (UILabel*)uiholder.getUIElement("lbl_timer");
		std::string minutes = std::to_string(timer / 3600);
		std::string seconds = std::to_string(timer % 3600 / 60);
		if (minutes.size() < 2)
			minutes = "0" + minutes;
		else if (minutes.size() < 1)
			minutes = "00";
		if (seconds.size()<2)
			seconds = "0" + seconds;
		else if (seconds.size() < 1)
			seconds = "00";
		lblTimer->setString(minutes + " : " + seconds);
		timer--;
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
			setNextStateId("levelselect");
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

void GameState::draw(sf::RenderWindow* window)
{
	uiholder.draw(window);
}

void GameState::setLevel(Level* _level)
{
	deleteCells();
	level = _level;
	initCells();
}

void GameState::initCells()
{
	sf::Vector2i cellsMargin = sf::Vector2i(0, 0);
	cellsMargin.x = 400 - ((32 * level->getNonogram()->getWidth()) / 2);
	cellsMargin.y = 300 - ((32 * level->getNonogram()->getHeight()) / 2);
	for (int i = 0; i < level->getNonogram()->getWidth(); i++)
	{
		for (int j = 0; j < level->getNonogram()->getHeight(); j++)
		{
			std::string name = "cell" + std::to_string(i * level->getNonogram()->getWidth() + j);
			UINonogramCell* cell = new UINonogramCell(name, sf::IntRect(j* 32 + cellsMargin.x, i * 32 + cellsMargin.y, 32, 32), 2);
			if (level->getNonogram()->getCell(i, j))
			{
				cell->setFilled(true);
			}
			uiholder.addUIElement(cell);
		}
	}
}

void GameState::deleteCells()
{
	for (int i = 0; i < level->getNonogram()->getWidth(); i++)
	{
		for (int j = 0; j < level->getNonogram()->getHeight(); j++)
		{
			std::string name = "cell" + std::to_string(i * level->getNonogram()->getWidth() + j);
			uiholder.deleteUIElement(name);
		}
	}
}

GameState::~GameState()
{
}
