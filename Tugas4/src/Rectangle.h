#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "Shape.h"
#include "Line.h"

using namespace std;

class Rectangle : public Shape {
  public:
    Rectangle();
    Rectangle(string);
    Rectangle(const Rectangle&);
    ~Rectangle();
    Rectangle& operator=(const Rectangle&);

  protected:
    Line* line;
    const int numberOfLine = 4;
};

#endif