#include "UIImage.h"


UIImage::UIImage(std::string _id, sf::IntRect _bounds, int _drawOrder, std::string _path) : UIElement(_id, _bounds, _drawOrder)
{
	TextureManager::getInstance().addTexture(_path);
	shape.setTexture(TextureManager::getInstance().getTexture(_path));
	shape.setTextureRect(sf::IntRect(0, 0, TextureManager::getInstance().getTexture(_path)->getSize().x, TextureManager::getInstance().getTexture(_path)->getSize().y));
}

void UIImage::update()
{

}

void UIImage::draw(sf::RenderWindow* window)
{
	sf::Vector2i screensize = sf::Vector2i(window->getSize().x, window->getSize().y);
	setShapePixelSize(screensize);

	window->draw(shape);

	//std::cout << shape.getPosition().x << ", " << shape.getPosition().y << "\n";
	//std::cout << shape.getSize().x << ", " << shape.getSize().y << "\n";
}

UIImage::~UIImage()
{
}
