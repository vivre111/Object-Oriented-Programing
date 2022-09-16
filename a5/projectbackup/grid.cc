#include "grid.h"
#include "fallenBlock.h"
#include <iostream>
using namespace std;

void Grid::attachTetris(FallenBlock &b){
	
}
bool Grid::rowFull(int row){
	return false;
}
void Grid::deleteRow(int row){

}

std::vector<std::vector<Cell>> Grid::getGrid() const {
	return theGrid;
}

int Grid::getHeight(){
	return height; 
}

int Grid::getWidth(){
	return width;
}

Grid::Grid(int r, int c){
	width=c;
	height=r;
	boundary=vector<int> (r,0);
	for(int i=0; i<r; i++){
		vector<Cell> vc;
		for (int j=0; j<c; j++){
			vc.emplace_back(Cell{i,j,' ',true,false,nullptr});
		}
		theGrid.emplace_back(vc);
	}
}


void Grid::kang(){
	for(auto &vc: theGrid){
		for(auto &c:vc){
			if (c.isEmpty){cout<<"/";}
			else {cout<<c.type;}
		}
		cout<<endl;
	}
}







