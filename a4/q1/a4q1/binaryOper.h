#ifndef _BINARYOPER__H_
#define _BINARYOPER__H_
#include "absOperation.h"

class BinaryOper: public AbsOperation{
	std::string op;
	AbsOperation *lhs;
	AbsOperation *rhs;
public:
	BinaryOper(std::string op ,AbsOperation *lhs, AbsOperation *rhs);
	int eval(std::string *noVal,std::vector<int> vals,std::vector<std::string> vars) override;
	void print(std::stringstream &ss,std::vector<int> vals,std::vector<std::string> vars) override;
	~BinaryOper();
};
#endif
