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

  Shape clippedShape(*shape); 
  translate(-xTemp,-yTemp);

  vector<Dot*>* dots;
  vector<Dot*>::iterator it;

  //TOP stage
  dots = clippedShape.getDots();
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
      it = clippedShape.insertNewDot(it, xnew, ymin, src->getColor());
      it++;
    } else if (destY >= ymin) {      
      int xnew = (((destX - srcX)/(destY - srcY)) * (ymin - srcY)) + srcX;
      clippedShape.replaceDot(it, xnew, ymin, src->getColor());
      it++;
    } else {
      it = clippedShape.deleteDot(it);
    }
  }

  Shape clippedShape2(clippedShape);

  //BOT stage
  dots = clippedShape2.getDots();
  it = dots->begin();
  for(int i = 0; i < clippedShape.getNumberOfVertices(); i++) {
    Dot* src = clippedShape.getLine(i).getDotSrc();
    Dot* dest = clippedShape.getLine(i).getDotDest();
    float srcX = src->getX(); float srcY = src->getY();
    float destX = dest->getX(); float destY = dest->getY();
    if (srcY <= ymax && destY <= ymax) {
      it++;      
    } else if (srcY <= ymax) {
      it++;
      int xnew = (((srcX - destX)/(srcY - destY)) * (ymax - destY)) + destX;
      it = clippedShape2.insertNewDot(it, xnew, ymax, src->getColor());
      it++;
    } else if (destY <= ymax) {      
      int xnew = (((destX - srcX)/(destY - srcY)) * (ymax - srcY)) + srcX;
      clippedShape2.replaceDot(it, xnew, ymax, src->getColor());
      it++;
    } else {
      it = clippedShape2.deleteDot(it);
    }
  }

  Shape clippedShape3(clippedShape2);

  //RIGHT stage
  dots = clippedShape3.getDots();
  it = dots->begin();
  for(int i = 0; i < clippedShape2.getNumberOfVertices(); i++) {
    Dot* src = clippedShape2.getLine(i).getDotSrc();
    Dot* dest = clippedShape2.getLine(i).getDotDest();
    float srcX = src->getX(); float srcY = src->getY();
    float destX = dest->getX(); float destY = dest->getY();
    if (srcX <= xmax && destX <= xmax) {
      it++;      
    } else if (srcX <= xmax) {
      it++;
      int ynew = (((srcY - destY)/(srcX - destX)) * (xmax - destX)) + destY;
      it = clippedShape3.insertNewDot(it, xmax, ynew, src->getColor());
      it++;
    } else if (destX <= xmax) {      
      int ynew = (((destY - srcY)/(destX - srcX)) * (xmax - srcX)) + srcY;
      clippedShape3.replaceDot(it, xmax, ynew, src->getColor());
      it++;
    } else {
      it = clippedShape3.deleteDot(it);
    }
  }

  Shape clippedShape4(clippedShape3);

  //RIGHT stage
  dots = clippedShape4.getDots();
  it = dots->begin();
  for(int i = 0; i < clippedShape3.getNumberOfVertices(); i++) {
    Dot* src = clippedShape3.getLine(i).getDotSrc();
    Dot* dest = clippedShape3.getLine(i).getDotDest();
    float srcX = src->getX(); float srcY = src->getY();
    float destX = dest->getX(); float destY = dest->getY();
    if (srcX >= xmin && destX >= xmin) {
      it++;      
    } else if (srcX  >= xmin) {
      it++;
      int ynew = (((srcY - destY)/(srcX - destX)) * (xmin - destX)) + destY;
      it = clippedShape4.insertNewDot(it, xmin, ynew, src->getColor());
      it++;
    } else if (destX  >= xmin) {      
      int ynew = (((destY - srcY)/(destX - srcX)) * (xmin - srcX)) + srcY;
      clippedShape4.replaceDot(it, xmin, ynew, src->getColor());
      it++;
    } else {
      it = clippedShape4.deleteDot(it);
    }
  }

  translate(xTemp,yTemp);
  return new Shape(clippedShape4);
}