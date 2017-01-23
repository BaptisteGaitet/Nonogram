#ifndef UI_HOLDER
#define UI_HOLDER

#include <SFML\Graphics.hpp>
#include "UIElement.h"
#include <map>
#include <string>
#include <iostream>

class UIHolder
{
private:
	std::vector<UIElement*> drawingQueue;
	std::map<std::string, UIElement*> elements;
public:
	UIHolder();

	void draw(sf::RenderWindow* window);
	void update();
	void addUIElement(UIElement* _uielement);
	void deleteUIElement(std::string _id);
	UIElement* getUIElement(std::string _id);
	bool hasUIElement(std::string _id);
	void sortDrawOrderVector();

	~UIHolder();
};

#endif