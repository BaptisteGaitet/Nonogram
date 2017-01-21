#ifndef UI_BUTTON_H
#define UI_BUTTON_H

#include "UIElement.h"
#include <SFML/Graphics.hpp>
#include "MouseManager.h"
#include "TextureManager.h"

class UIButton :
	public UIElement
{
private:
	enum ButtonState { idle, hovered, pressed };
	ButtonState state;
	bool clic;
	bool enabled;
public:
	UIButton(std::string _id, sf::IntRect _bounds, int _drawOrder, std::string _path);

	void update();
	void draw(sf::RenderWindow* window);
	bool getClic();
	void setEnabled(bool _val);
	bool getEnabled();

	~UIButton();
};

#endif