#include <iostream>
#include <string>
// You may include other allowed headers, as needed
#include "grid.h"
#include "state.h"
using namespace std;

// Do not remove any code; do not add code other than where indicated.

int main(int argc, char *argv[]) {
  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd;
  Grid g;
	bool blackmove=true;
  // Add code here

  try {
  while (true) {
		if(g.isFull()){
			Colour won=g.whoWon();
			if (won==Colour::Black){
				cout<<"Black wins!"<<endl;
			}else if(won==Colour::White){
				cout<<"White wins!"<<endl;
			}else{
				cout<<"Tie!"<<endl;
			}
			return 0;
		}
    cin >> cmd;
    if (cmd == "new") {
      int n;
      cin >> n;
			try{
			g.init(n);
			cout<<g;
			}catch(InvalidMove){}
      // Add code here
    }
    else if (cmd == "play") {
      int r = 0, c = 0;
      cin >> r >> c;
		try{
			if(blackmove){
					g.setPiece(r,c,Colour::Black);
					blackmove=false;
			}else{
				g.setPiece(r,c,Colour::White);
				blackmove=true;
			}
			cout<<g;
      // Add code here
    }
		catch(InvalidMove){}
		}
  }
  }
  catch (ios::failure &) {}  // Any I/O failure quits
}
