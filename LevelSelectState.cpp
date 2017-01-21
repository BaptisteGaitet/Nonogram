#include "LevelSelectState.h"


LevelSelectState::LevelSelectState() : State("levelselect")
{
	// TEST //
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

LevelSelectState::~LevelSelectState()
{
}
