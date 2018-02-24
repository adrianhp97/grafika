#include "Pilot.h"

Pilot::Pilot(int x, int y, float r) : Shape(4){
  dots[0]->setCoordinate(x, y-(r*50));
  dots[1]->setCoordinate(x+(r*65), y);
  dots[2]->setCoordinate(x, y+(r*50));
  dots[3]->setCoordinate(x-(r*65), y);
  dots[0]->setColor(255, 50, 50);
  xCenter = x;
  yCenter = y;
  radius = r;
}

Pilot::Pilot() : Pilot(0,0,1) {}