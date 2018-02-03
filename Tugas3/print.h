#ifndef PRINT_H
#define PRINT_H

typedef struct {
  int r;
  int g;
  int b;
  int gamma;
} RGBa;

int clearPixel(char * fbp, long int location);
int clearScreen(char * fbp, long int location);
int paintPixel(char * fbp, long int location, RGBa color);

#endif