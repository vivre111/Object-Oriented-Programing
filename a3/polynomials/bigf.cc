#include <iostream>
#include "rational.h"
#include <sstream>
#include <string>
#include <utility>

using namespace std;


struct Polynomial {
    Rational *coeffs; // heap allocated array
    int capacity;     // size of allocated array

  


Polynomial(){
	coeffs = new Rational[10];
	capacity=10;
}


~Polynomial(){
	delete[] coeffs;
}

Polynomial(const Polynomial &other){
	capacity=other.capacity;
	coeffs=new Rational[capacity];
	for (int i=0; i<capacity; i++){
		coeffs[i]=Rational(other.coeffs[i].num,other.coeffs[i].den);
		}
	cout << "copy ctor"<<endl;
	}

Polynomial(Polynomial &&other):coeffs{other.coeffs},capacity{other.capacity}{
	other.coeffs=nullptr;
	cout << "move ctor"<<endl;
}

Polynomial &operator=(const Polynomial &other){
	Polynomial p(other);
	swap(p.coeffs,coeffs);
	swap(p.capacity,capacity);
	cout << "copy ass"<<endl;
	return *this;
}

Polynomial &operator=(Polynomial &&other){
 	swap(other.coeffs,coeffs);
	swap(other.capacity,capacity);

	cout << "move ass"<<endl;
	return *this;
}

};




ostream& operator<<(std::ostream& out, const Polynomial &poly){
	bool start= true;
	for (int i=poly.capacity-1; i>=0; --i){
		if (!poly.coeffs[i].isZero()){
			if (start){
				start=false;
			}
			else{
				out<<" + "; 
			}

			out <<"(" <<poly.coeffs[i] <<")"<<"x^"<<i;
		}
	}
	return out;
}


istream& operator>>(istream& in,Polynomial &poly){
	string sline;
	getline(cin,sline);
	stringstream line(sline);
	Rational rat;
	int power;

	line >> rat;
	line >> power;
	poly.coeffs[power]=rat;
	if (power>=poly.capacity){
		//resize
	}


	while (line >> rat){
		line >> power;
		poly.coeffs[power]=rat;
	}
  return in;
}


Polynomial donothing(Polynomial p){
	return p;
}


int main() {
	Polynomial p;
	cin >> p;
	//Polynomial q(p);
	Polynomial q;
	q=donothing (p);
  p=q;

//	p=q;
  cout <<p <<endl<< q <<endl;
}
