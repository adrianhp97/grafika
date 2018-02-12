#ifndef ALPHABET_H
#define ALPHABET_H

#include "Line.h"
#include <iostream>
#include "FrameBuffer.h"

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