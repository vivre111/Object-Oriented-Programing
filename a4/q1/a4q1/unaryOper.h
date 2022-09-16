#ifndef _UNARYOPER__H_
#define _UNARYOPER__H_

#include "absOperation.h"

class UnaryOper: public AbsOperation{
	std::string op;
	AbsOperation* child;
	public:
	UnaryOper(std::string op,AbsOperation* child);
	int eval(std::string *noVal,std::vector<int> vals,std::vector<std::string> vars) override;
	void print(std::stringstream &ss,std::vector<int> vals,std::vector<std::string> vars) override;
	~UnaryOper();
};
#endif
