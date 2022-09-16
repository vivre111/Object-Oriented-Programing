#include "grid.h"
using namespace std;

bool outofBoard(size_t i,size_t j, size_t n){
	if(i<0||i>=n||j<0||j>=n){return true;}
	return false;
}


void Grid::init(size_t n){
	vector<Cell*> row(n,nullptr);
	vector<vector<Cell*>> mat(n,row);
	for (size_t i=0;i<n;i++){
		for (size_t j=0;j<n;j++){
			Cell *newCell=new Cell(i,j);
			mat[i][j]=newCell;
		}
	}
	//set neibours
	for(size_t i=0;i<n;i++){
		for(size_t j=0;j<n;j++){
			for(size_t r=-1;r<2;r++){
				for(size_t c=-1;c<2;c++){
					if(r==0 && c==0) {continue;}
					if(outofBoard(i+r,j+c,n)){continue;}
					Observer <Info,State>* o=mat[i+r][j+c];
					mat[i][j]->attach(o);
				}
			}
		}
	}
}  
Grid::~Grid(){}
  
  void  Grid::setObserver(Observer<Info, State> *ob){}
  bool  Grid::isFull() const{return false;}  // Is the game over, i.e., is the grid full?
  Colour  Grid::whoWon() const{return Colour::White;} // Who has more pieces when the board is full?
  void  Grid::setPiece(size_t r, size_t c, Colour colour){}  // Plays piece at row r, col c.
  void  Grid::toggle(size_t r, size_t c){}  // Flips piece at row r, col c.

  std::ostream  &operator<<(std::ostream &out, const Grid &g){
		out <<1;
		return out;
	}

