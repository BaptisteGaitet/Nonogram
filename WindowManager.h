#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <SFML\Graphics.hpp>
#include <iostream>

const sf::Vector2i BASE_SCREEN_SIZE = sf::Vector2i(800,600);

class WindowManager
{
private:
	WindowManager();
	WindowManager(WindowManager const&);
	void operator=(WindowManager const&);

	sf::IntRect displayArea;
	float stretchRatio;
	sf::Vector2u screenSize;
	bool requestExit;
public:
	static WindowManager& getInstance();

	void updateDisplayArea(sf::Vector2u screenSize);
	sf::Vector2u getScreenSize();
	float getStretchRatio();
	sf::IntRect getDisplayArea();
	void setRequestExit(bool _value);
	bool getRequestExit();

	~WindowManager();
};

#endif