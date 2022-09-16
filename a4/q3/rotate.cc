#include "rotate.h"
#include <iostream>
using namespace std;

Rotate::Rotate(Image* component):Decorator{component}{
}


void Rotate::render(PPM &ppm){
	component->render(ppm);
	int w=ppm.getWidth();
	int h=ppm.getHeight();
	vector<Pixel> newPixel;
	vector<Pixel> pixels=ppm.getPixels();
	for (int i=0;i<w;i++){
		for (int j=0;j<h;j++){
			newPixel.emplace_back (pixels[w * (h - j - 1) + i]);
		}
	}
	
	ppm.getPixels()=newPixel;
	ppm.getWidth()=h;
	ppm.getHeight()=w;
	

}
