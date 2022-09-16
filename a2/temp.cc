#include <iostream>
#include <string>
using namespace std;

int main()
{
	int strings;
	cout << "number of strings: ";
	cin >> strings;
	string* p = new string[strings];
	for(int i = 0; i < strings; i++)
	{
		cout << "string " << i << " info: ";
		cin >> p[i];
	}
        for(int i = 0; i < strings; i++)
        {
                cout << p[i] << endl;
        }
}
