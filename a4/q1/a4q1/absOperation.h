#ifndef ABSOPERATION_H
#define ABSOPERATION_H
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
class AbsOperation{
	public:
	virtual int eval(std::string *noValue,std::vector<int> vals,std::vector<std::string> vars)=0;
	virtual void print(std::stringstream &oss,std::vector<int> vals,std::vector<std::string> vars)=0;
	virtual ~AbsOperation();
	};

#endif
