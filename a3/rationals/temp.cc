#include <string>
#include <sstream>
#include <iostream>
using namespace std;
int gcd(int u, int v){
    return (v != 0) ? gcd(v, u % v) : u;
}

	int getNumerator() const{
		return num;
	}
  int getDenominator() const{
		return den;
	}
  bool isZero() const{
		return num==0;
	}  
	void simplify(){
		if (! isZero()){
			int g=gcd(num,den);		
			num=num/g;
			den=den/g;
	  }
		else{
			den=1;
		}

		if (den<0){
			den=-den;
			num=-num;
		}
		
	}

	Rational operator+(const Rational &rhs) const{
		Rational result{den*rhs.num+rhs.den*num,den*rhs.den};
		result.simplify();
		return result;
	}
  Rational operator-(const Rational &rhs) const{
		Rational result{-den*rhs.num+rhs.den*num,den*rhs.den};
		result.simplify();
		return result;
	}

  Rational operator*(const Rational &rhs) const{
		Rational result{rhs.num*num,den*rhs.den};
		result.simplify();
		return result;
	}
  Rational operator/(const Rational &rhs) const{
		Rational result{num*rhs.den,den*rhs.num};
		result.simplify();
		return result;
	}

};




istream &operator>>(std::istream &in, Rational &rat){
	char c;
	stringstream ss;
	while (c!='/'){
		in >> c;
		ss<<c;
	}
  int i;
	ss >>i;
	rat.num=i;
	string temp;
	in >> temp;
	ss.str(temp);
	ss >> i;
	rat.den=i;
	rat.simplify();
	return in;
}

std::ostream &operator<<(std::ostream &out, const Rational &rat){
	// what if result = 1 or 0
	if (rat.isZero()){
		cout << '0' << endl;
	}
	else if(rat.den==1){
		cout << rat.num << endl;
	}
	cout << rat.num << '/'  << rat.den << endl;
	return out;
}

int main(){
	Rational p;
  Rational q{2,19};
	cout << q;
	cin >> p;
	cout << p;
	cout << q-p; 

}

