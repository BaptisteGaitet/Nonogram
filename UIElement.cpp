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

UIElement::~UIElement()
{
}
