#include "UIBackground.h"

UIBackground::UIBackground(std::string _id, int _drawOrder) : UIElement(_id, sf::IntRect(0,0,100,100), _drawOrder)
{
	// TEST //
	TextureManager::getInstance().addTexture("bg2.png");
	TextureManager::getInstance().setRepeated("bg2.png", true);
	shape.setTexture(TextureManager::getInstance().getTexture("bg2.png"));
	shape.setTextureRect(sf::IntRect(0, 0, 400, 300));
	//////////
}

void UIBackground::update()
{
	// TEST //
	sf::IntRect tmp = shape.getTextureRect();
	tmp.left-=1;
	tmp.top-=1;
	shape.setTextureRect(tmp);
	//////////
}

void UIBackground::draw(sf::RenderWindow* window)
{
	sf::Vector2i screensize = sf::Vector2i(window->getSize().x, window->getSize().y);
	setShapePixelSize(screensize);

	window->draw(shape);
}

UIBackground::~UIBackground()
{
}
