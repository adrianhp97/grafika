#include <iostream>

using namespace std;

#ifndef WHEEL_H
#define WHEEL_H

class Wing {
	public:
		//ctor, cctor, dtor, operator=
		Wing();
		Wing(int);
		Wing(const Wing&);
		~Wing();
		Wing& operator=(const Wing&);

	protected:
    String name;
};

#endif