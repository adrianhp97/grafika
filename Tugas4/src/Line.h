#include "Dot.h"
#include <iostream>

using namespace std;

#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

class Line {
  public:
    Line();
    Line(Dot, Dot);
    Line(const Line&);
    ~Line();
    Line& operator=(const Line&);

  protected:
    Dot d1;
    Dot d2;

}

#endif