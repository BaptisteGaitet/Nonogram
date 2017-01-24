#include "UIElement.h"


UIElement::UIElement(std::string _id, sf::IntRect _bounds, int _drawOrder)
{
	id = _id;
	bounds = _bounds;
	drawOrder = _drawOrder;
}

std::string UIElement::getId()
{
	return id;
}

int UIElement::getDrawOrder()
{
	return drawOrder;
}

void UIElement::snapToDisplayArea()
{
	sf::Vector2f newPosition;
	sf::Vector2f newSize;
	sf::IntRect displayArea = WindowManager::getInstance().getDisplayArea();
	float stretchRatio = WindowManager::getInstance().getStretchRatio();

	newPosition.x = (bounds.left * stretchRatio) + displayArea.left;
	newPosition.y = (bounds.top * stretchRatio) + displayArea.top;
	newSize.x = bounds.width * stretchRatio;
	newSize.y = bounds.height * stretchRatio;

	shape.setPosition(newPosition);
	shape.setSize(newSize);
}

void UIElement::setPosition(sf::Vector2f _position)
{
	bounds.left = _position.x;
	bounds.top = _position.y;
}

sf::Vector2f UIElement::getPosition()
{
	sf::Vector2f res;
	res.x = bounds.left;
	res.y = bounds.top;
	return res;
}

void UIElement::setSize(sf::Vector2f _size)
{
	bounds.width = _size.x;
	bounds.height = _size.y;
}

sf::Vector2f UIElement::getSize()
{
	sf::Vector2f res;
	res.x = bounds.width;
	res.y = bounds.height;
	return res;
}

UIElement::~UIElement()
{
}
