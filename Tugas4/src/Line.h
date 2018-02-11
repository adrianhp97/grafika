#ifndef LINE_H
#define LINE_H

#include <iostream>
#include "Dot.h"

using namespace std;

class Line {
  public:
    Line();
    Line(Dot, Dot);
    Line(const Line&);
    ~Line();
    Line& operator=(const Line&);

    void makeLine(FrameBuffer);
    void makeLineOnGrid(int, int**, int);
    void setLineCoordinate(Dot, Dot);
    void setLinePoints(int, int, int, int);
    Coordinate getPoint1();
    Coordinate getPoint2();
    bool isInLine(Dot);

  protected:
    Dot d1;
    Dot d2;

};

#endif