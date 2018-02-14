#ifndef PROPELLER_H
#define PROPELLER_H

#include <iostream>
#include "../Shape.h"
using namespace std;

class Propeller : public Shape {
	public:
		//ctor, cctor, dtor, operator=
		Propeller(int, int, float);
		//~Propeller();
		/*Propeller(int);
		Propeller(const Propeller&);
		Propeller& operator=(const Propeller&);
	*/
};

#endif
