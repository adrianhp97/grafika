#include "Line.h"

Line::Line(Dot src, Dot dest) : d1(src), d2(dest){}

Dot* Line::getDotSrc(){
  return &d1;
}

Dot* Line::getDotDest(){
  return &d2;
}
