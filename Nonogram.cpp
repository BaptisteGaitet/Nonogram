#include "Nonogram.h"

Nonogram::Nonogram()
{
	width = 5;
	height = 5;
	grid = new bool[width * height];
	for (int i = 0; i < width * height; i++)
	{
		grid[i] = false;
	}
}

Nonogram::Nonogram(int _width, int _height, bool * _grid)
{
	width = _width;
	height = _height;
	grid = new bool[_width * _height];
	for (int i = 0; i < _width * _height; i++)
	{
		grid[i] = _grid[i];
	}
}

int Nonogram::getWidth()
{
	return width;
}

int Nonogram::getHeight()
{
	return height;
}

bool Nonogram::getCell(int _row, int _column)
{
	return grid[(_row * width) + _column];
}

std::string Nonogram::toString()
{
	std::string res = "";

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (grid[i * width + j])
			{
				res += "1 ";
			}
			else
			{
				res += "0 ";
			}
		}
		res += "\n";
	}

	return res;
}

std::string Nonogram::getRowHint(int _row)
{
	std::string res;
	int consecutiveCell = 0;

	for (int i = 0; i < width; i++)
	{
		if (grid[_row * width + i])
		{
			consecutiveCell++;
		}else{
			if (consecutiveCell > 0)
			{
				if (res.size() > 0)
				{
					res += " ";
				}
				res += std::to_string(consecutiveCell);
				consecutiveCell = 0;
			}
		}

		if (i == width - 1)
		{
			if (consecutiveCell > 0)
			{
				if (res.size() > 0)
				{
					res += " ";
				}
				res += std::to_string(consecutiveCell);
			}
			else if (res.size() == 0)
			{
				res += "0";
			}
		}
	}
	return res;
}

std::string Nonogram::getColumnHint(int _column)
{
	std::string res;
	int consecutiveCell = 0;

	for (int i = 0; i < height; i++)
	{
		if (grid[i * width + _column])
		{
			consecutiveCell++;
		}
		else{
			if (consecutiveCell > 0)
			{
				if (res.size() > 0)
				{
					res += "\n";
				}
				res += std::to_string(consecutiveCell);
				consecutiveCell = 0;
			}
		}

		if (i == height - 1)
		{
			if (consecutiveCell > 0)
			{
				if (res.size() > 0)
				{
					res += "\n";
				}
				res += std::to_string(consecutiveCell);
			}
			else if (res.size() == 0)
			{
				res += "0";
			}
			//res += "\n";
		}
	}
	return res;
}

Nonogram::~Nonogram()
{
	delete[width * height] grid;
}
