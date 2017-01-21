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
