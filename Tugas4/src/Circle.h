#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "Shape.h"
#include "Dot.h"

using namespace std;

class Circle : public Shape {
  public:
    Circle();
    Circle(string);
    Circle(string, int);
    Circle(const Circle&);
    ~Circle();
    Circle& operator=(const Circle&);

  protected:
    Dot centerPoint;
    int diameter;
};

#endif