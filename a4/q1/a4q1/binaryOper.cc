#include "binaryOper.h"

using namespace std;
	BinaryOper::BinaryOper(string op,AbsOperation *lhs, AbsOperation *rhs):op{op},lhs{lhs},rhs{rhs}{}
	int BinaryOper::eval(string *noVal,std::vector<int> vals,std::vector<std::string> vars){
		int r= rhs->eval(noVal,vals,vars);
		int l= lhs->eval(noVal,vals,vars);
		if (op=="+"){return l+r;}
		if (op=="-"){return l-r;}
		if (op=="*"){return l*r;}
		if (op=="/"){return l/r;}
		else return 0;
	}
	void BinaryOper::print(stringstream &ss,std::vector<int> vals,std::vector<std::string> vars){
		ss << "(";
		lhs->print(ss,vals,vars);
		ss <<" "<< op<<" ";
		rhs->print(ss,vals,vars);
		ss << ')';
	}
	BinaryOper::~BinaryOper(){
		delete rhs;
		delete lhs;
	}

