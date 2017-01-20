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

void UIElement::setShapePixelSize(sf::Vector2i screensize)
{
	shape.setPosition(sf::Vector2f(screensize.x * (bounds.left / 100), screensize.y * (bounds.top / 100)));
	shape.setSize(sf::Vector2f(screensize.x * (bounds.width / 100), screensize.y * (bounds.height / 100)));
}

UIElement::~UIElement()
{
}
