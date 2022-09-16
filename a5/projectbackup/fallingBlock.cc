#include "fallenBlock.h"
#include "fallingBlock.h"
#include "grid.h"
#include <iostream>
using namespace std;
bool FallingBlock::canFall(){
	return true;
}

FallingBlock::FallingBlock(int time, vector<Cell> cells,int numCells,Grid* g):timeCreated{time},cells{cells},numCells{numCells},g{g}{}

void FallingBlock::counterclockwise(){
	int x=cells[0].col;
	int y=cells[0].row;
	int X=cells[0].col;
	int Y=cells[0].row;
	for (auto &c: cells){
		if (x>c.col){x=c.col;}
		if (X<c.col){X=c.col;}
		if (y>c.row){y=c.row;}
		if (Y<c.row){Y=c.row;}
		}

	
	for (auto &c:cells){
		int col=c.col;
		int row=c.row;
		c.row=Y-col+x;
		c.col= x+row-y;
	}	
}


void FallingBlock::clockwise(){
	
	int x=cells[0].col;
	int y=cells[0].row;
	int X=cells[0].col;
	int Y=cells[0].row;
	for (auto &c: cells){
		if (x>c.col){x=c.col;}
		if (X<c.col){X=c.col;}
		if (y>c.row){y=c.row;}
		if (Y<c.row){Y=c.row;}
		}

	
	for (auto &c:cells){
		int col=c.col;
		int row=c.row;
		c.row=Y-X+col;
		c.col= x+Y-row;
	}
}

void FallingBlock::descend(){
	for (auto &c:cells){
		c.row++;
	}
		
}

vector<Cell> FallingBlock::getCells()const{
	return cells;
}
void FallingBlock::down(){}
void FallingBlock::left(){}
void FallingBlock::right(){}
void FallingBlock::attachToGrid(Grid* g){}
FallingBlock::~FallingBlock(){
}

