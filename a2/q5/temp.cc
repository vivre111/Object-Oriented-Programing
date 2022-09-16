#include<string>
#include<iostream>
#include<sstream>

using namespace std;

struct BinaryNum {
  int size;         // number of elements the array currently holds
  int capacity;     // number of elements the array could hold,
                    // given current memory allocation to contents
  bool *contents;   // (pointer to) heap-allocated array of bools
	int getSize()const{
		return size;
	}

};

int power(int n, int power){
	int result=1;
	for (int i=0; i<power; i++){
		result=result*n;
	}
	return result;
}

int charToInt(char c){
	stringstream ss;
	ss << c;
	int i;
	ss >> i;
	return i;
}

int findCapacity(int len){
	int ca=4;
	while (ca<len){
		ca=ca*2;
	}
	return ca;
}

BinaryNum readBinaryNum(){
	char c;
	int capacity=4;
	stringstream ss;
	
	while (cin >> c){
		if (c!='1' && c!='0'){
			break;
		}
		ss << c;
	}
	string in=ss.str();
	int length=in.length();
	
	capacity = findCapacity(length);
	bool *con=new bool[capacity];

	for (int i=0; i<length; i++){
		int val= charToInt(in[i]);
		con[i]=val;
	}
	
	BinaryNum b{length,capacity,con};
	return b;	
}
void binaryConcat(BinaryNum &binNum){
	stringstream ss;
	for (int i=0; i<binNum.size;i++){
		ss << binNum.contents[i];
	}
	char c;
	while (cin >> c){
		if (c!='1' && c!='0'){
			break;
		}
		ss << c;
	}
	string in=ss.str();
	int length=in.length();
	delete binNum.contents;

	int capacity=findCapacity(length);
	bool *con=new bool[capacity];
	for (int i=0; i<length; i++){
		int val= charToInt(in[i]);
		con[i]=val;
	}
	binNum.contents=con;
	binNum.size=length;
	

}
int binaryToDecimal(const BinaryNum &binNum){
	int len=binNum.size;
	int dec=0;
	for (int i=0;i<len;i++){
		dec=dec+power(2,len-i-1 )*binNum.contents[i];
	}
	return dec;
}


void printBinaryNum(std::ostream &out, const BinaryNum &binNum, char sep){
	int size=binNum.size;
	stringstream ss;
	for (int i=0; i<size-1;i++){
		ss << binNum.contents[i] << sep;	
	}
	ss << binNum.contents[size-1];
	string temp;
	temp=ss.str();
	cout << temp;

}
BinaryNum &operator<<(BinaryNum &binNum, int num){
	stringstream ss;
	int oLen=binNum.size;
	for (int i=0; i<oLen;i++){
		ss << binNum.contents[i];
	}
	string s=ss.str();
	int nLen=binNum.size+num;
	int capacity=findCapacity(nLen);
	bool *con=new bool[capacity];
	for (int i=0; i<oLen; i++){
		int val= charToInt(s.at(i));
		con[i]=val;
	}
	for (int i=oLen; i<nLen; i++){
		con[i]=0;
	}
	delete(binNum.contents);
	binNum.contents=con;
	binNum.size=nLen;
	binNum.capacity=capacity;

	
	return binNum;

}


