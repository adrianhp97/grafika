#include "Image.h"

Image::Image(int x, int y, float size) {
  this->x = x;
  this->y = y;
  this->size = size;
}

Image::~Image() {
  for(unsigned int i = 0; i < shapes.size(); i++) {
    delete shapes.at(i);
  }
}

Shape* Image::getShapePointer(unsigned int i) {
  return shapes.at(i);
}

void Image::addShape(Shape *newShape, int xRel, int yRel) {
  newShape->translate(this->x + xRel, this->y + yRel);
  newShape->scale(this->size);
  shapes.push_back(newShape);
}

int Image::getNumberOfShapes() {
  return shapes.size();
}

void Image::translate(float x, float y) {
  for(unsigned int i = 0; i < shapes.size(); i++) {
    shapes[i]->translate(x,y);
  }
  this->x += x;
  this->y += y;
}

void Image::scale(float amount) {
  translate(-this->x,-this->y);
  for(unsigned int i = 0; i < shapes.size(); i++) {
    shapes[i]->scale(amount,0,0);
  }
  translate(this->x,this->y);
}

void Image::scale(float amount, float xCenter, float yCenter) {
  translate(-xCenter,-yCenter);
  for(unsigned int i = 0; i < shapes.size(); i++) {
    shapes[i]->scale(amount,xCenter,yCenter);
  }
  translate(xCenter,yCenter);
}

void Image::rotate(double degree) {
  translate(-this->x,-this->y);
  for(unsigned int i = 0; i < shapes.size(); i++) {
    shapes[i]->rotate(degree,0,0);
  }
  translate(this->x,this->y);
}

void Image::rotate(double degree, float xCenter, float yCenter) {
  translate(-xCenter,-yCenter);
  for(unsigned int i = 0; i < shapes.size(); i++) {
    shapes[i]->rotate(degree,xCenter,yCenter);
  }
  translate(xCenter,yCenter);
}

