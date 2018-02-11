#ifndef PILOT_H
#define PILOT_H

#include <iostream>

using namespace std;

class Pilot {
	public:
		//ctor, cctor, dtor, operator=
		Pilot();
		Pilot(int);
		Pilot(const Pilot&);
		~Pilot();
		Pilot& operator=(const Pilot&);

	protected:
    string name;
};

#endif