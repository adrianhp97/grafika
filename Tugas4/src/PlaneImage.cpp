#include "PlaneImage.h"

PlaneImage::PlaneImage(int x, int y, float size) : Image(x,y,size) {
  addShape(new Wing(),0,0);
  addShape(new Propeller(),(size*100),(size*5));
  addShape(new Propeller(),0-(size*100),(size*5));
  addShape(new Wheel(),(size*40),(size*31));
  addShape(new Wheel(),0-(size*40),(size*31));
  addShape(new People(0,0,size*2),0-(size*100),0-(size*32));
  addShape(new Pilot(),0,0);
}

PlaneImage::~PlaneImage() {
  for(unsigned int i = 0; i < shapes.size(); i++) {
    delete shapes.at(i);
  }
}
