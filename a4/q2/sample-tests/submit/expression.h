#ifndef __EXPRESSION__H__
#define __EXPRESSION__H__
#include "intVal.h"
#include "absOperation.h"
#include "binaryOper.h"
#include "unaryOper.h"
#include <vector>
#include <string>
#include <sstream>
#include "variable.h"
#include "noValue.h"
class Expression{
 	std::vector<std::string> variables;
	std::vector<int> values;
	AbsOperation* head=nullptr;
	std::vector<AbsOperation*> exps;
  std::string noValue{""};
public:
	void setVar(std::string var, int value);
	void unsetVar(std::string var);
	void input(std::string s);
	int eval();
	void print(std::stringstream &ss);
	Expression* copy();
	Expression();
	Expression(std::vector<std::string> vs, std::vector<int> vi,AbsOperation* hea,
		std::vector<AbsOperation*> va);
	~Expression();	
};



#endif
