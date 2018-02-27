#include "ItbMapImage.h"

ItbMapImage::ItbMapImage(vector<CustomShape*>& shape,float x, float y, float size): Image(x,y,size) {
  for(int i=0; i<shape.size();i++){
    addShape(shape.at(i),0,0);
  }
}

ItbMapImage::~ItbMapImage(){
  for(unsigned int i = 0; i < shapes.size(); i++) {
    delete shapes.at(i);
  }
}
