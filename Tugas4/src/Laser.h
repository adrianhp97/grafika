#include <iostream>

using namespace std;

#ifndef LASER_H
#define LASER_H

class Laser {
	public:
		//ctor, cctor, dtor, operator=
		Laser();
		Laser(int);
		Laser(const Laser&);
		~Laser();
		Laser& operator=(const Laser&);

	protected:
    String name;
};

#endif