#include "Wing.h"

Wing::Wing(int x, int y, float r) : Shape(3){
  dots[0]->setCoordinate(x, y+(r*25));
  dots[1]->setCoordinate(x+(r*200), y);
  dots[2]->setCoordinate(x-(r*200), y);
  dots[0]->setColor(255, 255, 100);
  xCenter = x;
  yCenter = y;
  radius = r;
}

Wing::Wing() : Wing(0,0,1) {}
