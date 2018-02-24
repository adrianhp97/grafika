#include "View.h"

View::View(Image* image, float xmin, float ymin, float xmax, float ymax) : Image(image->getX(),image->getY(),1){
  clipImage(image,xmin,ymin,xmax,ymax);
}

View::View(Image* image) : View(image,0,0,100,100) {}

View::~View() {
  for(int i = 0; i < this->getNumberOfShapes(); i++) {
    delete this->shapes.at(i);
  }
}

void View::clipImage(Image* image,float xmin, float ymin, float xmax, float ymax) {
  for(int i = 0; i < image->getNumberOfShapes(); i++) {
    Shape* newClippedShape = clipShape(image->getShapePointer(i),xmin,ymin,xmax,ymax);
    shapes.push_back(newClippedShape);
  }
}

void View::updateClip(float xmin, float ymin, float xmax, float ymax) {

}

Shape* View::clipShape(Shape* shape,float xmin, float ymin, float xmax, float ymax) {
  //polygon clipping: Sutherland Hogman
  int xTemp = this->x;
  int yTemp = this->y; 

  Shape* clippedShape = new Shape(*shape); 
  translate(-xTemp,-yTemp);

  vector<Dot*>* dots =clippedShape->getDots();
  vector<Dot*>::iterator it;

  //TOP stage
  it = dots->begin();
  for(int i = 0; i < shape->getNumberOfVertices(); i++) {
    Dot* src = shape->getLine(i).getDotSrc();
    Dot* dest = shape->getLine(i).getDotDest();
    float srcX = src->getX(); float srcY = src->getY();
    float destX = dest->getX(); float destY = dest->getY();
    if (srcY >= ymin && destY >= ymin) {
      it++;      
    } else if (srcY >= ymin) {
      it++;
      int xnew = (((srcX - destX)/(srcY - destY)) * (ymin - destY)) + destX;
      it = clippedShape->insertNewDot(it, xnew, ymin, src->getColor());
      it++;
    } else if (destY >= ymin) {      
      int xnew = (((destX - srcX)/(destY - srcY)) * (ymin - srcY)) + srcX;
      clippedShape->replaceDot(it, xnew, ymin, src->getColor());
      it++;
    } else {
      it = clippedShape->deleteDot(it);
    }
  }

  

  translate(xTemp,yTemp);
  return clippedShape;
}