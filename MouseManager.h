#ifndef MOUSE_MANAGER_H
#define MOUSE_MANAGER_H

#include <SFML\Graphics.hpp>

class MouseManager
{
private:
	MouseManager();
	MouseManager(MouseManager const&);
	void operator=(MouseManager const&);

	bool currentLeftDown;
	bool lastLeftDown;
	bool currentRightDown;
	bool lastRightDown;
	sf::Window* window;

public:
	static MouseManager& getInstance();

	void setWindow(sf::Window* _window);
	void update();
	bool isLeftDown();
	bool isRightDown();
	bool leftPush();
	bool rightPush();
	bool leftRelease();
	bool rightRelease();
	sf::Vector2i getPosition();
	bool isOver(sf::IntRect _rect);

	~MouseManager();
};

#endif