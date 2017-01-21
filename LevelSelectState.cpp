#include "LevelSelectState.h"


LevelSelectState::LevelSelectState() : State("levelselect")
{
	selectedLevel = 0;

	// TEST //
	sf::Vector2i btnOffset = sf::Vector2i(120, 100);
	sf::Vector2i btnSpace = sf::Vector2i(20, 20);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::string btnName = "btnLevel" + std::to_string(j * 3 + i);
			std::string lblName = "lblLevel" + std::to_string(j * 3 + i);

			UIButton* btnLevel = new UIButton(btnName, sf::IntRect((i * (64 + btnSpace.x)) + btnOffset.x, (j * (64 + btnSpace.y)) + btnOffset.y, 64, 64), 2, "btnLevel.png");
			UILabel* lblLevel = new UILabel(lblName, sf::IntRect((i * (64 + btnSpace.x)) + btnOffset.x + 10, (j * (64 + btnSpace.y)) + btnOffset.y - 6, 64, 40), 3, std::to_string(j * 3 + i + 1));
			lblLevel->setTextColor(sf::Color(50, 50, 50));

			uiholder.addUIElement(btnLevel);
			uiholder.addUIElement(lblLevel);
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

	UIImage* imgSketch = new UIImage("img_sketch", sf::IntRect(400, 60, 300, 300), 2, "unknownSketch.png");
	uiholder.addUIElement(imgSketch);
	UILabel* lblDescription = new UILabel("lbl_description", sf::IntRect(420, 360, 100, 24), 2, "Unknown.");
	uiholder.addUIElement(lblDescription);
	UIButton* btnSolve = new UIButton("btn_solve", sf::IntRect(550, 500, 128, 64), 2, "btnSolve.png");
	uiholder.addUIElement(btnSolve);
	//////////
}

void LevelSelectState::update()
{
	uiholder.update();

	UIButton* btnBack = (UIButton*)uiholder.getUIElement("btn_back");
	if (btnBack->getClic())
	{
		setNextStateId("title");
	}
}

void LevelSelectState::draw(sf::RenderWindow* window)
{
	uiholder.draw(window);
}

void LevelSelectState::updateLevelButtons()
{

}

LevelSelectState::~LevelSelectState()
{
}
