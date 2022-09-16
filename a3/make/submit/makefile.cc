#include "makefile.h"

using namespace std;


Target* Makefile::findTar(string s){
	for (int i=0; i<numTar; ++i){
		if(allTar[i]->name==s){
			return allTar[i];
		}
	}
	return nullptr;
}

Makefile::~Makefile(){
	for (int i=0 ;i<numTar; ++i){
		delete allTar[i];
	}
}

Makefile::Makefile(ostream &out):out{out},numTar{0}{}

void Makefile::changeTarget(const string &t){
	Target* tar=findTar(t);
	if (tar==nullptr){
		++clock;
		return;
	}

	tar->update(clock);
	clock++;
}


void Makefile::addDepend(const std::string &t, const std::string &d){
	Target* parent=findTar(t);
	Target* child=findTar(d);
//	cout << numTar;
	if ((parent==nullptr)&&(child==nullptr)){
		if (numTar>=19){
			cout << "Max targets exceeded"<<endl;
			return;
		}
		else{
			allTar[numTar]=new Target(t);
			allTar[numTar+1]=new Target(d);
			parent=allTar[numTar];
			child=allTar[numTar+1];
			numTar+=2;
			
		}
	}
	
	else if (parent==nullptr){
		if (numTar>=20){
			cout <<"Max targets exceeded"<<endl;
			return;
		}
		else{
			allTar[numTar]=new Target(t);
			parent=allTar[numTar];
			numTar++;
		}
	}
	else if (child==nullptr){
		if (numTar>=20){
			cout <<"Max targets exceeded"<<endl;
			return;
		}else{
			allTar[numTar]=new Target(d);
			child=allTar[numTar];
			numTar++;
		}
	}
	parent->addDepend(child);

}

void Makefile::rebuild(const std::string &t){
	Target* tar=findTar(t);
	if (tar!=nullptr){
		tar->build();
	}
}



