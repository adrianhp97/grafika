#include "Wheel.h"

Wheel::Wheel(int x, int y, float r) : Shape(16){
  dots[0].setCoordinate(x-(r*2), y-(r*10));
  dots[1].setCoordinate(x+(r*2), y-(r*10));
  dots[2].setCoordinate(x+(r*2), y-(r*1));
  dots[3].setCoordinate(x+(r*5), y-(r*1));
  dots[4].setCoordinate(x+(r*5), y-(r*6));
  dots[5].setCoordinate(x+(r*10), y-(r*6));
  dots[6].setCoordinate(x+(r*10), y+(r*6));
  dots[7].setCoordinate(x+(r*5), y+(r*6));
  dots[8].setCoordinate(x+(r*5), y+(r*1));

  dots[9].setCoordinate(x-(r*5), y+(r*1));
  dots[10].setCoordinate(x-(r*5), y+(r*6));
  dots[11].setCoordinate(x-(r*10), y+(r*6));
  dots[12].setCoordinate(x-(r*10), y-(r*6));
  dots[13].setCoordinate(x-(r*5), y-(r*6));
  dots[14].setCoordinate(x-(r*5), y-(r*1));
  dots[15].setCoordinate(x-(r*2), y-(r*1));

  dots[0].setColor(150, 100, 190);
  xCenter = x;
  yCenter = y;
  radius = r;
}
