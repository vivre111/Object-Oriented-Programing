#ifndef _FALLINGBLOCK__H_
#define _FALLINGBLOCK__H_
#include <vector>
#include "cell.h"

class Grid;
class FallenBlock;

class FallingBlock{
	friend class FallenBlock;
	const int timeCreated;
	std::vector<Cell> cells;
	Grid* g;
	public:
	
	std::vector<Cell> getCells()const;
	const int numCells;
	FallingBlock(int,std::vector<Cell>,int,Grid*);

	bool canFall();
	void clockwise();
	void counterclockwise();
	void descend();
	void down();
	void left();
	void right();
	void attachToGrid(Grid* g);
	virtual ~FallingBlock();
};


#endif
