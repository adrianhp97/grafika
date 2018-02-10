#include "Dot.h"
#include <iostream>

using namespace std;

#ifndef LINE_H
#define LINE_H

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