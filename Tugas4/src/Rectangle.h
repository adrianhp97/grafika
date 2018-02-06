#include <iostream>
#include "Shape.h"

using namespace std;

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle : public Shape {
  public:
    Rectangle();
    Rectangle(String);
    Rectangle(const Rectangle&);
    ~Rectangle();
    Rectangle& operator=(const Rectangle&);

  protected:
    Line* line;
    const int numberOfLine = 4;
}

#endif