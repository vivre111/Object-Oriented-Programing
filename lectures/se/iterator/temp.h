

class List{
		class Node;
		Node *theList=nullptr;

		public:
		class Iterator{
			Node* p;
			Iterator(Node* p);


			int &operator*();
			Iterator &operator++();
			bool &operator!=(const Iterator& other);
		};
};
