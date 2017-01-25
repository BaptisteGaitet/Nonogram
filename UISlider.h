#ifndef UI_SLIDER_H
#define UI_SLIDER_H

#include "UIElement.h"
#include "TextureManager.h"
#include "MouseManager.h"

class UISlider :
	public UIElement
{
private:
	sf::RectangleShape knobShape;
	int amount;
	int lastAmount;
	bool selected;
	bool changed;
public:
	UISlider(std::string _id, sf::IntRect _bounds, int _drawOrder);

	void update();
	void draw(sf::RenderWindow* window);
	int getAmount();
	void setAmount(int _amount);
	bool hasChanged();

	~UISlider();
};

#endif