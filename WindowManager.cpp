#include "WindowManager.h"


WindowManager::WindowManager()
{
	requestExit = false;
}

WindowManager& WindowManager::getInstance()
{
	static WindowManager instance;

	return instance;
}

void WindowManager::updateDisplayArea(sf::Vector2u screensize)
{
	screenSize = screensize;
	if (screensize.x > screensize.y)
	{
		stretchRatio = (float)((float)screensize.y / (float)BASE_SCREEN_SIZE.y);
		displayArea.width = BASE_SCREEN_SIZE.x * stretchRatio;
		displayArea.height = BASE_SCREEN_SIZE.y * stretchRatio;
		displayArea.left = (float)(screensize.x - displayArea.width) / 2;
		displayArea.top = 0;
	}
	else
	{
		stretchRatio = (float)screensize.x / (float)BASE_SCREEN_SIZE.x;

		displayArea.width = BASE_SCREEN_SIZE.x * stretchRatio;
		displayArea.height = BASE_SCREEN_SIZE.y * stretchRatio;
		displayArea.left = 0;
		displayArea.top = (float)(screensize.y - displayArea.height) / 2;
	}
	
}

float WindowManager::getStretchRatio()
{
	return stretchRatio;
}

sf::IntRect WindowManager::getDisplayArea()
{
	return displayArea;
}

sf::Vector2u WindowManager::getScreenSize()
{
	return screenSize;
}

void WindowManager::setRequestExit(bool _value)
{
	requestExit = _value;
}

bool WindowManager::getRequestExit()
{
	return requestExit;
}

WindowManager::~WindowManager()
{
}
