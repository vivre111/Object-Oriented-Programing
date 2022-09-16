#include <string>
#include <sstream>
#include <iostream>
#include "aha.h"
using namespace std;
int gcd(int u, int v){
    return (v != 0) ? gcd(v, u % v) : u;
}


	void Rational::simplify(){
		if (num!=0){
			int g=gcd(num,den);		
			num=num/g;
			den=den/g;
	  }
		else{
			den=0;
		}


		if (den<0){
			den=-den;
			num=-num;
		}
		
	}


  Rational::Rational(int num, int den):num{num},den{den} {}	
	

	Rational Rational::operator+(const Rational &rhs) const{
		Rational result{den*rhs.num+rhs.den*num,den*rhs.den};
		result.simplify();
		return result;
	}
  Rational Rational::operator-(const Rational &rhs) const{
		Rational result{-den*rhs.num+rhs.den*num,den*rhs.den};
		result.simplify();
		return result;
	}

  Rational Rational::operator*(const Rational &rhs) const{
		Rational result{rhs.num*num,den*rhs.den};
		result.simplify();
		return result;
	}
  Rational Rational::operator/(const Rational &rhs) const{
		Rational result{num*rhs.den,den*rhs.num};
		result.simplify();
		return result;
	}
  Rational& Rational::operator+=(const Rational &rhs){
		num=den*rhs.num+rhs.den*num;
		den=den*rhs.den;
		simplify();
		return *this;

	}
  Rational& Rational::operator-=(const Rational &rhs){
		num=-den*rhs.num+rhs.den*num;
		den=den*rhs.den;
		simplify();
		return *this;

	}

  Rational Rational::operator-() const{
		Rational r(-num,den);
		return r;
	}

	int Rational::getNumerator() const{
		return num;
	}
  int Rational::getDenominator() const{
		return den;
	}
  bool Rational::isZero() const{
		return num==0;
	}  






istream &operator>>(std::istream &in, Rational &rat){
	string line;
	getline(cin,line);
	int index=line.find('/');
	int size=line.size();
	string snum=line.substr(0,index);
	string sden=line.substr(index+1, size-index);
	stringstream ss{""};
	int num;
	int den;
	ss.str(snum);
	ss >> num;
//	ss.str("");
	ss.clear();
//	cout << snum << sden;
	ss.str(sden);
	ss >> den;
	rat.num=num;
	rat.den=den;
	rat.simplify();
	return in;
}

std::ostream &operator<<(std::ostream &out, const Rational &rat){
	// what if result = 1 or 0
	if (rat.num==0){
		out << '0' ;
	}
	else if(rat.den==1){
		out << rat.num;
	}
	else{
	out << rat.num << '/'  << rat.den;
	}
	return out;
}

