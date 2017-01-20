#ifndef UI_BACKGROUND_H
#define UI_BACKGROUND_H

#include "UIElement.h"
#include <iostream>
#include "TextureManager.h"

class UIBackground : public UIElement
{
private:
	sf::RectangleShape shape;
public:
	UIBackground(std::string _id, int _drawOrder);

	void update();
	void draw(sf::RenderWindow* window);

	~UIBackground();
};

#endif