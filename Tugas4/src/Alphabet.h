#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include "Line.h"
#include <iostream>

using namespace std;

class Alphabet {
  public:
    Alphabet();
    Alphabet(int);
    Alphabet(const Alphabet&);
    ~Alphabet();
    Alphabet& operator=(const Alphabet&);

  protected:
    char name;
    Line* line;
    int numberOfLine;
};

#endif