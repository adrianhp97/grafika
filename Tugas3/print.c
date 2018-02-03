#include "print.h"

int clearPixel(char * fbp, long int location) {
  *(fbp + location) = 0;
  *(fbp + location + 1) = 0;
  *(fbp + location + 2) = 0;
  *(fbp + location + 3) = 0;    

  return 0;
}

int clearScreen(char * fbp, long int location) {
  int x;
  int y;

  for (y = 100; y < 300; y++) {
      for (x = 100; x < 300; x++) {
          clearPixel(fbp, location);
      }
  }

  return 0;
}

int paintPixel(char * fbp, long int location, RGBa color) {

  *(fbp + location) = color.b;        // Some blue
  *(fbp + location + 1) = color.g;     // A little green
  *(fbp + location + 2) = color.r;    // A lot of red
  *(fbp + location + 3) = color.gamma;      // No transparency

  return 0;
}