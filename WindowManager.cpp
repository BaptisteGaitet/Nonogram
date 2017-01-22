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

void WindowManager::initialize(sf::Window* _window)
{
	window = _window;
	videoModes = sf::VideoMode::getFullscreenModes();
	window->setFramerateLimit(60);
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

void WindowManager::setFullscreen(bool _val)
{
	if (_val && !fullscreen)
	{
		sf::Vector2u size = sf::Vector2u(videoModes.at(0).width, videoModes.at(0).height);
		updateDisplayArea(size);
		window->create(videoModes.at(0), "Picr-Os", sf::Style::Fullscreen);
		window->setFramerateLimit(60);
		fullscreen = true;
		window->setMouseCursorVisible(false);
	}
	else if (!_val && fullscreen)
	{
		window->create(sf::VideoMode(800, 600), "Picr-Os");
		updateDisplayArea(sf::Vector2u(800,600));
		window->setFramerateLimit(60);
		fullscreen = false;
		window->setMouseCursorVisible(false);
	}
}

bool WindowManager::getFullscreen()
{
	return fullscreen;
}

WindowManager::~WindowManager()
{
}
