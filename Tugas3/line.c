#include "line.h"

void makeLine(FrameBuffer frame, Line *line) {
  RGBa color;
  int dx = abs((*line).x1-(*line).x0), sx = (*line).x0<(*line).x1 ? 1 : -1;
  int dy = abs((*line).y1-(*line).y0), sy = (*line).y0<(*line).y1 ? 1 : -1;
  int err = (dx>dy ? dx : -dy)/2, e2;
  long int location = 0;

  setColor(&color, 2, 213, 32, 0);

  for(;;){
    // setPixel(line.x0,line.y0);
    Coordinate point;
    setCoordinate(&point, (*line).x0, (*line).y0);
    location = getLocation(frame, point);
    paintPixel(frame.fbp, location, color);

    if ((*line).x0==(*line).x1 && (*line).y0==(*line).y1) break;
    e2 = err;
    if (e2 >-dx) { err -= dy; (*line).x0 += sx; }
    if (e2 < dy) { err += dx; (*line).y0 += sy; }
  }
}

void setLineCoordinate(Line *line, Coordinate point1, Coordinate point2) {
  (*line).x0 = point1.x;
  (*line).x1 = point2.x;
  (*line).y0 = point1.y;
  (*line).y1 = point2.y;
}

Coordinate getPoint1(Line line) {
  Coordinate point;
  setCoordinate(&point, line.x0, line.y0);
  return point;
}

Coordinate getPoint2(Line line) {
  Coordinate point;
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
