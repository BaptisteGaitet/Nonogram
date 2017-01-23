#include "UINonogramCell.h"


UINonogramCell::UINonogramCell(std::string _id, sf::IntRect _bounds, int _drawOrder) : UIElement(_id, _bounds, _drawOrder)
{
	state = grassIdle;
	mistake = false;
	filled = false;
	TextureManager::getInstance().addTexture("cell.png");
	shape.setTexture(TextureManager::getInstance().getTexture("cell.png"));
	shape.setTextureRect(sf::IntRect(0, 0, TextureManager::getInstance().getTexture("cell.png")->getSize().x / 9, TextureManager::getInstance().getTexture("cell.png")->getSize().y));
}

void UINonogramCell::update()
{
	sf::IntRect rectPos = sf::IntRect(shape.getPosition().x, shape.getPosition().y, shape.getSize().x, shape.getSize().y);
	if (state == grassIdle)
	{
		if (MouseManager::getInstance().isOver(rectPos))
		{
			state = grassHovered;
		}
	}
	else if (state == grassHovered)
	{
		if (!MouseManager::getInstance().isOver(rectPos))
		{
			state = grassIdle;
		}
		if (MouseManager::getInstance().leftPush() || MouseManager::getInstance().rightPush())
		{
			state = grassPressed;
		}
	}
	else if (state == grassPressed)
	{
		if (!MouseManager::getInstance().isOver(rectPos))
		{
			state = grassIdle;
		}
		if (MouseManager::getInstance().leftRelease())
		{
			if (!filled)
			{
				mistake = true;
				state = flaggedIdle;
			}
			else
			{
				state = ground;
			}
		}
		if (MouseManager::getInstance().rightRelease())
		{
			state = flaggedIdle;
		}
	}
	else if (state == flaggedIdle)
	{
		if (MouseManager::getInstance().isOver(rectPos))
		{
			state = flaggedHovered;
		}
	}
	else if (state == flaggedHovered)
	{
		if (!MouseManager::getInstance().isOver(rectPos))
		{
			state = flaggedIdle;
		}
		if (MouseManager::getInstance().leftPush() || MouseManager::getInstance().rightPush())
		{
			state = flaggedPressed;
		}
	}
	else if (state == flaggedPressed)
	{
		if (!MouseManager::getInstance().isOver(rectPos))
		{
			state = flaggedIdle;
		}
		if (MouseManager::getInstance().leftRelease())
		{
			if (!filled)
			{
				mistake = true;
				state = flaggedIdle;
			}
			else
			{
				state = ground;
			}
		}
		if (MouseManager::getInstance().rightRelease())
		{
			state = grassIdle;
		}
	}

	sf::IntRect rectTex = shape.getTextureRect();
	if (state == grassIdle)
	{
		shape.setTextureRect(sf::IntRect(0, 0, rectTex.width, rectTex.height));
	}
	else if (state == grassHovered)
	{
		shape.setTextureRect(sf::IntRect(rectTex.width, 0, rectTex.width, rectTex.height));
	}
	else if (state == grassPressed)
	{
		shape.setTextureRect(sf::IntRect(rectTex.width * 2, 0, rectTex.width, rectTex.height));
	}
	else if (state == flaggedIdle)
	{
		shape.setTextureRect(sf::IntRect(rectTex.width * 3, 0, rectTex.width, rectTex.height));
	}
	else if (state == flaggedHovered)
	{
		shape.setTextureRect(sf::IntRect(rectTex.width * 4, 0, rectTex.width, rectTex.height));
	}
	else if (state == flaggedPressed)
	{
		shape.setTextureRect(sf::IntRect(rectTex.width * 5, 0, rectTex.width, rectTex.height));
	}
	else if (state == ground)
	{
		shape.setTextureRect(sf::IntRect(rectTex.width * 6, 0, rectTex.width, rectTex.height));
	}
}

void UINonogramCell::draw(sf::RenderWindow* window)
{
	snapToDisplayArea();
	window->draw(shape);
}

void UINonogramCell::setFilled(bool _filled)
{
	filled = _filled;
}

bool UINonogramCell::getMistake()
{
	bool res = mistake;
	mistake = false;
	return res;
}

UINonogramCell::~UINonogramCell()
{
}
