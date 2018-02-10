#include <iostream>

using namespace std;

#ifndef PROPELLER_H
#define PROPELLER_H

class Propeller {
	public:
		//ctor, cctor, dtor, operator=
		Propeller();
		Propeller(int);
		Propeller(const Propeller&);
		~Propeller();
		Propeller& operator=(const Propeller&);

	protected:
    String name;
};

#endif