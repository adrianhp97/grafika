#include "line.h"

void setLine(Line *line) {
  int dx = abs((*line).x1-(*line).x0), sx = (*line).x0<(*line).x1 ? 1 : -1;
  int dy = abs((*line).y1-(*line).y0), sy = (*line).y0<(*line).y1 ? 1 : -1; 
  int err = (dx>dy ? dx : -dy)/2, e2;

  for(;;){
    // setPixel(line.x0,line.y0);
    if ((*line).x0==(*line).x1 && (*line).y0==(*line).y1) break;
    e2 = err;
    if (e2 >-dx) { err -= dy; (*line).x0 += sx; }
    if (e2 < dy) { err += dx; (*line).y0 += sy; }
  }
}

Coodinate getPoint1(Line line) {
  Coodinate point;
  setCoordinate(&point, line.x0, line.y0);
  return point;
}

Coodinate getPoint2(Line line) {
  Coodinate point;
  setCoordinate(&point, line.x1, line.y1);
  return point;
}

int getX0(Line line) {
  return line.x0;
}

int getX1(Line line) {
  return line.x1;
}

int getY0(Line line) {
  return line.y0;
}

int getY1(Line line) {
  return line.y1;
}
