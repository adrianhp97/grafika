#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include "Dot.h"
#include "Line.h"

using namespace std;

class Shape {
  public:
    Shape(int);
    Shape(Dot*, int);
    //Shape(string);
    //Shape(const Shape&);
    //~Shape();
    //Shape& operator=(const Shape&);
    Dot getDot(int i);
    Dot* getDots();
    Line getLine(int i);
    int getNumberOfVertices();
    virtual int getCenterX() = 0;
    virtual int getCenterY() = 0;
    virtual int getRadius() = 0;
  protected:
    Dot* dots;
    int vertices;
    int xCenter;
    int yCenter;
    int radius;
};

#endif
