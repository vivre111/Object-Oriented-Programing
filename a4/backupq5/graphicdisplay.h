#ifndef GRAPHICDISPLAY_H
#define GRAPHICDISPLAY_H
#include <iostream>
#include <vector>
#include "observer.h"
#include "state.h"
#include "subject.h"
#include "info.h"
#include "window.h"

class Cell;

class GraphicDisplay: public Observer<Info, State> {
	Xwindow* w;
	int numGrid=4;
 public:
  GraphicDisplay(Xwindow* w);
	void init(int n);
  void notify(Subject<Info, State> &whoNotified) override;
	~GraphicDisplay();
};
#endif
