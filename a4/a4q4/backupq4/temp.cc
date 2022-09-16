#include <vector>
#include <iostream>
using namespace std;



vector<vector<int*>> init(size_t n){
	vector<int*> row(2,nullptr);
	vector<vector<int*>> mat(n,row);
	for (size_t i=0;i<n;i++){
		for (size_t j=0;j<n;j++){
			int *newInt=new int(j+i);
			mat[i][j]=newInt;
		}
	}
	return mat;
}

int main(){
	vector<vector<int*>> mat=init(3);
	cout << *mat[1][1];
	int* j=new int(1);
	mat[1][1]=j;
	cout <<*mat[1][1];
}



