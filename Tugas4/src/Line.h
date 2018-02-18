#ifndef LINE_H
#define LINE_H

#include <iostream>
#include "Dot.h"
#include "Color.h"

using namespace std;

class Line {
  public:
    //Line();
    Line(Dot, Dot);
    //Line(const Line&);
    //~Line();
    //Line& operator=(const Line&);
    Dot* getDotSrc();
    Dot* getDotDest();
  protected:
    Dot d1;
    Dot d2;

};

#endif
