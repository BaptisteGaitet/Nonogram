#ifndef UI_LEVEL_BUTTON_H
#define UI_LEVEL_BUTTON_H

#include "UIElement.h"
#include "TextureManager.h"
#include "FontManager.h"
#include "MouseManager.h"

class UILevelButton :
	public UIElement
{
private:
	enum ButtonState{ idle, hovered, pressed };
	sf::Text text;
	sf::RectangleShape medalShape;
	int levelNumber;
	bool selected;
	bool beaten;
public:
	UILevelButton(std::string _id, sf::IntRect _bounds, int _drawOrder);

	void update();
	void draw(sf::RenderWindow* window);
	void setLevelNumber(int _number);

	~UILevelButton();
};

#endif