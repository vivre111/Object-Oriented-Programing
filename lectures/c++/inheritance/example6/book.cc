#include <string>
#include "book.h"

using std::string;

Book::Book(const string &title, const string &author, int length):
  title{title}, author{author}, length{length} {}

Book* Book::copy(){
	Book* b=new Book("","",0);	
	return b;
}

int Book::getLength() const { return length; }
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
bool Book::isHeavy() const { return length > 200; }
