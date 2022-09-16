#ifndef __INTVAL_H__
#define __INTVAL_H__
#include <sstream>
#include "absOperation.h"
#include <vector>
class IntVal: public AbsOperation{
	
	int value;
	
	public:
	IntVal(int val_);
	int eval(std::string *noVal,std::vector<int> vals,std::vector<std::string> vars) override;
	void print(std::stringstream &oss,std::vector<int> vals,std::vector<std::string> vars) override;
	~IntVal();
	AbsOperation* copy() override;
};

#endif
