#include <iostream>
#include "Wheel.h"
#include "Wing.h"
#include "Propeller.h"

using namespace std;

#ifndef PLANE_H
#define PLANE_H

class Plane {
	public:
		//ctor, cctor, dtor, operator=
		Plane();
		Plane(int);
		Plane(const Plane&);
		~Plane();
		Plane& operator=(const Plane&);

	protected:
    String name;
    Wheel rightWheel;
    Wheel leftWheel;
    Propeller rightPropeller;
    Propeller leftPropeller;
    Wing rightWing;
    Wing leftWing;
};

#endif