#ifndef UI_ELEMENT_H
#define UI_ELEMENT_H

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "WindowManager.h"

class UIElement
{
private:
	std::string id;
	int drawOrder;
protected:
	sf::IntRect bounds;
	sf::RectangleShape shape;

	void snapToDisplayArea();
public:
	UIElement(std::string _id, sf::IntRect _bounds, int _drawOrder);

	std::string getId();
	int getDrawOrder();

	virtual void update() = 0;
	virtual void draw(sf::RenderWindow* window) = 0;
	void setPosition(sf::Vector2f _position);
	sf::Vector2f getPosition();
	void setSize(sf::Vector2f _size);
	sf::Vector2f getSize();

	~UIElement();
};

#endif