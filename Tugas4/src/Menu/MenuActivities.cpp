#include <iostream>
#include <stdio.h>
#include <vector>
#include "MenuActivities.h"
#include "../FrameBuffer.h"
#include "../Color.h"
#include "../Dot.h"
#include "../Plane.h"
#include "../Missile.h"
#include "../People.h"
#include "../Input.h"
#include "../PlaneImage.h"
#include "../View.h"
#include "../CustomShape.h"
#include "../ItbMapImage.h"


int StartMap() {
  int i=1;
  FrameBuffer frame;
  Input input;
  vector<CustomShape*> shape;
  vector<CustomShape*> shape2;
  string dest;
  for(int i=2;i<82;i++){
    dest = "../data/" + std::to_string(i) + ".txt";
    shape.push_back(readFile(dest));
    shape2.push_back(readFile(dest));
  }
  //for(i=0;i<shape->getNumberOfVertices();i++){
  //  printf("%f %f", shape->getDot(i)->getX(),shape->getDot(i)->getY());
  //}
  float initScale = 3.0f;
  ItbMapImage map(shape, 0.0f, 0.0f, 1.0f);
  ItbMapImage mainMap(shape2, 200.0f, 0.0f, initScale);
  Missile missile(100, 700, 1);
  //Plane plane(683,350, 1);
  PlaneImage planeImage(150,250,0.5f);
  float inp = 1;
  View miniView(&map,0,0,370,423);
  View mainView(&mainMap,380, 0, frame.getScreenWidth()-100, frame.getScreenHeight()-100);
  missile.rotate(90);
  int moveFactor = 5;
  for(;;i++){
    frame.clearScreen();
    char lastKey = input.getLastKey();
    if (lastKey != '\0'){
      mainView.updateClipRelative(0,0,0,0);
      if (lastKey == 'w') {
        mainMap.translate(0, -moveFactor);
      } else if (lastKey == 's') {
        mainMap.translate(0,moveFactor);
      } else if (lastKey == 'd') {
        mainMap.translate(moveFactor,0);
      } else if (lastKey == 'a') {
        mainMap.translate(-moveFactor,0);
      } else if (lastKey == '=') {
        mainMap.scale(1.01f, (mainView.xmax-mainView.xmin)/2, (mainView.ymax - mainView.ymin) /2);
      } else if (lastKey == '-') {
        mainMap.scale(0.99f, (mainView.xmax-mainView.xmin)/2, (mainView.ymax - mainView.ymin) /2);
      } else if (lastKey == 'q') {
          break;
      }
    }
    //for(int i = 0; i<shape.size();i++){
    //  frame.draw(shape.at(i));
    //}
    frame.setViewBorder(&miniView, 255, 255, 255);
    frame.draw(&mainView);
    frame.draw(&miniView);
    frame.clearBuffer();
    usleep(30000);
  }
  frame.unmapped();
  frame.closeReading();
  return 0;
}

int StartPlane() {
  int i=1;
  FrameBuffer frame;
  Input input;
  Missile missile(100, 700, 1);
  Plane plane(683,350, 1);
  missile.rotate(90);
  for(;;i++){
    frame.clearScreen();
    plane.draw(&frame);
    if(!missile.CheckCollision(&frame)){
      missile.rotate(-1, 0, 0);
      frame.draw(&missile);
    } else {
      plane.detachWheel();
    }
    
    char lastKey = input.getLastKey();
    if (lastKey == 'q') break;

    frame.clearBuffer();
    usleep(30000);
  }
  frame.unmapped();
  frame.closeReading();
  return 0;
}

CustomShape* readFile(string fileName) {
  FILE *file;
  file = fopen(fileName.c_str(), "r");

  float x, y;
  int numberOfLines;
  if(file != NULL){
    fscanf(file, "%d", &numberOfLines);
    CustomShape* shape = new CustomShape(1, numberOfLines);
    for(int i = 0; i < numberOfLines; i++){
        fscanf(file, "%f %f", &x, &y);

        shape->setDotCoordinate(i, x, y);
    }
    fclose(file);
    return shape;
  } else {
    printf("NULL\n");
    return new CustomShape;
  }
}
