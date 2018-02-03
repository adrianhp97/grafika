#ifndef COORDINATE_H
#define COORDINATE_H

#include "struct.h"

void setCoordinate(Coordinate *point, int x, int y);
void copyCoordinate(Coordinate *dest, Coordinate source);
void setLocation(long int *location, FrameBuffer frame, Coordinate point);
long int getLocation(FrameBuffer frame, Coordinate point);
int getX(Coordinate point);
int getY(Coordinate point);
Coordinate getTopCoordinate(Coordinate point);
Coordinate getBottomCoordinate(Coordinate point);
Coordinate getLeftCoordinate(Coordinate point);
Coordinate getRightCoordinate(Coordinate point);
Coordinate getTopLeftCoordinate(Coordinate point);
Coordinate getBottomLeftCoordinate(Coordinate point);
Coordinate getTopRightCoordinate(Coordinate point);
Coordinate getBottomRightCoordinate(Coordinate point);

#endif