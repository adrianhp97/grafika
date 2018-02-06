#include <iostream>

using namespace std;

#ifndef COLOR_H
#define COLOR_H

class Color {
  public:
    Color();
    Color(int, int, int, int);
    Color(String);
    Color(const Color&);
    ~Color();
    Color& operator=(const Color&);

  protected:
    int r;
    int g;
    int b;
    int a;
}

#endif