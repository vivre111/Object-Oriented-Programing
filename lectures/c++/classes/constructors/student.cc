#include <iostream>
using namespace std;




struct Student {
  int assigns, mt, final;
  float grade() {
    return assigns * 0.4 + mt * 0.2 + final * 0.4;
  }
	~Student(){
		cout << "delete";
	}
};


Student donothing(){
i//	Student *s=new Student;
	Student j;
//	delete j;
	return j;
}


int main () {
 // Student s {60, 70, 80};
	donothing();
//	Student *s= new Student;
//  cout << s.grade() << endl;
}
