#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>
#include "Shape.h"
#include "FrameBuffer.h"

using namespace std;

class People : public Shape {
	public:
		People();
		People(float , float, float);
		void setScale(float);
};

#endif
