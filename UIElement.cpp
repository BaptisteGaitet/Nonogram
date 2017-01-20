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

UIElement::~UIElement()
{
}
