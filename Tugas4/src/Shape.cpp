#include "Shape.h"

Shape::Shape(int n) {
  dots = new Dot[n];
  vertices = n;
}

Shape::Shape(Dot* dotCollection, int numberOfVert) {
  dots = dotCollection;
  vertices = numberOfVert;
}

Dot* Shape::getDots(){
  return dots;
}

Dot Shape::getDot(int i){
  return dots[i];
}

Line Shape::getLine(int i){
  int x = (i+1) >= vertices ? 0 : i+1;
  Line lineTemp(dots[i], dots[x]);
  return lineTemp;
}

int Shape::getNumberOfVertices() {
  return vertices;
}
