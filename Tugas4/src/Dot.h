#ifndef DOT_H
#define DOT_H

#include <iostream>
#include "Color.h"

using namespace std;

class Dot {
  public:
    Dot();
    Dot(int, int, Color);
    Dot(int, int, string);
    Dot(const Dot&);
    ~Dot();
    Dot& operator=(const Dot&);

  protected:
    int x;
    int y;
    Color color;
};

#endif