#include "GameState.h"

GameState::GameState() : State("game")
{
	timer = LEVEL_TIME;
	currentLevel = 0;
	level = LevelManager::getInstance().getLevel(0);
	initCells();

	UIBackground* bg = new UIBackground("background", 0, "bg2.png");
	uiholder.addUIElement(bg);
	UIImage* imgTablet = new UIImage("img_tablet", sf::IntRect(0, 0, 800, 600), 1, "tablet.png");
	uiholder.addUIElement(imgTablet);
	//UIImage* imgTimer = new UIImage("img_timer", sf::IntRect(10, 10, 256, 128), 1, "timerFrame.png");
	//uiholder.addUIElement(imgTimer);
	UIImage* imgBack = new UIImage("img_back", sf::IntRect(10, 500, 128, 128), 1, "backButtonFrame.png");
	uiholder.addUIElement(imgBack);
	UILabel* lblTimer = new UILabel("lbl_timer", sf::Vector2f(200, 150), 30, 2, "29:29");
	uiholder.addUIElement(lblTimer);
	UIButton* btnBack = new UIButton("btn_back", sf::IntRect(40, 520, 64, 64), 2, "btn4.png");
	uiholder.addUIElement(btnBack);

	UIImage* imgWarning = new UIImage("img_warning", sf::IntRect(250, 100, 300, 400), 3, "sheet.png");
	imgWarning->setEnabled(false);
	uiholder.addUIElement(imgWarning);
	UILabel* lblWarning = new UILabel("lbl_warning", sf::Vector2f(280, 200), 40, 4, "Are you sure ?");
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
	timer = LEVEL_TIME;

	sf::Vector2i cellsMargin = sf::Vector2i(0, 0);
	cellsMargin.x = 400 - ((CELL_SIZE * level->getNonogram()->getWidth()) / 2);
	cellsMargin.y = 300 - ((CELL_SIZE * level->getNonogram()->getHeight()) / 2);
	for (int i = 0; i < level->getNonogram()->getWidth(); i++)
	{
		for (int j = 0; j < level->getNonogram()->getHeight(); j++)
		{
			std::string name = "cell" + std::to_string(i * level->getNonogram()->getWidth() + j);
			UINonogramCell* cell = new UINonogramCell(name, sf::IntRect(j* CELL_SIZE + cellsMargin.x, i * CELL_SIZE + cellsMargin.y, CELL_SIZE, CELL_SIZE), 2);
			if (level->getNonogram()->getCell(i, j))
			{
				cell->setFilled(true);
			}
			uiholder.addUIElement(cell);
		}
	}

	for (int i = 0; i < level->getNonogram()->getWidth(); i++)
	{
		std::string name = "lbl_hint_hor_" + std::to_string(i);
		std::string content = level->getNonogram()->getRowHint(i);
		UILabel* lblHint = new UILabel(name, sf::Vector2f(cellsMargin.x - 8, (i * CELL_SIZE) + cellsMargin.y - 14), CELL_SIZE, 2, content);
		lblHint->setPosition(sf::Vector2f(lblHint->getPosition().x - lblHint->getTextBounds().width, lblHint->getPosition().y));
		uiholder.addUIElement(lblHint);
	}

	for (int i = 0; i < level->getNonogram()->getHeight(); i++)
	{
		std::string name = "lbl_hint_ver_" + std::to_string(i);
		std::string content = level->getNonogram()->getColumnHint(i);
		UILabel* lblHint = new UILabel(name, sf::Vector2f((i * CELL_SIZE) + cellsMargin.x + 6, cellsMargin.y - 24), CELL_SIZE, 2, content);
		lblHint->setPosition(sf::Vector2f(lblHint->getPosition().x, lblHint->getPosition().y - lblHint->getTextBounds().height));
		uiholder.addUIElement(lblHint);
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
	for (int i = 0; i < level->getNonogram()->getWidth(); i++)
	{
		std::string name = "lbl_hint_hor_" + std::to_string(i);
		uiholder.deleteUIElement(name);
	}
	for (int i = 0; i < level->getNonogram()->getHeight(); i++)
	{
		std::string name = "lbl_hint_ver_" + std::to_string(i);
		uiholder.deleteUIElement(name);
	}
}

GameState::~GameState()
{
}
