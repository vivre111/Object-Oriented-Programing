#include "textdisplay.h"
#include "grid.h"
#include "fallingBlock.h"
#include <iostream>
#include <vector>
using namespace std;

TextDisplay::TextDisplay(const Grid &g, const FallingBlock &fb):g{g},fb{fb}{}

void TextDisplay::draw(){
	vector<vector<char>> mat;
	for(auto &vc: g.getGrid()){
		vector<char> newvc;
		for(auto &c:vc){
			if (c.isEmpty){newvc.emplace_back('/');}
			else {newvc.emplace_back(c.type);}
		}
		mat.emplace_back(newvc);
	}
	for(auto &cell:fb.getCells()){
		mat[cell.row][cell.col]=cell.type;
	}	
	

	for(auto &vec: mat){
		for(auto &element: vec){
			cout << element;
		}
		cout << endl;
	}
	cout<<"------------"<<endl;
}

