#include "flip.h"
#include <iostream>
using namespace std;

Flip::Flip(Image* component):Decorator{component}{
}


void Flip::render(PPM &ppm){
	component->render(ppm);
	int w=ppm.getWidth();
	int h=ppm.getHeight();
	vector<Pixel> newPixel;
	vector<Pixel> pixels=ppm.getPixels();
	for (int r=0;r<h;r++){
		for (int c=0;c<w;c++){
			newPixel.emplace_back (pixels[ (r*w)+w-c-1  ]);
		}
	}
	
	ppm.getPixels()=newPixel;
	ppm.getWidth()=w;
	ppm.getHeight()=h;
	

}
