#ifndef _GRID__H_
#define _GRID__H_

#include <vector>
#include "cell.h"

class FallenBlock;

class Grid{
	int width;
	int height;
	std::vector<int> boundary;
	std::vector<FallenBlock*> fallenBlock;
	std::vector<std::vector<Cell>> theGrid;
	public:
	void kang();
	int getWidth();
	int getHeight();
	Grid(int r, int c);
	void attachTetris(FallenBlock &b);
	bool rowFull(int row);
	void deleteRow(int row);
	std::vector<std::vector<Cell>> getGrid() const;
};


#endif
