#ifndef LINE_H
#define LINE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x0;
  int y0;
  int x1;
  int y1;
} Line;

void line(Line line);
void setPixel(int x, int y);

#endif