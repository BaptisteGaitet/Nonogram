#include "UISlider.h"

UISlider::UISlider(std::string _id, sf::IntRect _bounds, int _drawOrder) : UIElement(_id, _bounds, _drawOrder)
{
	knobShape = sf::RectangleShape();
	TextureManager::getInstance().addTexture("slide.png");
	TextureManager::getInstance().addTexture("knob.png");
	shape.setTexture(TextureManager::getInstance().getTexture("slide.png"));
	knobShape.setTexture(TextureManager::getInstance().getTexture("knob.png"));
	selected = false;
	amount = 100;
	lastAmount = 100;
	changed = false;
}

void UISlider::update()
{
	lastAmount = amount;
	changed = false;

	sf::IntRect knobRect;
	knobRect.left = knobShape.getPosition().x;
	knobRect.top = knobShape.getPosition().y;
	knobRect.width = knobShape.getSize().x;
	knobRect.height = knobShape.getSize().y;

	if (MouseManager::getInstance().isOver(knobRect))
	{
		if (MouseManager::getInstance().isLeftDown())
		{
			selected = true;
		}
	}

	if (!MouseManager::getInstance().isLeftDown())
	{
		selected = false;
	}

	if (selected)
	{
		knobShape.setPosition(MouseManager::getInstance().getPosition().x - knobShape.getSize().x/2, knobShape.getPosition().y);
		if (knobShape.getPosition().x < shape.getPosition().x)
		{
			knobShape.setPosition(shape.getPosition().x - (knobShape.getSize().x / 2), knobShape.getPosition().y);
		}

		if (knobShape.getPosition().x > shape.getPosition().x + shape.getSize().x)
		{
			knobShape.setPosition(shape.getPosition().x + shape.getSize().x - (knobShape.getSize().x / 2), knobShape.getPosition().y);
		}
		amount = (knobShape.getPosition().x + (knobShape.getSize().x / 2)) - shape.getPosition().x;
		amount = floor((amount * 100) / shape.getSize().x);
	}
	else
	{
		knobShape.setPosition(shape.getPosition().x + ((float)((float)amount / 100) * shape.getSize().x - (knobShape.getSize().x/2)), shape.getPosition().y);
	}

	if (amount != lastAmount)
	{
		changed = true;
	}
}

void UISlider::draw(sf::RenderWindow* window)
{
	snapToDisplayArea();

	knobShape.setSize(sf::Vector2f(shape.getSize().y, shape.getSize().y));

	window->draw(shape);
	window->draw(knobShape);
}

void UISlider::setAmount(int _amount)
{
	amount = _amount;
}

int UISlider::getAmount()
{
	return amount;
}

bool UISlider::hasChanged()
{
	return changed;
}

UISlider::~UISlider()
{
}
