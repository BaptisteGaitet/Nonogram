#include "MouseManager.h"


MouseManager::MouseManager()
{
}

MouseManager& MouseManager::getInstance()
{
	static MouseManager instance;

	return instance;
}

void MouseManager::update()
{
	lastLeftDown = currentLeftDown;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		currentLeftDown = true;
	}
	else
	{
		currentLeftDown = false;
	}

	lastRightDown = currentRightDown;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		currentRightDown = true;
	}
	else
	{
		currentRightDown = false;
	}
}

bool MouseManager::isLeftDown()
{
	return currentLeftDown;
}

bool MouseManager::isRightDown()
{
	return currentRightDown;
}

bool MouseManager::leftPush()
{
	return (currentLeftDown && !lastLeftDown);
}

bool MouseManager::rightPush()
{
	return (currentRightDown && !lastRightDown);
}

bool MouseManager::leftRelease()
{
	return (!currentLeftDown && lastLeftDown);
}

bool MouseManager::rightRelease()
{
	return (!currentRightDown && lastRightDown);
}

sf::Vector2i MouseManager::getPosition()
{
	return sf::Mouse::getPosition();
}

bool MouseManager::isOver(sf::IntRect _rect)
{
	bool res = false;

	if (getPosition().x >= _rect.left && getPosition().x <= _rect.left + _rect.width && getPosition().y >= _rect.top && getPosition().y <= _rect.top + _rect.height)
	{
		res = true;
	}

	return res;
}

MouseManager::~MouseManager()
{
}
