#include "textdisplay.h"
#include <iostream>
using namespace std;


TextDisplay::TextDisplay(int n):gridSize{n}{
	vector<char> v(n,'-');
	theDisplay= vector<vector<char>> (n,v);
	
}

void TextDisplay::notify(Subject<Info, State> &whoNotified){
	Info i=whoNotified.getInfo();
	if (i.colour==Colour::Black){
		theDisplay[i.row][i.col]='B';
	}if (i.colour==Colour::White){
		theDisplay[i.row][i.col]='W';
	}
}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td){
	for(auto &i:td.theDisplay){
 		for(auto &c:i){
 			out << c;
 	}
 	out << endl;
 }
 
 return out;
}



//int main (){
//	TextDisplay t=TextDisplay(4);
//	cout << t;
//}

