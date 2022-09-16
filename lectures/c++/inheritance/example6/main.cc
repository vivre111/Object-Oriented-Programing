#include <iostream>
#include <string>
#include "book.h"
#include "text.h"
#include "comic.h"

using namespace std;

int main() {
  Comic c("Robin Rescues Batman Twice", "Robin", 40, "Robin");

	Book* d=c.copy();
	cout << d->isHeavy();
	
}
