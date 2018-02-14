#ifndef WING_H
#define WING_H

#include <iostream>
#include "../Shape.h"

using namespace std;

class Wing : public Shape {
	public:
		// ctor, cctor, dtor, operator=
		Wing(int, int, float);
		//Wing(int);
		//Wing(const Wing&);
		//~Wing();
		//Wing& operator=(const Wing&);
};

#endif
