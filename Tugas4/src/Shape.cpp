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
    getDots()[i].setX((float)getDot(i).getX()+x);
    getDots()[i].setY((float)getDot(i).getY()+y);
  }
  setCenterCoordinate(getCenterX()+x,getCenterY()+y);
}

void Shape::scale(float amount, float xCenter, float yCenter) {
  int i;
  translate(-xCenter, -yCenter);
  for(i = 0; i < getNumberOfVertices(); i++){
    getDots()[i].setX(((float)getDot(i).getX()*amount));
    getDots()[i].setY(((float)getDot(i).getY()*amount));
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
    getDots()[i].setX(((float)getDot(i).getX()*amount));
    getDots()[i].setY(((float)getDot(i).getY()*amount));
  }
  translate(xTemp, yTemp);
}

void Shape::rotate(double degree, float xCenter, float yCenter) {
  int i;
  double sinTheta = sin(degree*PI/180);
  double cosTheta = cos(degree*PI/180);
  translate(-xCenter, -yCenter);
  for(i = 0; i < getNumberOfVertices(); i++){
    double x = (double)getDot(i).getX();
    double y = (double)getDot(i).getY();
    getDots()[i].setX((x*cosTheta) - (y*sinTheta));
    getDots()[i].setY((x*sinTheta) + (y*cosTheta));
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
    double x = (double)getDot(i).getX();
    double y = (double)getDot(i).getY();
    getDots()[i].setX((x*cosTheta) - (y*sinTheta));
    getDots()[i].setY((x*sinTheta) + (y*cosTheta));
  }
  setCenterCoordinate(getCenterX()*cosTheta - getCenterY()*sinTheta, getCenterX()*sinTheta + getCenterY()*cosTheta);
  translate(xTemp, yTemp);
}
