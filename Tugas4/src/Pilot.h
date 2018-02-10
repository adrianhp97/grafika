#include <iostream>

using namespace std;

#ifndef PILOT_H
#define PILOT_H

class Pilot {
	public:
		//ctor, cctor, dtor, operator=
		Pilot();
		Pilot(int);
		Pilot(const Pilot&);
		~Pilot();
		Pilot& operator=(const Pilot&);

	protected:
    String name;
};

#endif