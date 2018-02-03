#include "alphabet.h"

void makeA() {
  Coordinate point1;
  Coordinate point2;
  setCoordinate(&point1, 200, 200);
  setCoordinate(&point1, 300, 300);
  Line line[11];
  setLineCoordinate(&line[0], point1, point2);
  makeLine(frame, &line);
}