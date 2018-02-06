#include <iostream>
#include "Color.h"

using namespace std;

#ifndef DOT_H
#define DOT_H

class Dot {
  public:
    Dot();
    Dot(int, int, Color);
    Dot(int, int, String);
    Dot(const Dot&);
    ~Dot();
    Dot& operator=(const Dot&);

  protected:
    int x;
    int y;
    Color color;
}

#endif