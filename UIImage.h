#ifndef UI_IMAGE_H
#define UI_IMAGE_H

#include "UIElement.h"
#include <SFML\Graphics.hpp>

class UIImage :
	public UIElement
{
public:
	UIImage(std::string _id, sf::IntRect _bounds, int _drawOrder);

	void update();
	void draw(sf::RenderWindow* window);

	~UIImage();
};

#endif