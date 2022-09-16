#include <iostream>
#include <sstream>
#include <string>
#include "expression.h"
using namespace std;

// You will need to write your own test harness

// Read and construct expression object. Returns a pointer to a heap-allocated
// object (caller must delete it).

istream &operator>>(istream &in, Expression *&e) {
 		string s;
 while (in >> s) {

    istringstream ss(s);
    int n;
    if (ss >> n) {
			e->input(s);			
    }
    else if (s == "NEG" || s == "ABS") {
			e->input(s);
    }
    else if (s == "+" || s == "-" || s == "*" || s == "/") {
			e->input(s);
    }
    else if (s == "done") {
			stringstream sss;
			e->print(sss);
			cout << sss.str()<<endl;
			break;
    }
    else {
			e->input(s);
    }
  }
  return in;
}

int main () {
  string s;
	Expression ex=Expression();
	Expression* e=&ex;
	cin >> e;

  // Command interpreter
  while (cin >> s) {
    if (s == "eval") {
		e->eval();
    }
    else if (s == "set") {
		string st;
		cin >>st;
		int inte;
		cin >>inte;
    e->setVar(st,inte);
		}

    else if (s == "unset") {
    	string st;
			cin >> st;
			e->unsetVar(st);
		}
    else if (s == "print") {
			stringstream ss;
			e->print(ss);
			string st{ss.str()};
			
			cout << st<<endl;
    }
  }
}





