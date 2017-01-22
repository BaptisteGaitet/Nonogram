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
	ButtonState state;
	int levelNumber;
	bool selected;
	bool beaten;
	bool clic;
	bool enabled;
public:
	UILevelButton(std::string _id, sf::IntRect _bounds, int _drawOrder);

	void update();
	void draw(sf::RenderWindow* window);
	bool getClic();
	void setLevelNumber(int _number);
	int getLevelNumber();
	bool getEnabled();
	void setEnabled(bool _enabled);
	bool getSelected();
	void setSelected(bool _selected);

	~UILevelButton();
};

#endif