#ifndef _DECORATOR__H_
#define _DECORATOR__H_

#include "image.h"


class Decorator: public Image{
	protected:
	Image *component;
	public:
	Decorator(Image* im);
	virtual void render(PPM &ppm)=0;
	virtual ~Decorator();
	
};

#endif

