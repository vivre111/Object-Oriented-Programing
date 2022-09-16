#ifndef _BOOK_H_
#define _BOOK_H_
#include <string>

class Book {
  public:
	std::string title, author;
  int length;
  int getLength() const;
  Book(const std::string &title, const std::string &author, int length);
  std::string getTitle() const;
  std::string getAuthor() const;
	virtual Book* copy();
  virtual bool isHeavy() const;
};

#endif
