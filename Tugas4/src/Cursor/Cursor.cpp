#include "Cursor.h"

Cursor::Cursor() : Shape(4) {

}

Cursor::Cursor(int x, int y, float r) : Shape(4) {
  dots[0]->setCoordinate(x-(r*8), y-(r*2));
  dots[1]->setCoordinate(x+(r*8), y-(r*2));
  dots[2]->setCoordinate(x+(r*8), y+(r*2));
  dots[3]->setCoordinate(x-(r*8), y+(r*2));
/*    dots[4]->setCoordinate(x-(r*8), y-(r*8.1));
    dots[5]->setCoordinate(x-(r*4.1), y-(r*8.1));
    dots[6]->setCoordinate(x-(r*4.1), y-(r*12));
    dots[7]->setCoordinate(x-(r*4), y-(r*12));
    dots[8]->setCoordinate(x-(r*4), y-(r*8.1));
    dots[9]->setCoordinate(x-(r*0), y-(r*8.1));
    dots[10]->setCoordinate(x-(r*0), y-(r*8));
    dots[11]->setCoordinate(x-(r*4), y-(r*8));
*/  dots[0]->setColor(100,100,100);
    

    xCenter = x;
    yCenter = y;
    radius = r;
}