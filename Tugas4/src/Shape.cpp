#include "Shape.h"

Shape::Shape(int n) {
  for(int i = 0; i < n; i++) {
    dots.push_back(new Dot());
  }
  vertices = n;
  xCenter = 0;
  yCenter = 0;
  radius = 1;
}

Shape::Shape(Dot* dotCollection, int numberOfVert) {
  for(int i = 0; i < numberOfVert; i++) {
    dots.push_back(&dotCollection[i]);
  }
  vertices = numberOfVert;
}

Dot* Shape::getDot(int i){
  return dots.at(i);
}

Line Shape::getLine(int i){
  int x = (i+1) >= vertices ? 0 : i+1;
  Line lineTemp(*dots.at(i), *dots.at(x));
  return lineTemp;
}

int Shape::getNumberOfVertices() {
  return vertices;
}

float Shape::setCenterCoordinate(float x, float y){
  xCenter = x;
  yCenter = y;
}

float Shape::getCenterX(){
  return xCenter;
}

float Shape::getCenterY(){
  return yCenter;
}

float Shape::getRadius(){
  return radius;
}

void Shape::translate(float x, float y) {
  int i;
  for(i = 0; i < getNumberOfVertices(); i++){
    getDot(i)->setX((float)getDot(i)->getX()+x);
    getDot(i)->setY((float)getDot(i)->getY()+y);
  }
  setCenterCoordinate(getCenterX()+x,getCenterY()+y);
}

void Shape::scale(float amount, float xCenter, float yCenter) {
  int i;
  translate(-xCenter, -yCenter);
  for(i = 0; i < getNumberOfVertices(); i++){
    getDot(i)->setX(((float)getDot(i)->getX()*amount));
    getDot(i)->setY(((float)getDot(i)->getY()*amount));
  }
  setCenterCoordinate(getCenterX()*amount, getCenterY()*amount);
  translate(xCenter, yCenter);
}

void Shape::scale(float amount) {
  int i;
  float xTemp = (float)getCenterX();
  float yTemp = (float)getCenterY();
  translate(-xTemp, -yTemp);
  for(i = 0; i < getNumberOfVertices(); i++){
    getDot(i)->setX(((float)getDot(i)->getX()*amount));
    getDot(i)->setY(((float)getDot(i)->getY()*amount));
  }
  translate(xTemp, yTemp);
}

void Shape::rotate(double degree, float xCenter, float yCenter) {
  int i;
  double sinTheta = sin(degree*PI/180);
  double cosTheta = cos(degree*PI/180);
  translate(-xCenter, -yCenter);
  for(i = 0; i < getNumberOfVertices(); i++){
    double x = (double)getDot(i)->getX();
    double y = (double)getDot(i)->getY();
    getDot(i)->setX((x*cosTheta) - (y*sinTheta));
    getDot(i)->setY((x*sinTheta) + (y*cosTheta));
  }
  translate(xCenter, yCenter);
}

void Shape::rotate(double degree) {
  int i;
  double sinTheta = sin(degree*PI/180);
  double cosTheta = cos(degree*PI/180);
  float xTemp = (float)getCenterX();
  float yTemp = (float)getCenterY();
  translate(-xTemp, -yTemp);
  for(i = 0; i < getNumberOfVertices(); i++){
    double x = (double)getDot(i)->getX();
    double y = (double)getDot(i)->getY();
    getDot(i)->setX((x*cosTheta) - (y*sinTheta));
    getDot(i)->setY((x*sinTheta) + (y*cosTheta));
  }
  setCenterCoordinate(getCenterX()*cosTheta - getCenterY()*sinTheta, getCenterX()*sinTheta + getCenterY()*cosTheta);
  translate(xTemp, yTemp);
}
