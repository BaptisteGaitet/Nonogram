#include "UILevelButton.h"

UILevelButton::UILevelButton(std::string _id, sf::IntRect _bounds, int _drawOrder) : UIElement(_id, _bounds, _drawOrder)
{
	text = sf::Text();
	medalShape = sf::RectangleShape();
	selected = false;
	enabled = true;
	state = idle;
	levelNumber = 0;
	beaten = false;
	clic = false;

	TextureManager::getInstance().addTexture("img/btnLevel.png");
	shape.setTexture(TextureManager::getInstance().getTexture("img/btnLevel.png"));
	shape.setTextureRect(sf::IntRect(0, 0, 32,32));

	TextureManager::getInstance().addTexture("img/solved.png");
	medalShape.setTexture(TextureManager::getInstance().getTexture("img/solved.png"));
	medalShape.setTextureRect(sf::IntRect(0, 0, 16, 16));

	FontManager::getInstance().addFont("fnt/shty.ttf");
	text.setFont(*FontManager::getInstance().getFont("fnt/shty.ttf"));
	text.setString(std::to_string(levelNumber));
	text.setColor(sf::Color(50, 50, 50));
	text.setCharacterSize(40);

	AudioManager::getInstance().addSound("snd/clic.ogg");

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
				AudioManager::getInstance().playSound("snd/clic.ogg");
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
		medalShape.setPosition(sf::Vector2f(shape.getPosition().x + (shape.getSize().x / 2), shape.getPosition().y + (shape.getSize().y /2)));
		medalShape.setSize(sf::Vector2f(shape.getSize().x/2, shape.getSize().y/2));
		text.setPosition(shape.getPosition().x + 10, shape.getPosition().y - 4);

		window->draw(shape);
		window->draw(text);

		if (beaten)
		{
			window->draw(medalShape);
		}
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

void UILevelButton::setBeaten(bool _val)
{
	beaten = _val;
}

UILevelButton::~UILevelButton()
{
}
