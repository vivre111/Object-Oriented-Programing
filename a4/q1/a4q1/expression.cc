#include "expression.h"
using namespace std;

	void Expression::setVar(string var,int value){
		int ith=0;
		for (auto& it : variables){
			if (it==var){
				values[ith]=value;
				return;
			}
			ith++;
		}
		variables.emplace_back(var);
		values.emplace_back(value);
	}

	void Expression::unsetVar(string var){
		for(auto &it : variables){
			if(it==var){
				it.erase();		
			}
		}
	}

	int Expression::eval(){
		int result= head->eval(&noValue,values,variables);
		if(noValue!=""){
			cout<<noValue << " has no value."<<endl;
			noValue="";
			return 0;
		}else{
			cout << result<<endl;
			return result;
		}
	}
			
	void Expression::print(stringstream &ss){
		head->print(ss,values,variables);
	}

	void Expression::input(string s){
		stringstream ss(s);
		int newint;
	  int size=exps.size();
		if (ss>>newint){
			AbsOperation *in=new IntVal(newint);
			exps.emplace_back(in);
			if (head==nullptr){
				head=in;
			}
		}
		else if (s=="+"|| s=="-"||s=="*"||s=="/"){
			AbsOperation* bi=new BinaryOper(s,exps[size-2],exps[size-1]);
			exps[size-1]=nullptr;
			exps[size-2]=nullptr;
			exps.resize(size-2);
			exps.emplace_back(bi);
			head=bi;
		}
		else if (s=="NEG"||s=="ABS"){
			AbsOperation* un=new UnaryOper(s,exps[size-1]);
			exps[size-1]=nullptr;
			exps.resize(size-1);
			exps.emplace_back(un);
			head=un;
		}else{
			AbsOperation* var=new Variable(s,values,variables);
			exps.emplace_back(var);
			if (head==nullptr){
				head=var;
			}
		}

	}

	Expression::~Expression(){
		delete head;
	}
		

