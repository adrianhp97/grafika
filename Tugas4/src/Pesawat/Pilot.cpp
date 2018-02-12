#include "Pilot.h"

Pilot::Pilot(int x, int y, float r) : Shape(4){
  dots[0].setCoordinate(x, y-(r*125));
  dots[1].setCoordinate(x+(r*100), y);
  dots[2].setCoordinate(x, y+(r*75));
  dots[3].setCoordinate(x-(r*100), y);
  xCenter = x;
  yCenter = y;
  radius = r;
}

int Pilot::getCenterX(){
  return xCenter;
}

int Pilot::getCenterY(){
  return yCenter;
}

int Pilot::getRadius(){
  return radius;
}
