#ifndef _SEPIA_H_
#define _SEPIA_H_
#include "image.h"
#include "decorator.h"
#include <string>
class Sepia: public Decorator{
	public:
	Sepia(Image* component);
	void render(PPM &ppm) override;
};

#endif
