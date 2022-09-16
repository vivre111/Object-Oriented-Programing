#include "node.h"
#include <iostream>

using namespace std;

void attachNode(Node **headArray, int head, int index, int data){
	if (index==0){
		Node* oldRoot=headArray[head];
		Node* newRoot=new Node(data,oldRoot);
		headArray[head]=newRoot;
	}
	else{
		Node* parent=headArray[head];
		for (int i=0; i<index; i++){
			parent=parent->next;
		}
		Node* child=new Node(data,parent);
		child->owns=false;

		for (int i=0; ;i++){
			if (headArray[i]==nullptr){
				headArray[i]=child;
				break;
			}
		}
	}
}

void printNodes(std::ostream &out, Node **headArray, int head){
	Node* n= headArray[head];
	while (n->next){
		out << n->data<<" ";
		n=n->next;
	}
	out << n->data  << endl;
}

void mutateNode(Node **headArray, int head, int index, int newValue){
	Node* start=headArray[head];
	for(int i=0;i<index;i++){
		start=start->next;
	}
	start->data=newValue;
}




void freeLists(Node **headArray){
	for (int i=0; i<10 ; i++){
		Node* n=headArray[i];
		while(n!=nullptr && n->owns){
			Node* temp=n;
			n=n->next;
			delete temp;
		}
		delete n;
	}			
}



