#ifndef WHEEL_H
#define WHEEL_H

#include <iostream>
#include "Circle.h"

using namespace std;

class Wheel : public Circle{
	public:
		//ctor, cctor, dtor, operator=
		Wheel();
		Wheel(int);
		Wheel(const Wheel&);
		~Wheel();
		Wheel& operator=(const Wheel&);

	protected:
    string name;
};

#endif