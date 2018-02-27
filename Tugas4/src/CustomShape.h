#ifndef CUSTOMSHAPE_H
#define CUSTOMSHAPE_H

#include <iostream>
#include "Shape.h"

using namespace std;

class CustomShape : public Shape {
	public:
		//ctor, cctor, dtor, operator=
		CustomShape();
		CustomShape(float,int);
    void setDotCoordinate(int, float, float);
		//Pilot(int);
		//Pilot(const Pilot&);
		//~Pilot();
		//Pilot& operator=(const Pilot&);
};

#endif
