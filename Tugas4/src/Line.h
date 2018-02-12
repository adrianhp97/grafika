#ifndef LINE_H
#define LINE_H

#include <iostream>
#include "Dot.h"
#include "FrameBuffer.h"

using namespace std;

class Line {
  public:
    //Line();
    Line(Dot, Dot);
    Line(const Line&);
    ~Line();
    Line& operator=(const Line&);

    void makeLine(FrameBuffer);
    void makeLineOnGrid(int, int**, int);
    void setLineCoordinate(Dot, Dot);
    void setLinePoints(int, int, int, int);
    Dot getPoint1();
    Dot getPoint2();
    bool isInLine(Dot);

  protected:
    Dot d1;
    Dot d2;

};

#endif
