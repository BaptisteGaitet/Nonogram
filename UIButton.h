#ifndef UI_BUTTON_H
#define UI_BUTTON_H

#include "UIElement.h"
#include <SFML/Graphics.hpp>
#include "MouseManager.h"
#include "TextureManager.h"

enum ButtonState {idle, hovered, pressed};

class UIButton :
	public UIElement
{
private:
	ButtonState state;
	bool clic;
public:
	UIButton(std::string _id, sf::IntRect _bounds, int _drawOrder, std::string _path);

	void update();
	void draw(sf::RenderWindow* window);
	bool getClic();

	~UIButton();
};

#endif