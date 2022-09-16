#include <sstream>
#include <string>
#include <iostream>
using namespace std;

bool belong (string str, int argc, char *argv[]){
	for (int i=1; i<argc; ++i){
		if (str==argv[i]){
			return true;
		}
	}
	return false;
}




int main (int argc, char *argv[]){
	string in;
	int line=0;
	int wor=0;
	int c=0;
	while (getline(cin, in)){
		line++;
		stringstream ss(in);
		string word;
		while (ss>>word){
			wor++;
			char ch;
			stringstream sss(word);
			while (sss>>ch){
				c++;
			}
		}
	}
	c=c+wor-1;
	if (c<0){
		c=0;
	}

	if (argc==1){
		cout << line << "  " << wor << "  " << c;
	}
	else{
		stringstream ss;
		if (belong("-l",argc,argv)){
			ss << line;
			if (belong("-w",argc,argv)){
				ss << "  " << wor;
			}
			if (belong("-c",argc,argv)){
					ss <<"  " <<c;
				}
		}
		else if (belong("-w",argc,argv)){
			ss << wor;
			if (belong("-c",argc,argv)){
					ss <<"  " <<c;
			}
		else if (belong("-c",argc,argv)){
			ss << c;
		}

		}
			
		
		string temp;
		temp=ss.str();
		cout << temp;

	}
	cout << endl;
	
}




