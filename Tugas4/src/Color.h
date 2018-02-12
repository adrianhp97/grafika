#ifndef COLOR_H
#define COLOR_H

#include <iostream>

using namespace std;

class Color {
  public:

    Color();
    Color(int, int, int, int);
    Color(string);
    Color(const Color&);
    Color& operator=(const Color&);
    int r;
    int g;
    int b;
    int a;
};

#endif
