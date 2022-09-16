#include "grid.h"
#include "textdisplay.h"
#include "cell.h"
#include "fallingBlock.h"
#include "fallenBlock.h"
#include "iblock.h"
#include "zblock.h"
using namespace std;

int main(){
	Grid g{Grid(10,10)};
	FallingBlock b{Zblock{1,&g}};
	TextDisplay t{TextDisplay{g,b}};
	t.draw();
	b.clockwise();
	t.draw();
	b.counterclockwise();
	t.draw();
	return 0;
}
