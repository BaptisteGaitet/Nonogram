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
	shape.setPosition(sf::Vector2f(screensize.x * ((float)bounds.left / 100), screensize.y * ((float)bounds.top / 100)));
	shape.setSize(sf::Vector2f(screensize.x * ((float)bounds.width / 100), screensize.y * ((float)bounds.height / 100)));

	//std::cout << shape.getPosition().x << ", " << shape.getPosition().y << "\n";
	//std::cout << shape.getSize().x << ", " << shape.getSize().y << "\n";
}

UIElement::~UIElement()
{
}
