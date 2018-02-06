#include "Line.h"
#include <iostream>

using namespace std;

#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

class Alphabet {
  public:
    Alphabet();
    Alphabet(int);
    Alphabet(const Alphabet&);
    ~Alphabet();
    Alphabet& operator=(const Alphabet&);

  protected:
    Line* line;
    int numberOfLine;
}

#endif