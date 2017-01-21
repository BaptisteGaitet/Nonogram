#include "FontManager.h"


FontManager::FontManager()
{
}

FontManager& FontManager::getInstance()
{
	static FontManager instance;
	return instance;
}

bool FontManager::hasFont(std::string _id)
{
	bool valid = true;

	// Try to access the corresponding Font
	try
	{
		fonts.at(_id);
	}
	catch (const std::out_of_range& oor)
	{
		// Set return value to false
		valid = false;
		// Log the error
		std::cerr << "FontManager: Out of Range error: " << oor.what() << "\n";
	}

	return valid;
}

void FontManager::addFont(std::string _path)
{
	if (!hasFont(_path))
	{
		std::cout << " -> Loading " + _path + "\n";
		sf::Font newFont;
		if (!newFont.loadFromFile(_path))
		{
			std::cout << "FontManager: Error loading: " << _path << "\n";
		}
		std::pair<std::string, sf::Font> newEntry = std::pair<std::string, sf::Font>(_path, newFont);
		fonts.insert(newEntry);
	}
}

sf::Font* FontManager::getFont(std::string _id)
{
	sf::Font* res = nullptr;

	if (hasFont(_id))
	{
		std::cout << "returned font\n";
		res = &fonts.at(_id);
	}

	return res;
}

FontManager::~FontManager()
{
}
