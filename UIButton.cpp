#include "UIButton.h"


UIButton::UIButton(std::string _id, sf::IntRect _bounds, int _drawOrder, std::string _path) : UIElement(_id, _bounds, _drawOrder)
{
	TextureManager::getInstance().addTexture(_path);
	shape.setTexture(TextureManager::getInstance().getTexture(_path));
	shape.setTextureRect(sf::IntRect(0, 0, TextureManager::getInstance().getTexture(_path)->getSize().x / 3, TextureManager::getInstance().getTexture(_path)->getSize().y));
	clic = false;
}

void UIButton::update()
{
	clic = false;
	sf::IntRect pixelBounds = sf::IntRect(shape.getPosition().x, shape.getPosition().y, shape.getSize().x, shape.getSize().y);

	if (MouseManager::getInstance().isOver(pixelBounds))
	{
		if (MouseManager::getInstance().isLeftDown())
		{
			state = pressed;
		}
		else if (state == pressed)
		{
			clic = true;
		}else
		{
			state = hovered;
		}
	}
	else 
	{
		state = idle;
	}

	sf::IntRect rect = shape.getTextureRect();
	if (state == idle)
	{
		shape.setTextureRect(sf::IntRect(0,0,rect.width,rect.height));
	}
	else if (state == hovered)
	{
		shape.setTextureRect(sf::IntRect(rect.width, 0, rect.width, rect.height));
	}
	else
	{
		shape.setTextureRect(sf::IntRect(rect.width*2, 0, rect.width, rect.height));
	}
}

void UIButton::draw(sf::RenderWindow* window)
{
	snapToDisplayArea();

	window->draw(shape);
}

bool UIButton::getClic()
{
	return clic;
}

UIButton::~UIButton()
{
}
