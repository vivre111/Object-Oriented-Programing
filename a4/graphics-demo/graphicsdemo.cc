#include <iostream>
#include "window.h"

using namespace std;

int main() {
  Xwindow w;
	
	int winSize=500;
	int numGrid=10;
	int sizeCell=winSize/numGrid;
	int color=2;
  w.fillRectangle(0,0,500,500,3);
	
	for (int i = 0 ; i < numGrid; i++) {
		for(int j=0;j<numGrid;j++ ){
		  w.fillRectangle(i*sizeCell,j*sizeCell,sizeCell,sizeCell,color);
			color++;
			if (color==4){color=2;}
		
		}
		color++;
		if(color==4){color=2;}
  }
	


  w.drawString(50, 50, "Hello!");

  w.drawString(50, 100, "ABCD");

  w.drawString(50, 150, "Hello!");

//  Xwindow w2(199, 199);
//  w2.drawString(50, 100, "ABCD");


  //w.showAvailableFonts();

  char c;
  cin >> c;
	if(c=='q'){
	return 0;
	}
}

