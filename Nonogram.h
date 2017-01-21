#ifndef NONOGRAM_H
#define NONOGRAM_H

#include <list>
#include <string>

class Nonogram
{
private:
	bool * grid;
	int height;
	int width;
public:
	Nonogram(int _width, int _height, bool* _grid);

	int getWidth();
	int getHeight();
	bool getCell(int _row, int _column);
	std::string toString();
	std::string getRowHint(int _row);
	std::string getColumnHint(int _column);

	~Nonogram();
};

#endif;