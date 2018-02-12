#ifndef PILOT_H
#define PILOT_H

#include <iostream>
#include "../Shape.h"

using namespace std;

class Pilot : public Shape {
	public:
		//ctor, cctor, dtor, operator=
		Pilot(int , int, float);
		//Pilot(int);
		//Pilot(const Pilot&);
		//~Pilot();
		//Pilot& operator=(const Pilot&);
		int getCenterX();
    int getCenterY();
    int getRadius();
};

#endif
