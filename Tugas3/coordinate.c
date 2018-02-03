#include "coordinate.h"

void setCoordinate(Coordinate *point, int x, int y) {
  *point.x = x;
  *point.y = y;
}

void copyCoordinate(Coordinate *dest, Coordinate source) {
  *dest.x = source.x;
  *dest.y = source.y;
}

void setLocation(long int *location, FrameBuffer frame, Coordinate point) {
  *location = ;
}

long int getLocation(FrameBuffer frame, Coordinate point) {
  return 
}


int getX(Coordinate point) {
  return point.x;
}

int getY(Coordinate point) {
  return point.y;
}

Coordinate getTopCoordinate(Coordinate point) {
  Coordinate TopCoordinate;
  setCoordinate(&TopCoordinate, point.x, point.y+1);
  return TopCoordinate;
}

Coordinate getBottomCoordinate(Coordinate point) {
  Coordinate BottomCoordinate;
  setCoordinate(&BottomCoordinate, point.x, point.y-1);
  return BottomCoordinate;
}

Coordinate getLeftCoordinate(Coordinate point) {
  Coordinate LeftCoordinate;
  setCoordinate(&LeftCoordinate, point.x-1, point.y);
  return LeftCoordinate;
}

Coordinate getRightCoordinate(Coordinate point) {
  Coordinate RightCoordinate;
  setCoordinate(&RightCoordinate, point.x+1, point.y);
  return RightCoordinate;
}

Coordinate getTopLeftCoordinate(Coordinate point) {
  Coordinate TopLeftCoordinate;
  setCoordinate(&TopLeftCoordinate, point.x-1, point.y+1);
  return TopLeftCoordinate;
}

Coordinate getBottomLeftCoordinate(Coordinate point) {
  Coordinate BottomLeftCoordinate;
  setCoordinate(&BottomLeftCoordinate, point.x-1, point.y-1);
  return BottomLeftCoordinate;
}

Coordinate getTopRightCoordinate(Coordinate point) {
  Coordinate TopRightCoordinate;
  setCoordinate(&TopRightCoordinate, point.x+1, point.y+1);
  return TopRightCoordinate;
}

Coordinate getBottomRightCoordinate(Coordinate point) {
  Coordinate BottomRightCoordinate;
  setCoordinate(&BottomRightCoordinate, point.x+1, point.y-1);
  return BottomRightCoordinate;
}
