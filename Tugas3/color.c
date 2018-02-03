#include "raster.h"


RGBa getColor(FrameBuffer frame, Coordinate point) {
  RGBa color;
  long int location = getLocation(frame, point);
  int r = *(frame.fbp + location + 2);
  int g = *(frame.fbp + location + 1);
  int b = *(frame.fbp + location);
  int gamma = *(frame.fbp + location + 3);
  setColor(&color, r, g, b ,gamma);
  return color;
}

void setColor(RGBa *color, int r, int g, int b, int gamma) {
  (*color).r = r;
  (*color).g = g;
  (*color).b = b;
  (*color).gamma = gamma;
}

void paintPixel(char * fbp, long int location, RGBa color) {
  *(fbp + location) = color.b;        // Some blue
  *(fbp + location + 1) = color.g;     // A little green
  *(fbp + location + 2) = color.r;    // A lot of red
  *(fbp + location + 3) = color.gamma;      // No transparency
}

bool isEqualR(int r1, int r2) {
  return (r1 == r2);
}

bool isEqualG(int g1, int g2) {
  return (g1 == g2);
}

bool isEqualB(int b1, int b2) {
  return (b1 == b2);
}

bool isEqualGamma(int gamma1, int gamma2) {
  return (gamma1 == gamma2);
}


bool isEqualColor(RGBa color1, RGBa color2) {
  return isEqualR(color1.r, color2.r) && isEqualG(color1.g, color2.g) && isEqualB(color1.b, color2.b) && isEqualGamma(color1.gamma, color2.gamma);
}

void BFill4Connected(FrameBuffer frame, Coordinate point, RGBa fillcoll, RGBa boundcol) {
  RGBa currcol = getColor(frame, point);
  if(!isEqualColor(currcol, fillcoll) && !isEqualColor(currcol, boundcol)) {
    long int location = getLocation(frame, point);
    paintPixel(frame.fbp, location, fillcoll);
    BFill4Connected(frame, getTopCoordinate(point), fillcoll, boundcol);
    BFill4Connected(frame, getBottomCoordinate(point), fillcoll, boundcol);
    BFill4Connected(frame, getLeftCoordinate(point), fillcoll, boundcol);
    BFill4Connected(frame, getRightCoordinate(point), fillcoll, boundcol);
  }
}

void BFill8Connected(FrameBuffer frame, Coordinate point, RGBa fillcoll, RGBa boundcol) {
  RGBa currcol = getColor(frame, point);
  if(!isEqualColor(currcol, fillcoll) && !isEqualColor(currcol, boundcol)) {
    long int location = getLocation(frame, point);
    paintPixel(frame.fbp, location, fillcoll);
    BFill8Connected(frame, getTopCoordinate, fillcoll, boundcol);
    BFill8Connected(frame, getBottomCoordinate, fillcoll, boundcol);
    BFill8Connected(frame, getLeftCoordinate, fillcoll, boundcol);
    BFill8Connected(frame, getRightCoordinate, fillcoll, boundcol);
    BFill8Connected(frame, getTopLeftCoordinate, fillcoll, boundcol);
    BFill8Connected(frame, getBottomLeftCoordinate, fillcoll, boundcol);
    BFill8Connected(frame, getTopRightCoordinate, fillcoll, boundcol);
    BFill8Connected(frame, getBottomRightCoordinate, fillcoll, boundcol);
  }
}
