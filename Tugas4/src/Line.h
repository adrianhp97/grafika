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

  protected:
    Dot d1;
    Dot d2;

};

#endif