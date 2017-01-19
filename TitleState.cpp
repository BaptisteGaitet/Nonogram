#include "TitleState.h"

// Calls State constructor and initialize id as "title"
TitleState::TitleState() : State("title")
{
}

// Updates the state
void TitleState::update()
{

}

// Draws the state
void TitleState::draw(sf::RenderWindow* window)
{
	// Temp rect fill for debug purpose
	sf::RectangleShape tmp = sf::RectangleShape(sf::Vector2f(800, 600));
	tmp.setFillColor(sf::Color(100, 200, 100));
	window->draw(tmp);
}

TitleState::~TitleState()
{
}
