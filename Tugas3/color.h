#ifndef COLOR_H
#define COLOR_H

#include "struct.h"
#include "coordinate.h"

RGBa getColor(FrameBuffer frame, Coordinate point);
void setColor(FrameBuffer frame, Coordinate point);
int paintPixel(FrameBuffer frame, long int location, RGBa color);
bool isEqualR(int r1, int r2);
bool isEqualG(int g1, int g2);
bool isEqualB(int b1, int b2);
bool isEqualA(int a1, int a2);
bool isEqualColor(RGBa color1, RGBa color2);
void BFill4Connected(FrameBuffer frame, Coordinate point, RGBa fillcoll, RGBa boundcol);
void BFill8Connected(FrameBuffer frame, Coordinate point, RGBa fillcoll, RGBa boundcol);

#endif