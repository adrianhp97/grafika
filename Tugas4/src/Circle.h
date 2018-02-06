#include <iostream>
#include "Shape.h"

using namespace std;

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle : public Shape {
  public:
    Circle();
    Circle(String);
    Circle(String, int);
    Circle(const Circle&);
    ~Circle();
    Circle& operator=(const Circle&);

  protected:
    Dot centerPoint;
    int diameter;
}

#endif