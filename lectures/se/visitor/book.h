#ifndef _BOOK_H_
#define _BOOK_H_
#include <string>

#include "BookVisitor.h"

class Book {
  std::string title, author;
  int length;
 protected:
  int getLength() const;
 public:
  Book(const std::string &title, const std::string &author, int length);
  std::string getTitle() const;
  std::string getAuthor() const;
  virtual bool isHeavy() const;

  virtual bool favourite() const;

  virtual void accept(BookVisitor &v);

  virtual ~Book();
};

#endif
