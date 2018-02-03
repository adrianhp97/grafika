#include "raster.h"


RGBa getColor(FrameBuffer frame, Coordinate point) {

}

void paintPixel(char * fbp, long int location, RGBa color) {
  *(fbp + location) = color.b;        // Some blue
  *(fbp + location + 1) = color.g;     // A little green
  *(fbp + location + 2) = color.r;    // A lot of red
  *(fbp + location + 3) = color.gamma;      // No transparency
}

bool isEqualColor(RGBa color1, RGBa color2) {

}

void BFill4Connected(FrameBuffer frame, Coordinate point, RGBa fillcoll, RGBa boundcol) {
  RGBa currcol = getColor(frame, point);
  if(!isEqualColor(currcol, fillcoll) && !isEqualColor(currcol, boundcol)) {
    paintPixel();
    BFill4Connected(frame, point, fillcoll, boundcol);
    BFill4Connected(frame, point, fillcoll, boundcol);
    BFill4Connected(frame, point, fillcoll, boundcol);
    BFill4Connected(frame, point, fillcoll, boundcol);
  }
}

void BFill8Connected(FrameBuffer frame, Coordinate point, RGBa fillcoll, RGBa boundcol) {
  RGBa currcol = getColor(frame, point);
  if(!isEqualColor(currcol, fillcoll) && !isEqualColor(currcol, boundcol)) {
    paintPixel();
    BFill8Connected(frame, point, fillcoll, boundcol);
    BFill8Connected(frame, point, fillcoll, boundcol);
    BFill8Connected(frame, point, fillcoll, boundcol);
    BFill8Connected(frame, point, fillcoll, boundcol);
    BFill8Connected(frame, point, fillcoll, boundcol);
    BFill8Connected(frame, point, fillcoll, boundcol);
    BFill8Connected(frame, point, fillcoll, boundcol);
    BFill8Connected(frame, point, fillcoll, boundcol);
  }
}
