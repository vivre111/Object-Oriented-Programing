#include <iostream>
#include "rational.h"
#include "polynomial.h"
#include <sstream>
#include <string>

using namespace std;



Polynomial::Polynomial(){
	coeffs = new Rational[10];
	capacity=10;
}


Polynomial::~Polynomial(){
	//delete[] coeffs;
//	cout << "delete ctor"<<endl;
}

Polynomial::Polynomial(const Polynomial &other){
	capacity=other.capacity;
	coeffs=new Rational[capacity];
	for (int i=0; i<capacity; i++){
		coeffs[i]=Rational(other.coeffs[i].num,other.coeffs[i].den);
		}
	//cout << "copy ctor"<<endl;
	}


Polynomial::Polynomial(Polynomial &&other):coeffs{other.coeffs},capacity{other.capacity}{
	other.coeffs=nullptr;
	//cout << "move ctor"<<endl;
}

Polynomial &Polynomial::operator=(const Polynomial &other){
	Polynomial p(other);
	swap(p.coeffs,coeffs);
	swap(p.capacity,capacity);
	//cout << "copy ass"<<endl;
	return *this;
}

//returns quotient after long division
 


Polynomial &Polynomial::operator=(Polynomial &&other){
 	swap(other.coeffs,coeffs);
	swap(other.capacity,capacity);

//	cout << "move ass"<<endl;
	return *this;
}


int Polynomial::degree() const{
	int i;
	for(i=capacity-1;i>=0;i--){
		if (!coeffs[i].isZero()){
			break;
		}
	}
	return i;
}

Polynomial Polynomial::operator+(const Polynomial &rhs) const{
	int max;
	int second;
	Polynomial temp;
	if (degree()>rhs.degree()){
		temp=*this;
		max=degree();
		second=rhs.degree();
	}
	else{
		temp=rhs;
		max=rhs.degree();
		second=degree();
	}
	for (int i = 0;i<=second; i++){
		temp.coeffs[i]=coeffs[i]+rhs.coeffs[i];
	}
	
	if (degree()>rhs.degree()){
		for (int i=second+1; i<=max; i++){
			temp.coeffs[i]=coeffs[i];
		}
	}
	else{
			for (int i=second+1; i<=max; i++){
			temp.coeffs[i]=rhs.coeffs[i];
		}
	}
	return temp;
}
//Polynomial operator-(const Polynomial &rhs) const;
//Polynomial operator*(const Polynomial &rhs) const;

Polynomial Polynomial::operator-(const Polynomial &rhs) const{
	int max;
	int second;
	Polynomial temp;
	if (degree()>rhs.degree()){
		temp=*this;
		max=degree();
		second=rhs.degree();
	}
	else{
		temp=rhs;
		max=rhs.degree();
		second=degree();
	}
	for (int i = 0;i<=second; i++){
		temp.coeffs[i]=coeffs[i]-rhs.coeffs[i];
	}
	
	if (degree()>rhs.degree()){
		for (int i=second+1; i<=max; i++){
			temp.coeffs[i]=coeffs[i];
		}
	}
	else{
			for (int i=second+1; i<=max; i++){
			temp.coeffs[i]=-rhs.coeffs[i];
		}
	}
	return temp;
}



Polynomial Polynomial::operator*(const Polynomial &rhs) const{
	int max= degree()+rhs.degree()+10;
	Polynomial temp;
	Rational *r=new Rational[max];
	swap(temp.coeffs, r);
	temp.capacity=max;
	delete[] r;

	for (int i=0; i<=degree(); i++){
		for (int j=0; j<=rhs.degree(); j++){
			temp.coeffs[i+j]+=coeffs[i]*rhs.coeffs[j];
		}
	}
	return temp;
}

Polynomial Polynomial::operator/(const Polynomial &rhs) const{
	int max= degree()-rhs.degree();
	if (max<0){
		Polynomial p;
		return p;
	}
	Polynomial cp{*this};
	Polynomial temp;
	temp.capacity=max+5;
	Rational* r= new Rational[max+5];
	swap(temp.coeffs,r);
	delete[] r;

	while(true){
		int deg=cp.degree();
		int rhsDeg=rhs.degree();
		int power=deg-rhsDeg;
		if (power<0){
			return temp;
		}

		Rational coe=cp.coeffs[deg]/rhs.coeffs[rhsDeg];
		temp.coeffs[power]=coe;
		cp=*this-temp*rhs;
//		cout << temp<<"and"<<cp;
	}

} 

//returns remainder after long division
Polynomial Polynomial::operator%(const Polynomial &rhs) const{
	Polynomial p=(*this-((*this/rhs)*rhs));
	return p;
}


ostream& operator<<(std::ostream& out, const Polynomial &poly){
	bool start= true;
	bool isZer=true;
	for (int i=poly.capacity-1; i>=0; --i){
		if (!poly.coeffs[i].isZero()){
			isZer=false;
			if (start){
				start=false;
			}
			else{
				out<<" + "; 
			}
			if(i==1){
				out <<"(" <<poly.coeffs[i] <<")"<<"x";
				continue;
			}
			if (i==0){
					out <<"(" <<poly.coeffs[i] <<")";
					continue;
			}
			out <<"(" <<poly.coeffs[i] <<")"<<"x^"<<i;
		}
	}
	if (isZer){
		out << "0";
	}
	return out;
}

void resizePoly(Polynomial &poly, int newCap){
	Polynomial temp;
	Rational *r= new Rational[newCap];
	swap(r, poly.coeffs);


	for (int i=0;i<poly.capacity; i++){
		swap(r[i],poly.coeffs[i]);
		cout << r[i];
		cout << poly.coeffs[i];
	}

	
	
  delete[](r);
	
	poly.coeffs[1].num=2;
	cout << poly;
}


istream& operator>>(istream& in,Polynomial &poly){
	Polynomial temp;
	string sline;
	getline(cin,sline);
	stringstream line(sline);
	Rational rat;
	int power;

	line >> rat;
	line >> power;
	if (power>=temp.capacity-1){
		temp.capacity=power+10;
		Rational *r= new Rational[temp.capacity];
		swap(r, temp.coeffs);
		delete[](r);
	}

	temp.coeffs[power]=rat;

	while (line >> rat){
		line >> power;
		temp.coeffs[power]=rat;
	}
	poly=temp;
  return in;

}
