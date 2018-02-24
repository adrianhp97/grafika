#ifndef WHEEL_H
#define WHEEL_H

#include <iostream>
#include "../Shape.h"

using namespace std;

class Wheel : public Shape {
	public:
		//ctor, cctor, dtor, operator=
		Wheel();
		Wheel(int, int, float);
};

#endif
