#ifndef LASER_H
#define LASER_H

#include <iostream>

using namespace std;

class Laser {
	public:
		//ctor, cctor, dtor, operator=
		Laser();
		Laser(int);
		Laser(const Laser&);
		~Laser();
		Laser& operator=(const Laser&);

	protected:
    string name;
};

#endif