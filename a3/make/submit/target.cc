#include "target.h"

using namespace std;



Target::Target(const string &name,ostream &out):name{name},out{out},numDependency{0},modified{0}{
	numUser=0;
}

bool Target::isLeaf() const{
	return (numDependency==0);
}



void Target::addDepend(Target *d){
	for (int i=0;i<numDependency;i++){
		if (dependency[i]==d){
			return;
		}
	}

	if (numDependency>=MaxDependency){
		out << "Max dependencies exceeded"<<endl;
		return;

	}
	numDependency++;
	dependency[numDependency-1]=d;
	d->user[d->numUser]=this;
	d->numUser++;

//	cout << name << numDependency;
//	cout << d->name << d->numUser;
}


void needModify(Target *tar){
	tar->modified=true;
	

  for (int i=0; i<tar->numUser;i++){
		needModify(tar->user[i]);
	}
}

void Target::update(int time){
	if (isLeaf()){
		modified=true;
		out << name <<" updated at time "<< time <<endl;
		for (int i=0; i<numUser;i++){
			needModify(user[i]);
		}

	}else{
		out << "Cannot update non-leaf object"<<endl;	
	}
}

int Target::lastUpdated() const{
	return modified;
}



void Target::build(){
	
	for(int i=0; i<numDependency;i++){
		dependency[i]->build();
		if (modified==true){
			modified=false;
			out << "Building " << name << endl;
		}
	}
}





