#ifndef LEVEL_H
#define LEVEL_H

#include "Nonogram.h"
#include <string>

class Level
{
private:
	std::string imagePath;
	std::string description;
	Nonogram* nonogram;
	bool beaten;
public:
	Level(std::string _imagePath, std::string _description, Nonogram* _nonogram, bool _beaten);

	std::string getImagePath();
	void setImagePath(std::string _imagePath);
	std::string getDescription();
	void setDescription(std::string _description);
	Nonogram* getNonogram();
	void setNonogram(Nonogram* _nonogram);
	bool getBeaten();
	void setBeaten(bool _beaten);

	~Level();
};

#endif