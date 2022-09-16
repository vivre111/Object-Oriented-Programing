#include "unaryOper.h"

using namespace std;

	
	int UnaryOper::eval(string *noVal,std::vector<int> vals,std::vector<std::string> vars){
		int childScore=child->eval(noVal,vals,vars);
		if (op=="ABS"){return (childScore<0)? -childScore:childScore;}
		if (op=="NEG"){return -childScore;}
		return 0;
	}

	void UnaryOper::print(stringstream &ss,std::vector<int> vals,std::vector<std::string> vars){
		if (op=="ABS"){
			ss << "|";
			child->print(ss,vals,vars);
			ss << "|";
		}
		else if (op=="NEG"){
			ss << "-";
			child->print(ss,vals,vars);
		}
	}

	AbsOperation* UnaryOper::copy(){
		AbsOperation* ch=child->copy();
		UnaryOper* u=new UnaryOper(op,ch);
		return u;
	}



	UnaryOper::~UnaryOper(){
		delete child;
	}

	UnaryOper::UnaryOper(string op,AbsOperation* child):op{op},child{child}{}
