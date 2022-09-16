#include "intVal.h"
#include "absOperation.h"

using namespace std;

int IntVal::eval(string *noVal,std::vector<int> vals,std::vector<std::string> vars){
		return value;
	}

void IntVal::print(stringstream &oss,std::vector<int> vals,std::vector<std::string> vars){
		oss << value;
	}
 
IntVal::IntVal(int _val):value{_val}{}

IntVal::~IntVal(){}

