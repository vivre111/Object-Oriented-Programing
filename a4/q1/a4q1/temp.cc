#include <iostream>
#include <sstream>
#include <string>
#include "expression.h"
using namespace std;

int main(){
	Expression ex;
	Expression *e=&ex;
	e->input("3");
	e->input("4");
	e->input("+");
}

