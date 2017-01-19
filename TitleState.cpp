#include "TitleState.h"

// Calls State constructor and initialize id as "title"
TitleState::TitleState() : State("title")
{
	// TEST //
	UIBackground* bg = new UIBackground("background", 0);
	uiholder.addUIElement(bg);
	//////////
}

// Updates the state
void TitleState::update()
{
	uiholder.update();
}

// Draws the state
void TitleState::draw(sf::RenderWindow* window)
{
	uiholder.draw(window);
}

TitleState::~TitleState()
{
}
