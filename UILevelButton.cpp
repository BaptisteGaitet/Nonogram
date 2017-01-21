#include "UILevelButton.h"

UILevelButton::UILevelButton(std::string _id, sf::IntRect _bounds, int _drawOrder) : UIElement(_id, _bounds, _drawOrder)
{
	levelNumber = 0;

	TextureManager::getInstance().addTexture("btnLevel.png");
	shape.setTexture(TextureManager::getInstance().getTexture("btnLevel.png"));
	shape.setTextureRect(sf::IntRect(0, 0, 32,32));

	FontManager::getInstance().addFont("shty.ttf");
	text.setFont(*FontManager::getInstance().getFont("shty.ttf"));
	text.setString(std::to_string(levelNumber));
	text.setColor(sf::Color(50, 50, 50));
	text.setCharacterSize(40);
}

void UILevelButton::update()
{

}

void UILevelButton::draw(sf::RenderWindow* window)
{
	snapToDisplayArea();
	text.setPosition(shape.getPosition().x + 10, shape.getPosition().y - 4);

	window->draw(shape);
	window->draw(text);
}

void UILevelButton::setLevelNumber(int _number)
{
	levelNumber = _number;
	text.setString(std::to_string(levelNumber));
}

UILevelButton::~UILevelButton()
{
}
