#ifndef UI_BUTTON_H
#define UI_BUTTON_H

#include "UIElement.h"
#include <SFML/Graphics.hpp>

class UIButton :
	public UIElement
{
public:
	UIButton(std::string _id, sf::IntRect _bounds, int _drawOrder, std::string _path);

	void update();
	void draw(sf::RenderWindow* window);

	~UIButton();
};

#endif