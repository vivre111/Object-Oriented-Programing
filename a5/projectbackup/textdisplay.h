#ifndef _TEXTDISPLAY__H_
#define _TEXTDISPLAY__H_
class Grid;
class FallingBlock;
class TextDisplay{
	const Grid& g;
	const FallingBlock &fb;
	
	public:
	TextDisplay(const Grid &g, const FallingBlock &fb);
	void draw();


};


#endif
