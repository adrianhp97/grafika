#ifndef DOT_H
#define DOT_H

#include <iostream>
#include "Color.h"

using namespace std;

class Dot {
  public:
    Dot();
    Dot(int, int, Color);
    Dot(int, int, String);
    Dot(const Dot&);
    ~Dot();
    Dot& operator=(const Dot&);

    void setLocation(long int *, FrameBuffer);
    long int getLocation(FrameBuffer);
    int getX();
    int getY();
    int getColor();
    Dot getTopCoordinate();
    Dot getBottomCoordinate();
    Dot getLeftCoordinate();
    Dot getRightCoordinate();
    Dot getTopLeftCoordinate();
    Dot getBottomLeftCoordinate();
    Dot getTopRightCoordinate();
    Dot getBottomRightCoordinate();

  protected:
    int x;
    int y;
    Color color;
};

#endif