#ifndef SHAPE_H
#define SHAPE_H
#define PI 3.14159265

#include <iostream>
#include <math.h>
#include <vector>
#include "Dot.h"
#include "Line.h"

using namespace std;

class Shape {
  public:
    Shape(int);
    Shape(Dot*, int);
    //Shape(string);
    Shape(const Shape&);
    ~Shape();
    //Shape& operator=(const Shape&);
    Dot* getDot(int i) const;
    vector<Dot*>* getDots();

    void addNewDot(Dot* dot);
    void addNewDot(int x, int y, Color color);
    void insertNewDot(int pos, int x, int y, Color color);
    vector<Dot*>::iterator insertNewDot(vector<Dot*>::iterator it,int x, int y, Color color);
    void replaceDot(int pos, int x, int y, Color color);
    void replaceDot(vector<Dot*>::iterator it, int x, int y, Color color);
    void deleteDot(int pos);
    vector<Dot*>::iterator deleteDot(vector<Dot*>::iterator it);

    Line getLine(int i);
    int getNumberOfVertices() const;
    float setCenterCoordinate(float, float);
    float getCenterX();
    float getCenterY();
    float getRadius();

    void translate(float, float);
    void scale(float);
    void scale(float, float, float);
    void rotate(double);
    void rotate(double, float, float);
  protected:
    vector<Dot*> dots;
    float xCenter;
    float yCenter;
    float radius;
};

#endif
