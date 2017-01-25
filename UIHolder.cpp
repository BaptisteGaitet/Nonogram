#include "UIHolder.h"

UIHolder::UIHolder()
{
	drawingQueue = std::vector<UIElement*>();
	elements = std::map<std::string, UIElement*>();
}

void UIHolder::update()
{
	for (std::map<std::string, UIElement*>::iterator it = elements.begin(); it != elements.end(); ++it)
	{
		it->second->update();
	}
}

void UIHolder::draw(sf::RenderWindow* window)
{
	for (int i = 0; i < drawingQueue.size(); i++)
	{
		drawingQueue.at(i)->draw(window);
	}
}

void UIHolder::addUIElement(UIElement* _uielement)
{
	elements.insert(std::pair<std::string, UIElement*>(_uielement->getId(), _uielement));
	drawingQueue.push_back(_uielement);
	sortDrawOrderVector();
}

void UIHolder::deleteUIElement(std::string _id)
{
	UIElement* element;
	if (hasUIElement(_id))
	{
		element = getUIElement(_id);
		elements.erase(_id);
		for (int i = 0; i < drawingQueue.size(); i++)
		{
			if (drawingQueue.at(i) == element)
			{
				drawingQueue.erase(drawingQueue.begin() + i);
			}
		}
		delete element;
	}
}

UIElement* UIHolder::getUIElement(std::string _id)
{
	UIElement* res = nullptr;

	if (hasUIElement(_id))
	{
		res = elements.at(_id);
	}

	return res;
}

bool UIHolder::hasUIElement(std::string _id)
{
	// Declare return value as true;
	bool valid = true;

	// Try to access the corresponding UIElement
	try
	{
		elements.at(_id);
	}
	catch (const std::out_of_range& oor)
	{
		// Set return value to false
		valid = false;
		// Log the error
		std::cerr << "UIHolder Out of Range error: " << oor.what() << "\n";
	}

	return valid;
}

void UIHolder::sortDrawOrderVector()
{
	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		for (int i = 0; i < drawingQueue.size() - 1; i++)
		{
			if (drawingQueue.at(i)->getDrawOrder() > drawingQueue.at(i + 1)->getDrawOrder())
			{ 
				UIElement* tmp = drawingQueue.at(i);
				drawingQueue.at(i) = drawingQueue.at(i + 1);
				drawingQueue.at(i + 1) = tmp;
				sorted = false;
			}
		}
	}
}

UIHolder::~UIHolder()
{
}
