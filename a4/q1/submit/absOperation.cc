#include "absOperation.h"

int AbsOperation::eval(std::string *noValue,std::vector<int> vals,std::vector<std::string> vars){
	return 0;
}
void AbsOperation::print(std::stringstream &oss,std::vector<int> vals,std::vector<std::string> vars){}
	
AbsOperation* AbsOperation::copy(){
	return nullptr;
}

AbsOperation::~AbsOperation(){}
