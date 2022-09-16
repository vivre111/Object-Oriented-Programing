#include <vector>
#include <iostream>

using namespace std;

int main(){
vector<int> arr(3,3);
vector<int>::iterator it;
it=arr.begin();
it++;
cout <<arr[0];
arr.erase(it);
for(auto &it: arr){
	cout << it;
}
}


