#ifndef _VARIABLE__H_
#define _VARIABLE__H_

#include "absOperation.h"
#include "expression.h"

class Variable: public AbsOperation{
	std::string varName;
	std::vector<int> vals;
	std::vector<std::string> vars;
	public:
	Variable(std::string varName,std::vector<int> vals,std::vector<std::string> vars);
	~Variable();
	int eval(std::string *noVal,std::vector<int> vals,std::vector<std::string> vars) override;
  void	print(std::stringstream &ss,std::vector<int> vals,std::vector<std::string> vars) override;

};




#endif
