#include "UILabel.h"


UILabel::UILabel(std::string _id, sf::Vector2f _position, float _characterSize, int _drawOrder, std::string _content) : UIElement(_id, sf::IntRect(), _drawOrder)
{
	enabled = true;
	FontManager::getInstance().addFont("shty.ttf");
	text.setFont(*FontManager::getInstance().getFont("shty.ttf"));
	text.setPosition(_position);
	text.setCharacterSize(_characterSize);
	text.setString(_content);
	text.setColor(sf::Color(50,50,50));

	shape.setFillColor(sf::Color(50, 200, 50));
	//std::cout << text.getGlobalBounds().left << ", " << text.getGlobalBounds().top << ", " << text.getGlobalBounds().width << ", " << text.getGlobalBounds().height << "\n";
	setPosition(sf::Vector2f(text.getGlobalBounds().left, text.getGlobalBounds().top));
	setSize(sf::Vector2f(text.getGlobalBounds().width, text.getGlobalBounds().height));
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
		//window->draw(shape);
		window->draw(text);
	}
}

void UILabel::snapTextToShape()
{
	text.setPosition(shape.getPosition());
	text.setScale(WindowManager::getInstance().getStretchRatio(), WindowManager::getInstance().getStretchRatio());
}

void UILabel::setString(std::string _content)
{
	text.setString(_content);
	//setPosition(sf::Vector2f(text.getGlobalBounds().left, text.getGlobalBounds().top));
	setSize(sf::Vector2f(text.getGlobalBounds().width, text.getGlobalBounds().height));
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

sf::FloatRect UILabel::getTextBounds()
{
	return text.getLocalBounds();
}

sf::Vector2f UILabel::getCharacterPos(int _index)
{
	return text.findCharacterPos(_index);
}

float UILabel::getWidth()
{
	float res = 0;

	for (int i = 0; i < text.getString().getSize(); i++)
	{
		res += text.getFont()->getGlyph(text.getString()[i], text.getCharacterSize(), false).advance;
	}
	std::cout << res << "\n";
	return res;
}

int UILabel::getLinesNumber()
{
	int res = 0;

	for (int i = 0; i < text.getString().getSize(); i++)
	{
		if (text.getString()[i] == '\n')
		{
			res++;
		}
	}

	return res;
}

UILabel::~UILabel()
{
}
