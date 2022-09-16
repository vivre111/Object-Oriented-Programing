#ifndef _CELL__H_
#define _CELL__H_

class Block;

struct Cell {
	int row;
	int col;
	char type;
	bool isEmpty;
	bool isBlur;
	Block* belongTo;
};

#endif
