#ifndef PLANE_H
#define PLANE_H

#include <iostream>
#include "Pesawat/Pilot.h"
#include "Pesawat/Wheel.h"
#include "Pesawat/Propeller.h"
#include "Pesawat/Wing.h"
#include "FrameBuffer.h"
#include "People.h"

using namespace std;

class Plane {
	public:
		//ctor, cctor, dtor, operator=
		Plane(int, int, float);
		~Plane();
		/*Plane(int);
		Plane(const Plane&);
		Plane& operator=(const Plane&);*/
		void draw(FrameBuffer*);
		void detachWheel();
		void animateWheel(FrameBuffer*, Wheel*);
		void drawPeople(FrameBuffer*, People*);

	protected:
		int x;
		int y;
		float size;
		Pilot* pilot;
		Wing* wing;
		Propeller* rightPropeller;
		Propeller* leftPropeller;
		Wheel* rightWheel;
    Wheel* leftWheel;
		People* people;
		bool wheelDetached;
		int animationState;

};

#endif
