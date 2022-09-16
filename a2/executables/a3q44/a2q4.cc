#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

bool belong (string str, int argc, char *argv[]){
	for (int i=1; i<argc; ++i){
		if (str==argv[i]){
			return true;
		}
	}
	return false;
}
string fromFile(int argc, char *argv[]){
	for (int i=1;i<argc;i++){
		string arg=argv[i];
		if ((arg!="-l")&&(arg!="-w")&&(arg!="-c")){
			return arg;
		}
	}
	string emp= "";
	return emp;
}



int main (int argc, char *argv[]){
	string in;
	int line=0;
	int wor=0;
	int c=0;

	if (fromFile(argc,argv)==""){

		while (getline(cin, in)){
			line++;
			stringstream ss(in);
			string temp=ss.str();
			string word;
			while (ss>>word){
				wor++;
			}
			c=c+temp.length();	
		}
		c=c+line;
		if (argc==1){
			cout << line << "  " << wor << "  " << c<<"  "<< endl;
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
			}
			else if (belong("-c",argc,argv)){
				ss << c;
			}
	
			
			string temp;
			temp=ss.str();
			cout << temp << "  " << endl;
	
		}
	}else{
		ifstream myfile(fromFile(argc,argv));
		string file=fromFile(argc,argv);
		while (getline(myfile, in)){
		line++;
		

		stringstream ss(in);
		string temp=ss.str();
		string word;
		while (ss>>word){
			wor++;
		}
		c=c+temp.length();	
		}
		c=c+line;
		if (argc==2){
			cout << line << "  " << wor << "  " << c<<"  "<< file<<"  " << endl;
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
			}
			else if (belong("-c",argc,argv)){
				ss << c;
			}
	
			
			string temp;
			temp=ss.str();
			cout << temp << "  " << file<<"  "<<endl;
	
		}
	}
	
}




