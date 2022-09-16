#include "graphicdisplay.h"
#include <iostream>
using namespace std;


GraphicDisplay::~GraphicDisplay(){
}

GraphicDisplay::GraphicDisplay(Xwindow* w):w{w}{
		w->fillRectangle(0,0,500,500,3);
		w->drawString(240,0,"Hello");
		w->drawString(230,75,"Bonjour");
		w->drawString(230,150,"Ni Hao");
		w->drawString(225,225,"Kon'nichiwa");

		w->drawString(210,300,"Welcome to reversi");
		
		w->drawString(100,400,"type 'new n'; n is number of grid size (n=0 mod 2 and n>=4)");
	}


void GraphicDisplay::init(int n){
		numGrid=n;
		int color=2;
		int sizeCell=500/n;
		for (int i = 0 ; i < numGrid; i++) {
			for(int j=0;j<numGrid;j++ ){
		  		w->fillRectangle(i*sizeCell,j*sizeCell,sizeCell,sizeCell,color);
					color++;
					if (color==4){color=2;}
		
				}
			color++;
			if(color==4){color=2;}
  	}
		int paint=(numGrid/2-1)*sizeCell;
		w->fillRectangle(paint,paint,sizeCell,sizeCell,1);
		w->fillRectangle(paint,paint+sizeCell,sizeCell,sizeCell,0);
		w->fillRectangle(paint+sizeCell,paint,sizeCell,sizeCell,0);
		w->fillRectangle(paint+sizeCell,paint+sizeCell,sizeCell,sizeCell,1);
	}

void GraphicDisplay::notify(Subject<Info, State> &whoNotified){
	State s=whoNotified.getState();
	Info i=whoNotified.getInfo();
	if(s.type==StateType::Reply||s.type==StateType::NewPiece){
		int x=i.row;
		int sizeCell=500/numGrid;
		int y=i.col;
		int co= (s.colour==Colour::Black? 1:0);
		w->fillRectangle(y*sizeCell,x*sizeCell,sizeCell,sizeCell,co);
	}
}

