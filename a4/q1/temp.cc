#include <vector>
#include <string>
#include <iostream>
using namespace std;
struct B{
	int a;
};
struct s{
	vector<string> *st;
	vector<int> in;
	
};



int main(){
	vector<int> i;
	vector<int>* j=&i;
	i.emplace_back(2);
	cout <<*j[0];
}
