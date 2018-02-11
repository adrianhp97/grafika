#ifndef PROPELLER_H
#define PROPELLER_H

#include <iostream>

using namespace std;

class Propeller {
	public:
		//ctor, cctor, dtor, operator=
		Propeller();
		Propeller(int);
		Propeller(const Propeller&);
		~Propeller();
		Propeller& operator=(const Propeller&);

	protected:
    string name;
};

#endif