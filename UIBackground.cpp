#include "UIBackground.h"

UIBackground::UIBackground(std::string _id, int _drawOrder, std::string _path) : UIElement(_id, sf::IntRect(0,0,100,100), _drawOrder)
{
	// TEST //
	TextureManager::getInstance().addTexture(_path);
	TextureManager::getInstance().setRepeated(_path, true);
	shape.setTexture(TextureManager::getInstance().getTexture(_path));
	
	//////////
}

void UIBackground::update()
{
	// TEST //
	sf::IntRect tmp = shape.getTextureRect();
	tmp.left-=1;
	tmp.top-=1;
	shape.setTextureRect(tmp);
	//////////
}

void UIBackground::draw(sf::RenderWindow* window)
{
	sf::Vector2f size = sf::Vector2f(WindowManager::getInstance().getScreenSize().x, WindowManager::getInstance().getScreenSize().y);
	shape.setSize(size);
	shape.setPosition(0, 0);
	shape.setTextureRect(sf::IntRect(shape.getTextureRect().left, shape.getTextureRect().top, WindowManager::getInstance().getScreenSize().x / 2, WindowManager::getInstance().getScreenSize().y / 2));

	window->draw(shape);
}

UIBackground::~UIBackground()
{
}
