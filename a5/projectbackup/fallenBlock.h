#ifndef _FALLENBLOCK__H_
#define _FALLENBLOCK__H_
class FallingBlock;

class FallenBlock{
	int cellsLeft;
	public:
	const int timeCreated;
	FallenBlock(FallingBlock &falling);
	void cellDeleted();
};


#endif
