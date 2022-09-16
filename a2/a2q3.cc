#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void showerror(){
	cout << "Usage: wordWrap [-w width] [-l | -c | -r]"<<'\n';
	exit(1);
}

void leftP(stringstream &ss){
	string out;
	out=ss.str();
	cout <<out<< '\n';
}

string makeSpace(int n){
	stringstream ss;
	for (int i=0;i<n;i++){
		ss << " ";
	}
	string out = ss.str();
	return out;
}

void formatPrint(stringstream &ss, char location,int width){
	string out;
	out=ss.str();
	int strL=out.length();
	if (location == 'l'){
		cout <<out<< '\n';
	}
	if (location =='r'){
		int i= width-strL;
		string blank=makeSpace(i);
		cout << blank  << out<<'\n';		
	}
	if (location == 'c'){
		int i=(width-strL)/2;
		string blank=makeSpace(i);
		cout << blank << out << '\n';
	}
	
}

void overLength(string &s, int width, int &totalL, bool &first,stringstream &sss,char location){
	int j=0;
	int strLen=s.length();
	first=true;
	while (j < strLen){
		stringstream ss;
		for (int i=0;i<width;i++){
			
			ss << s.at(j);
			j=j+1;
			if (j>=strLen){
				first=false;
				string temp=ss.str();
				sss<<temp;
				break;
			}
		}
		if (first == true){
		formatPrint(ss,location,width);
		}
	}
	totalL= strLen%width;
	if (totalL==0){
		totalL=width;
	}
	
}

void readinput(int width,char format){
	string in;
	bool first=true;
	int totalL=0;
	int potentialL=0;
	stringstream ss;
	while (cin>>in){
		if (first==true){
			first=false;
			int strL=in.length();
			potentialL=strL;
			if (potentialL<= width){
				totalL=totalL+strL;
				ss<<in;
			}
			else{
				overLength(in,width,totalL,first,ss,format);

			}
		}
		else{
			int strL=in.length();
			potentialL=totalL+strL+1;
			if (potentialL<= width){
				totalL=totalL+strL+1;
				ss<<" " << in;
			}
			else{
				formatPrint(ss,format,width);
				
				totalL=0;
				potentialL=0;
				ss.str("");
				int strL=in.length();
				potentialL=totalL+strL;
				if (potentialL<= width){
					totalL=totalL+strL;
					ss<<in;
					first=false;
				}

				else{
					overLength(in,width,totalL,first,ss,format);
				}
			}
		}
	}
	formatPrint(ss,format,width);
}


void readArg(int argc, char *argv[], int &width, char &location){
	if (argc==1){
		width=25;
		location='l';
	}
	else if (argc==2){
		string s= argv[1];
		if (s=="-r"){
		location='r';
		}
		else if (s=="-l"){
		location='l';
		}
		else if (s=="-c"){
		location='c';
		}
		else{
		showerror();
		}
	}
	else if (argc==3){
		string w=argv[1];
		if ( w!= "-w"){
		showerror();
		}
		stringstream ss(argv[2]);
		ss >> width;
	}
	else if (argc==4){
		string w= argv[1];
		string l= argv[3];
		stringstream ss(argv[2]);
		ss >> width;
		
		if ( w!= "-w"){
		showerror();
		}
		if (l=="-r"){
		location='r';
		}
		else if (l=="-l"){
		location='l';
		}
		else if (l=="-c"){
		location='c';
		}
		else{
		showerror();
		}
	}	
}


int main (int argc, char *argv[]){
	int width=25;
	char location = 'l';
	readArg(argc, argv, width, location);
	readinput(width, location);
}
