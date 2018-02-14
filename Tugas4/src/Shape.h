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
    float setCenterCoordinate(float, float);
    float getCenterX();
    float getCenterY();
    float getRadius();
  protected:
    Dot* dots;
    int vertices;
    float xCenter;
    float yCenter;
    float radius;
};

#endif
