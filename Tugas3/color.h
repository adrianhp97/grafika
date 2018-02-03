#ifndef COLOR_H
#define COLOR_H

#include "struct.h"

RGBa getColor(FrameBuffer frame, Coordinate point);
int paintPixel(FrameBuffer frame, long int location, RGBa color);
bool isEqualColor(RGBa color1, RGBa color2);
void BFill4Connected(FrameBuffer frame, Coordinate point, RGBa fillcoll, RGBa boundcol);
void BFill8Connected(FrameBuffer frame, Coordinate point, RGBa fillcoll, RGBa boundcol);

#endif