#include "grid.h"
using namespace std;

bool outofBoard(size_t i,size_t j, size_t n){
	if(i<0||i>=n||j<0||j>=n){return true;}
	return false;
}


void Grid::init(size_t n){
	delete td;
	theGrid.clear();
	numPieces=0;
	if (n%2==1||n<4){throw(InvalidMove());}

	int in=n;
	gridSize=n;
  td=new TextDisplay(in);
	
	for (size_t i=0;i<n;i++){
		vector<Cell> row;
		for (size_t j=0;j<n;j++){
			row.emplace_back(Cell(i,j));
		}
		theGrid.emplace_back(row);
	}
	
	//setPiece(n/2,n/2,Colour::Black);

	//set neibours
	for(size_t i=0;i<n;i++){
		for(size_t j=0;j<n;j++){
			Observer<Info,State> *ob= td;
			theGrid[i][j].attach(ob);
			for(size_t r=0;r<3;r++){
				for(size_t c=0;c<3;c++){
					if(r==1 && c==1) {continue;}
					if(outofBoard(i+r-1,j+c-1,n)){continue;}
					Observer <Info,State>* o=&theGrid[i+r-1][j+c-1];
					theGrid[i][j].attach(o);
										numPieces=4;
				}
			}
		}
	}
	theGrid[n/2-1][n/2-1].setPiece(Colour::Black);
	theGrid[n/2-1][n/2].setPiece(Colour::White);
	theGrid[n/2][n/2-1].setPiece(Colour::White);
	theGrid[n/2][n/2].setPiece(Colour::Black);

}


Grid::~Grid(){
	delete td;
}
 	 
  void  Grid::setObserver(Observer<Info, State> *ob){
	}


  bool  Grid::isFull() const{
		int n=gridSize;
		if(numPieces==0){return false;}
		return (numPieces>=n*n);}  // Is the game over, i.e., is the grid full?
 
 Colour  Grid::whoWon() const{
		int whites=0;
		int gr=gridSize;
		for (int i=0;i<gr;i++){
			for(int j =0;j<gr;j++){
					Info in=theGrid[i][j].getInfo();
					if(in.colour==Colour::White){whites++;}
				}
			}
		
		if (2*whites<gr*gr){return Colour::Black;}
		if (2*whites==gr*gr){return Colour::NoColour;}	
		if (2*whites>gr*gr){return Colour::White;}
		return Colour::NoColour;
	} // Who has more pieces when the board is full?

void  Grid::setPiece(size_t r, size_t c, Colour colour){
		if (r>=gridSize||c>=gridSize||r<0||c<0){throw InvalidMove();}
		Info i=theGrid[r][c].getInfo();
		if (i.colour!=Colour::NoColour){throw InvalidMove();}
		theGrid[r][c].setPiece(colour);
		numPieces++;
	}  // Plays piece at row r, col c.

void  Grid::toggle(size_t r, size_t c){
		theGrid[r][c].toggle();
	}  // Flips piece at row r, col c.

  std::ostream  &operator<<(std::ostream &out, const Grid &g){
		TextDisplay *t=g.td;
		out << *t;		
		return out;
	}


