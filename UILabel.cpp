#include "UILabel.h"


UILabel::UILabel(std::string _id, sf::IntRect _bounds, int _drawOrder, std::string _content) : UIElement(_id, _bounds, _drawOrder)
{
	FontManager::getInstance().addFont("shty.ttf");
	text.setFont(FontManager::getInstance().getFont("shty.ttf"));
	text.setString(_content);
}

void UILabel::update()
{

}

void UILabel::draw(sf::RenderWindow* window)
{
	snapToDisplayArea();
	snapTextToShape();
	window->draw(text);
}

void UILabel::snapTextToShape()
{
	text.setPosition(shape.getPosition());
	text.setCharacterSize(shape.getSize().y);
}

UILabel::~UILabel()
{
}
