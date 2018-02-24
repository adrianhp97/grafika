#include "People.h"

People::People(float x, float y, float r) : Shape(6){
	dots[0].setCoordinate(x-(r*10), y);
	dots[1].setCoordinate(x-(r*7.5), y-(r*7.5));
	dots[2].setCoordinate(x, y-(r*10));
	dots[3].setCoordinate(x+(r*7.5), y-(r*7.5));
	dots[4].setCoordinate(x+(r*10), y);
	dots[5].setCoordinate(x, y+(r*7.5));
	xCenter = x;
	yCenter = y;
	radius = r;
}

People::People() : People(0,0,1) {}

void People::setScale(float r) {
	dots[0].setCoordinate(xCenter-(r*10), yCenter);
	dots[1].setCoordinate(xCenter-(r*7.5), yCenter-(r*7.5));
	dots[2].setCoordinate(xCenter, yCenter-(r*10));
	dots[3].setCoordinate(xCenter+(r*7.5), yCenter-(r*7.5));
	dots[4].setCoordinate(xCenter+(r*10), yCenter);
	dots[5].setCoordinate(xCenter, yCenter+(r*7.5));
	radius = r;
}
