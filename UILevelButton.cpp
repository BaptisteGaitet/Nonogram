#include "UILevelButton.h"

UILevelButton::UILevelButton(std::string _id, sf::IntRect _bounds, int _drawOrder) : UIElement(_id, _bounds, _drawOrder)
{
	selected = false;
	enabled = true;
	state = idle;
	levelNumber = 0;

	TextureManager::getInstance().addTexture("btnLevel.png");
	shape.setTexture(TextureManager::getInstance().getTexture("btnLevel.png"));
	shape.setTextureRect(sf::IntRect(0, 0, 32,32));

	FontManager::getInstance().addFont("shty.ttf");
	text.setFont(*FontManager::getInstance().getFont("shty.ttf"));
	text.setString(std::to_string(levelNumber));
	text.setColor(sf::Color(50, 50, 50));
	text.setCharacterSize(40);
}

void UILevelButton::update()
{
	clic = false;
	if (enabled)
	{
		sf::IntRect pixelBounds = sf::IntRect(shape.getPosition().x, shape.getPosition().y, shape.getSize().x, shape.getSize().y);

		if (MouseManager::getInstance().isOver(pixelBounds))
		{
			if (MouseManager::getInstance().isLeftDown())
			{
				state = pressed;
			}
			else if (state == pressed)
			{
				clic = true;
				selected = true;
				state = idle;
			}
			else if (!selected)
			{
				state = hovered;
			}
		}
		else if(!selected)
		{
			state = idle;
		}

		sf::IntRect rect = shape.getTextureRect();
		if (state == idle && !selected)
		{
			shape.setTextureRect(sf::IntRect(0, 0, rect.width, rect.height));
		}
		else if (state == hovered && !selected)
		{
			shape.setTextureRect(sf::IntRect(rect.width, 0, rect.width, rect.height));
		}
		else
		{
			shape.setTextureRect(sf::IntRect(rect.width * 2, 0, rect.width, rect.height));
		}
	}
}

void UILevelButton::draw(sf::RenderWindow* window)
{
	if (enabled)
	{
		snapToDisplayArea();
		text.setPosition(shape.getPosition().x + 10, shape.getPosition().y - 4);

		window->draw(shape);
		window->draw(text);
	}
}

bool UILevelButton::getClic()
{
	return clic;
}

void UILevelButton::setLevelNumber(int _number)
{
	levelNumber = _number;
	text.setString(std::to_string(levelNumber + 1));
}

int UILevelButton::getLevelNumber()
{
	return levelNumber;
}

bool UILevelButton::getEnabled()
{
	return enabled;
}

void UILevelButton::setEnabled(bool _enabled)
{
	enabled = _enabled;
}

bool UILevelButton::getSelected()
{
	return (state == selected);
}

void UILevelButton::setSelected(bool _selected)
{
	selected = _selected;
}

UILevelButton::~UILevelButton()
{
}
