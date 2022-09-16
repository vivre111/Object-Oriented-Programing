#include "variable.h"

using namespace std;

Variable::Variable(string varName,vector<int> vals,vector<string> vars):varName{varName},vals{vals},vars{vars}{}
Variable::~Variable(){}
int Variable::eval(string *noVal,std::vector<int> vals,std::vector<std::string> vars){
	int i=0;
	for (auto& it : vars){
		if (it==varName){
			return vals[i];
		}
		++i;
	}
//	if (*noVal!=""){
		*noVal=varName;
//	}
	return 0;
}
void	Variable::print(stringstream &ss,std::vector<int> vals,std::vector<std::string> vars){
		int ith=0;
		int found;
		for(auto &it :vars){


			if (it==varName){
				found=vals[ith];

				ss<<found;
				return;
			}
			ith++;
		}
		ss << varName;
	}


