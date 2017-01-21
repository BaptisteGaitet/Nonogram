#ifndef FONT_MANAGER_H
#define FONT_MANAGER_H

#include <SFML\Graphics.hpp>
#include <iostream>
#include <map>
#include <string>

class FontManager
{
private:
	FontManager();
	FontManager(FontManager const&);
	void operator=(FontManager const&);

	std::map<std::string, sf::Font> fonts;
	bool hasFont(std::string _id);
public:
	static FontManager& getInstance();

	void addFont(std::string _path);
	sf::Font getFont(std::string _id);

	~FontManager();
};

#endif