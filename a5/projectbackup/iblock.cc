#include "iblock.h"
#include "cell.h"
using namespace std;



//FallingBlock::FallingBlock(int time, vector<Cell> cells,int numCells):timeCreated{time},cells{cells},numCells{numCells}{}

vector<Cell> f(){
	Cell c1{3,0,'i',true,false,nullptr};
	Cell c2{3,1,'i',true,false,nullptr};
	Cell c3{3,2,'i',true,false,nullptr};
	Cell c4{3,3,'i',true,false,nullptr};
	vector<Cell> cells={c1,c2,c3,c4};
	return cells;

}


Iblock::Iblock(int time,Grid* g):FallingBlock{time,f(),4,g}{}


