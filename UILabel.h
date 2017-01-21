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
public:
	UILabel(std::string _id, sf::IntRect _bounds, int _drawOrder, std::string _content);

	void update();
	void draw(sf::RenderWindow* window);
	void setString(std::string _str);
	std::string getString();
	bool getEnabled();
	void setEnabled(bool _val);

	~UILabel();
};

#endif