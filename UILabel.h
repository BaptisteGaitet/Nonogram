#ifndef UI_LABEL_H
#define UI_LABEL_H

#include "UIElement.h"
#include "FontManager.h"

class UILabel :
	public UIElement
{
private:
	sf::Text text;
	void snapTextToShape();
	bool enabled;

	int getLinesNumber();
public:
	UILabel(std::string _id, sf::Vector2f position, float characterSize, int _drawOrder, std::string _content);

	void update();
	void draw(sf::RenderWindow* window);
	void setString(std::string _str);
	std::string getString();
	bool getEnabled();
	void setEnabled(bool _val);
	void setTextColor(sf::Color _color);
	sf::FloatRect getTextBounds();
	sf::Vector2f getCharacterPos(int _index);
	float getWidth();

	~UILabel();
};

#endif