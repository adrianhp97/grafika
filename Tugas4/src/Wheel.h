#include <iostream>
#include "Circle.h"

using namespace std;

#ifndef WHEEL_H
#define WHEEL_H

class Wheel : public Circle{
	public:
		//ctor, cctor, dtor, operator=
		Wheel();
		Wheel(int);
		Wheel(const Wheel&);
		~Wheel();
		Wheels& operator=(const Wheel&);

	protected:
    String name;
};

#endif