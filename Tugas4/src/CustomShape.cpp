#include "CustomShape.h"

CustomShape::CustomShape(float r, int n) : Shape(n){
  xCenter = 0;
  yCenter = 0;
  dots[0]->setColor(255, 255, 255);
  radius = r;
}

CustomShape::CustomShape() : CustomShape(1,3) {}

void CustomShape::setDotCoordinate(int i, float x, float y) {
  getDots()->at(i)->setCoordinate(x,y);
}
