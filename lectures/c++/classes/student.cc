#include <iostream>
using namespace std;

struct Student {
  const int id;
  int assigns, mt, final;
  float grade();
  Student(int id_, int assigns_, int mt_,int final_):id{id_}, assigns{assigns_}, mt{mt_}, final {final_}{
//	this.id=id;
	}
  };





float Student::grade() {
  return assigns * 0.4 + mt * 0.2 + final * 0.4;
}

int main () {
  Student s {101,60, 70, 80};
  Student d{s};
  Student *arr[10];
	Student **heap=new Student*[10];
  cout << d.id << endl;
  cout << s.grade() << endl;
}
