#include "WindowManager.h"


WindowManager::WindowManager()
{
	requestExit = false;
	window = nullptr;
	videoModes = std::vector<sf::VideoMode>();
	displayArea = sf::IntRect();
	stretchRatio = 0;
	screenSize = sf::Vector2u();
	fullscreen = false;
	shakeTimer = 0;
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

void WindowManager::update()
{
	if (shakeTimer > 0 && shakeTimer % 2 == 0)
	{
		sf::Vector2i offset;
		int random = rand() % 4 + 1;
		switch (random)
		{
		case 1:
			offset.x += SHAKE_INTENSITY;
			break;
		case 2:
			offset.x -= SHAKE_INTENSITY;
			break;
		case 3:
			offset.y += SHAKE_INTENSITY;
			break;
		case 4:
			offset.y -= SHAKE_INTENSITY;
			break;
		}

		updateDisplayArea(screenSize, offset);
		shakeTimer--;
	}
	else if (shakeTimer > 0)
	{
		updateDisplayArea(screenSize, sf::Vector2i(0, 0));
		shakeTimer--;
	}
}

void WindowManager::updateDisplayArea(sf::Vector2u screensize, sf::Vector2i offset)
{
	screenSize = screensize;
	if (screensize.x > screensize.y)
	{
		stretchRatio = (float)((float)screensize.y / (float)BASE_SCREEN_SIZE.y);
		displayArea.width = BASE_SCREEN_SIZE.x * stretchRatio;
		displayArea.height = BASE_SCREEN_SIZE.y * stretchRatio;
		displayArea.left = (float)(screensize.x - displayArea.width) / 2 + offset.x;
		displayArea.top = 0 + offset.y;
	}
	else
	{
		stretchRatio = (float)screensize.x / (float)BASE_SCREEN_SIZE.x;

		displayArea.width = BASE_SCREEN_SIZE.x * stretchRatio;
		displayArea.height = BASE_SCREEN_SIZE.y * stretchRatio;
		displayArea.left = 0 + offset.x;
		displayArea.top = (float)(screensize.y - displayArea.height) / 2 + offset.y;
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
		updateDisplayArea(size, sf::Vector2i(0, 0));
		window->create(videoModes.at(0), "Archeo-Gram", sf::Style::Fullscreen);
		window->setFramerateLimit(60);
		fullscreen = true;
		window->setMouseCursorVisible(false);
	}
	else if (!_val && fullscreen)
	{
		window->create(sf::VideoMode(800, 600), "Archeo-Gram");
		updateDisplayArea(sf::Vector2u(800,600), sf::Vector2i(0,0));
		window->setFramerateLimit(60);
		fullscreen = false;
		window->setMouseCursorVisible(false);
	}
}

bool WindowManager::getFullscreen()
{
	return fullscreen;
}

void WindowManager::screenShake(int _duration)
{
	shakeTimer = _duration;
}

WindowManager::~WindowManager()
{
}
