#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <string>
#include "../Shape.h"

using namespace std;

class Text{
  public:
    Text(string, int, int);

  private:
    Shape* Character;
};

#endif
