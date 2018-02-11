#ifndef WING_H
#define WING_H

#include <iostream>

using namespace std;

class Wing {
	public:
		// ctor, cctor, dtor, operator=
		Wing();
		Wing(int);
		Wing(const Wing&);
		~Wing();
		Wing& operator=(const Wing&);

	protected:
    string name;
};

#endif