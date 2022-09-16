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
	Expression::Expression(std::vector<std::string> vs, std::vector<int> vi,AbsOperation* hea,
		std::vector<AbsOperation*> va):variables{vs},values{vi},head{hea},exps{va}{}

	Expression* Expression::copy(){
		vector<string> vs=vector<string>{variables};
		vector<int> vi=vector<int>{values};
		AbsOperation* headcopy= head->copy();
		vector<AbsOperation*> expscopy=vector<AbsOperation*>{exps};
		Expression *ex= new Expression(vs,vi,headcopy,expscopy);
		return ex;
	}

	Expression::Expression(){
		vector<string> sv;
		vector<int> iv;
		vector<AbsOperation*> av;
		variables=sv;
		values=iv;
		head=nullptr;
		exps=av;
	}

	void Expression::unsetVar(string var){
		for(auto &it : variables){
			if(it==var){
				it.erase();		
			}
		}
	}

	int Expression::eval(){
	  int result;
		try{
			result= head->eval(&noValue,values,variables);
		}
		catch(NoValue &n){
		  cout << n.s << " has no value."<<endl;
			noValue="";
			return 0;
	
		}
		if(noValue!=""){
//			cout<<noValue << " has no value."<<endl;
//			noValue="";
//			return 0;
		}
		else{
			cout << result<<endl;
			return result;
		}
		return 0;
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
		

