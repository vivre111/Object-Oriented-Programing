#include "zblock.h"
#include "cell.h"
using namespace std;



//FallingBlock::FallingBlock(int time, vector<Cell> cells,int numCells):timeCreated{time},cells{cells},numCells{numCells}{}

vector<Cell> initZ(){
	Cell c1{2,3,'z',true,false,nullptr};
	Cell c2{2,4,'z',true,false,nullptr};
	Cell c3{3,4,'z',true,false,nullptr};
	Cell c4{4,4,'z',true,false,nullptr};
	vector<Cell> cells={c1,c2,c3,c4};
	return cells;

}


//vector<Cell> initZ(){
//	Cell c1{2,0,'z',true,false,nullptr};
//	Cell c2{2,1,'z',true,false,nullptr};
//	Cell c3{3,1,'z',true,false,nullptr};
//	Cell c4{3,2,'z',true,false,nullptr};
//	vector<Cell> cells={c1,c2,c3,c4};
//	return cells;
//
//}
Zblock::Zblock(int time,Grid *g):FallingBlock{time,initZ(),4,g}{}


