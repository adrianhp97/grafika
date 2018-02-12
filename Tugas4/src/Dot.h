#ifndef DOT_H
#define DOT_H

#include <iostream>
#include "Color.h"

using namespace std;

class Dot {
  public:
    Dot();
    Dot(float, float, Color);
    //Dot(int, int, string);
    //Dot(const Dot&);
    //~Dot();
    //Dot& operator=(const Dot&);
    void setCoordinate(float,float);
    void setX(float);
	  float getX();
	  void setY(float);
    float getY();
    void setColor(int r, int g, int b);
	  Color getColor();

  //protected:
    float x;
    float y;
    Color color;
};

#endif
