#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

using namespace std;

class Shape {
  public:
    Shape();
    Shape(string);
    Shape(const Shape&);
    ~Shape();
    Shape& operator=(const Shape&);

  protected:
    string name;
};

#endif