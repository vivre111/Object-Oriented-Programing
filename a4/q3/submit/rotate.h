#ifndef _ROTATE_H_
#define _ROTATE_H_
#include "image.h"
#include "decorator.h"
#include <string>
class Rotate: public Decorator{
	public:
	Rotate(Image* component);
	void render(PPM &ppm) override;
};

#endif
