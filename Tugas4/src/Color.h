#ifndef COLOR_H
#define COLOR_H

#include <iostream>

using namespace std;

class Color {
  public:
	int r,g,b,a;

  Color() {
    r = 255;
    g = 255;
    b = 255;
    a = 0;
  }

	Color(int r, int g, int b){
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = 0;
	}

  Color(int r, int g, int b, int a) {
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

  Color(const Color& color) {
    r = color.r;
    g = color.g;
    b = color.b;
    a = color.a;
  }
};

#endif
