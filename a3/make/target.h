#ifndef _TARGET_H_
#define _TARGET_H_
#include <iostream>
#include <string>

const int maxDepends = 10;

struct Target {  // You may add fields and methods as you see fit
  std::ostream &out;  // Stream where Target will print its output
  std::string name;
	//start
	int numDependency;
	bool modified;
	Target *dependency[10];
	const int MaxDependency=10;	
	int numUser;
	Target *user[20];
	
	
  Target(const std::string &name, std::ostream &out = std::cout);
  bool isLeaf() const;
  void addDepend(Target *d);
  void update(int time);
  int lastUpdated() const;
  void build();
};

#endif
