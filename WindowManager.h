#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <SFML\Graphics.hpp>
#include <iostream>

const sf::Vector2i BASE_SCREEN_SIZE = sf::Vector2i(800,600);

class WindowManager
{
private:
	const int SHAKE_INTENSITY = 4;

	WindowManager();
	WindowManager(WindowManager const&);
	void operator=(WindowManager const&);

	sf::Window* window;
	std::vector<sf::VideoMode> videoModes;
	sf::IntRect displayArea;
	float stretchRatio;
	sf::Vector2u screenSize;
	bool requestExit;
	bool fullscreen;
	int shakeTimer;

public:
	static WindowManager& getInstance();

	void initialize(sf::Window* _window);
	void update();
	void updateDisplayArea(sf::Vector2u screenSize, sf::Vector2i offset);
	sf::Vector2u getScreenSize();
	float getStretchRatio();
	sf::IntRect getDisplayArea();
	void setRequestExit(bool _value);
	bool getRequestExit();
	void setFullscreen(bool _val);
	bool getFullscreen();
	void screenShake(int _duration);

	~WindowManager();
};

#endif