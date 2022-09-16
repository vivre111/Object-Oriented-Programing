#include "sepia.h"
#include <iostream>
using namespace std;

Sepia::Sepia(Image* component):Decorator{component}{
}


//np.r = p.r *.393 + p.g * .769 + p.b * .189
//np.g = p.r *.349 + p.g * .686 + p.b * .168
//np.b = p.r *.272 + p.g * .534 + p.b * .131

void Sepia::render(PPM &ppm){
	component->render(ppm);
	int w=ppm.getWidth();
	int h=ppm.getHeight();
	vector<Pixel> newPixel;
	vector<Pixel> pixels=ppm.getPixels();
	for (int i=0;i<h*w;i++){
			unsigned int r= pixels[i].r;
			unsigned int g= pixels[i].g;
			unsigned int b= pixels[i].b;
			unsigned int newr=r*0.393+g*0.769+b*0.189;
			unsigned int newg=r*0.349+g*0.686+b*0.168;
			unsigned int newb=r*0.272+g*0.534+b*0.131;
			if (newr>255){newr=255;}
			if (newb>255){newb=255;}
			if (newg>255){newg=255;}


			Pixel newP=Pixel{newr,newg,newb};
			newPixel.emplace_back (newP);
		}
	
	
	ppm.getPixels()=newPixel;
	ppm.getWidth()=w;
	ppm.getHeight()=h;
	

}
