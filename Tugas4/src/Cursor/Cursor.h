#ifndef CURSOR_H
#define CURSOR_H

#include <iostream>
#include "../Shape.h"
#include "../CustomShape.h"

using namespace std;

class Cursor : public Shape {
public :
    Cursor();
    Cursor(int, int, float);
};


#endif