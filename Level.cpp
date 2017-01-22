#include "Level.h"

Level::Level(std::string _imagePath, std::string _description, Nonogram* _nonogram, bool _beaten)
{
	imagePath = _imagePath;
	description = _description;
	nonogram = _nonogram;
	beaten = _beaten;
}

std::string Level::getImagePath()
{
	return imagePath;
}

void Level::setImagePath(std::string _imagePath)
{
	imagePath = _imagePath;
}

std::string Level::getDescription()
{
	return description;
}

void Level::setDescription(std::string _description)
{
	description = _description;
}

Nonogram* Level::getNonogram()
{
	return nonogram;
}

void Level::setNonogram(Nonogram* _nonogram)
{
	nonogram = _nonogram;
}

bool Level::getBeaten()
{
	return beaten;
}

void Level::setBeaten(bool _beaten)
{
	beaten = _beaten;
}

Level::~Level()
{
}
