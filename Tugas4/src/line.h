#ifndef LINE_H
#define LINE_H

#include "struct.h"
#include "coordinate.h"
#include "color.h"

void makeLine(FrameBuffer frame, Line *line);
void makeLineOnGrid(int gridYsize,int grid[][gridYsize], int gridXSize,Line *line);
void setLineCoordinate(Line *line, Coordinate point1, Coordinate point2);
void setLinePoints(Line *line, int x0 , int y0, int x1, int y1);
Coordinate getPoint1(Line line);
Coordinate getPoint2(Line line);
int getX0(Line line);
int getX1(Line line);
int getY0(Line line);
int getY1(Line line);
bool isInLine(Line line, Coordinate point);

#endif