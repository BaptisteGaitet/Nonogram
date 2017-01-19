#ifndef UI_ELEMENT_H
#define UI_ELEMENT_H

#include <string>
#include <SFML/Graphics.hpp>

class UIElement
{
private:
	std::string id;
	sf::IntRect bounds;
	int drawOrder;
public:
	UIElement(std::string _id, sf::IntRect _bounds, int _drawOrder);

	std::string getId();
	int getDrawOrder();

	virtual void update() = 0;
	virtual void draw(sf::RenderWindow* window) = 0;

	~UIElement();
};

#endif