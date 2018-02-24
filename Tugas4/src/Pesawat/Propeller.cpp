#include "Propeller.h"

Propeller::Propeller(int x, int y, float r) : Shape(12){
  dots[0].setCoordinate(x-(r*3), y+(r*25));
  dots[1].setCoordinate(x+(r*3), y+(r*25));
  dots[2].setCoordinate(x+(r*3), y+(r*3));
  dots[3].setCoordinate(x+(r*25), y+(r*3));
  dots[4].setCoordinate(x+(r*25), y-(r*3));
  dots[5].setCoordinate(x+(r*3), y-(r*3));
  dots[6].setCoordinate(x+(r*3), y-(r*25));
  dots[7].setCoordinate(x-(r*3), y-(r*25));
  dots[8].setCoordinate(x-(r*3), y-(r*3));
  dots[9].setCoordinate(x-(r*25), y-(r*3));
  dots[10].setCoordinate(x-(r*25), y+(r*3));
  dots[11].setCoordinate(x-(r*3), y+(r*3));
  dots[0].setColor(50, 100, 100);
  xCenter = x;
  yCenter = y;
  radius = r;
}

Propeller::Propeller() : Propeller(0,0,1) {}
