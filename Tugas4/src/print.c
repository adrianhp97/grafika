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
