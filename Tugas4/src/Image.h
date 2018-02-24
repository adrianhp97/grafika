#ifndef IMAGE_H
#define IMAGE_H
#define PI 3.14159265

#include <vector>
#include "Shape.h"
using namespace std;

//Image is an object consist of shapes
class Image {
  public:
    Image(int x, int y, float size);

    Shape* getShapePointer(unsigned int i);
    void addShape(Shape* newShape, int xRel, int yRel);
    int getNumberOfShapes();

    int getX();
    int getY();

    void translate(float, float);
    void scale(float);
    void scale(float, float, float);
    void rotate(double);
    void rotate(double, float, float);

  protected:
    int x;
    int y;
    float size;
    vector<Shape*> shapes;
};

#endif