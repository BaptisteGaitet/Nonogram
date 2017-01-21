#ifndef UI_IMAGE_H
#define UI_IMAGE_H

#include "UIElement.h"
#include <iostream>
#include <SFML\Graphics.hpp>
#include "TextureManager.h"

class UIImage :
	public UIElement
{
private:
	bool enabled;
public:
	UIImage(std::string _id, sf::IntRect _bounds, int _drawOrder, std::string _path);

	void update();
	void draw(sf::RenderWindow* window);
	bool getEnabled();
	void setEnabled(bool _val);

	~UIImage();
};

#endif