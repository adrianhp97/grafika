#ifndef LINE_H
#define LINE_H

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "coodinate.h"

void makeLine(Line *line);
void setLineCoordinate(Line *line);
Coodinate getPoint1(Line line);
Coodinate getPoint2(Line line);
int getX0(Line line);
int getX1(Line line);
int getY0(Line line);
int getY1(Line line);

#endif