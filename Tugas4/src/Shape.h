#include <iostream>

using namespace std;

#ifndef SHAPE_H
#define SHAPE_H

class Shape {
  public:
    Shape();
    Shape(String);
    Shape(const Shape&);
    ~Shape();
    Shape& operator=(const Shape&);

  protected:
    String name;
}

#endif