#include "MouseManager.h"


MouseManager::MouseManager()
{
	currentLeftDown = false;
	lastLeftDown = false;
	currentRightDown = false;
	lastRightDown = false;
	window = nullptr;
}

MouseManager& MouseManager::getInstance()
{
	static MouseManager instance;

	return instance;
}

void MouseManager::setWindow(sf::Window* _window)
{
	window = _window;
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
	bool res = ((currentLeftDown == true) && (lastLeftDown == false));
	//if (res)
		//std::cout << "leftPush\n";
	return res;
}

bool MouseManager::rightPush()
{
	bool res = ((currentRightDown == true) && (lastRightDown == false));
	//if (res)
		//std::cout << "rightPush\n";
	return res;
}

bool MouseManager::leftRelease()
{

	bool res = ((currentLeftDown == false) && (lastLeftDown == true));
	//if (res)
		//std::cout << "leftRelease\n";
	return res;
}

bool MouseManager::rightRelease()
{
	bool res = ((currentRightDown == false) && (lastRightDown == true));
	//if (res)
		//std::cout << "rightRelease\n";
	return res;
}

sf::Vector2i MouseManager::getPosition()
{
	return sf::Mouse::getPosition(*window);
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
