#include "Shape.h"

Shape::Shape(int n) {
  for(int i = 0; i < n; i++) {
    dots.push_back(new Dot());
  }
  xCenter = 0;
  yCenter = 0;
  radius = 1;
}

Shape::Shape(Dot* dotCollection, int numberOfVert) {
  for(int i = 0; i < numberOfVert; i++) {
    dots.push_back(&dotCollection[i]);
  }
}

Shape::Shape(const Shape& shape) {
  for(int i = 0; i < shape.getNumberOfVertices(); i++) {
    dots.push_back(new Dot(*shape.getDot(i)));
  }
  this->xCenter = shape.xCenter;
  this->yCenter = shape.yCenter;
  this->radius = shape.radius;
}

Shape::~Shape() {
  for(int i = 0; i < getNumberOfVertices(); i++) {
    delete dots.at(i);
  }
}

Dot* Shape::getDot(int i) const {
  return dots.at(i);
}

vector<Dot*>* Shape::getDots() {
  return &dots;
}

void Shape::addNewDot(Dot* dot) {

  dots.push_back(new Dot(*dot));
}

void Shape::addNewDot(int x, int y, Color color) {
  dots.push_back(new Dot(x,y,color));
}

void Shape::insertNewDot(int pos,int x, int y, Color color) {
  if (pos < dots.size()) {
    dots.insert(dots.begin()+pos, new Dot(x,y,color));
  } else {
    dots.push_back(new Dot(x,y,color));
  }
}

vector<Dot*>::iterator Shape::insertNewDot(vector<Dot*>::iterator it,int x, int y, Color color) {
  return dots.insert(it, new Dot(x,y,color));
}

void Shape::replaceDot(int pos, int x, int y, Color color) {
  Dot* oldValue = dots.at(pos); 
  dots.at(pos) = new Dot(x,y,color);
  delete oldValue;
}

void Shape::replaceDot(vector<Dot*>::iterator it, int x, int y, Color color) {
  Dot* oldValue = *it;
  *it = new Dot(x,y,color);
  delete oldValue;
}
   

void Shape::deleteDot(int pos) {
  dots.erase(dots.begin() + pos);
}

vector<Dot*>::iterator Shape::deleteDot(vector<Dot*>::iterator it) {
  return dots.erase(it);
}

Line Shape::getLine(int i){
  int x = (i+1) > getNumberOfVertices()-1 ? 0 : i+1;
  Line lineTemp(*dots.at(i), *dots.at(x));
  return lineTemp;
}

int Shape::getNumberOfVertices() const{
  return dots.size();
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
