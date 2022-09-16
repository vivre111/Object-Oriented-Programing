#include <iostream>
using namespace std;

struct Node {
   int data;
  Node *next;
  Node(int data, Node *next) {
  	this.data=data;
	this.next=next;
  }

  Node(const Node &n): data {n.data}, next {n.next} {}
};

ostream &operator<<(ostream &out, const Node &n) {
  out << n.data;
  if (n.next) {
    out << ",";
    out << *(n.next);
  }
  return out;
}

int main() {
 dsf 
	Node c(2,nullptr);
	cout << c;
}
