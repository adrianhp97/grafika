#ifndef PLANE_H
#define PLANE_H

#include <iostream>
#include "Wheel.h"
#include "Propeller.h"
#include "Wing.h"

using namespace std;

class Plane {
	public:
		//ctor, cctor, dtor, operator=
		Plane();
		Plane(int);
		Plane(const Plane&);
		~Plane();
		Plane& operator=(const Plane&);

	protected:
    string name;
    Wheel rightWheel;
    Wheel leftWheel;
    Propeller rightPropeller;
    Propeller leftPropeller;
    Wing rightWing;
    Wing leftWing;
};

#endif