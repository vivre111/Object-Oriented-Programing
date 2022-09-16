#include "expression.h"
using namespace std;

int main(){
	Expression ex;
	ex.input("1");
	ex.input("2");
	ex.input("+");
	ex.input("a");
	ex.input("*");
  ex.setVar("a",2);
	ex.unsetVar("a");
	stringstream ss;	
	ex.print(ss);
	string s=ss.str();
	cout << s;
	int i=ex.eval();
	cout << i;
}
