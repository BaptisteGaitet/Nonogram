#include "UILabel.h"


UILabel::UILabel(std::string _id, sf::IntRect _bounds, int _drawOrder, std::string _content) : UIElement(_id, _bounds, _drawOrder)
{
	enabled = true;
	FontManager::getInstance().addFont("shty.ttf");
	text.setFont(*FontManager::getInstance().getFont("shty.ttf"));
	text.setString(_content);
	text.setColor(sf::Color(50,50,50));
}

void UILabel::update()
{

}

void UILabel::draw(sf::RenderWindow* window)
{
	if (enabled)
	{
		snapToDisplayArea();
		snapTextToShape();
		window->draw(text);
	}
}

void UILabel::snapTextToShape()
{
	text.setPosition(shape.getPosition());
	text.setCharacterSize(shape.getSize().y);
}

void UILabel::setString(std::string _content)
{
	text.setString(_content);
}

std::string UILabel::getString()
{
	return text.getString();
}

bool UILabel::getEnabled()
{
	return enabled;
}

void UILabel::setEnabled(bool _val)
{
	enabled = _val;
}

void UILabel::setTextColor(sf::Color _color)
{
	text.setColor(_color);
}

UILabel::~UILabel()
{
}
