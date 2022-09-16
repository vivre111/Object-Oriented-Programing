

#include "target.h"
using namespace std;

int main(){
	string s{"1"};
	string s2{"2"};
	Target tar=Target(s);
	Target tar2=Target(s2);
	cout<<tar2.isLeaf(); 
	tar2.addDepend(&tar);
	cout <<tar2.isLeaf();
}

