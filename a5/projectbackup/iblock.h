#ifndef _IBLOCK__H_
#define _IBLOCK__H_
#include "fallingBlock.h"
class Grid;
class Iblock:public FallingBlock{
	public:
	Iblock(int time,Grid* g);	
};


#endif
