#ifndef _FLIP_H_
#define _FLIP_H_
#include "image.h"
#include "decorator.h"
#include <string>
class Flip: public Decorator{
	public:
	Flip(Image* component);
	void render(PPM &ppm) override;
};

#endif
