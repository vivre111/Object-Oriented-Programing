#include <iostream>
#include "node.h"
using namespace std;

int main () {
   Node n{1, new Node{2, new Node{3, nullptr}}};

   Node m{4, new Node{5,new Node {6,nullptr}}};
   *m.next=n;
   Node z{m};

   cout << n << endl;
   cout << m << endl;
   cout << z << endl;
   cout << endl;

   n.next->next->data = 7;
   m.next->next->data = 8;
   cout << n << endl;
   cout << m << endl;

}

