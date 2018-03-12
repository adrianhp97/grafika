#include <iostream>
#include <stdio.h>
#include <vector>
#include "FrameBuffer.h"
#include "Color.h"
#include "Dot.h"
#include "Plane.h"
#include "Missile.h"
#include "People.h"
#include "Input.h"
#include "PlaneImage.h"
#include "View.h"
#include "CustomShape.h"
#include "ItbMapImage.h"
#include "Menu/MenuBox.h"
#include "Menu/MenuActivities.h"

using namespace std;

int main(int argc, char* argv[]) {
  FrameBuffer frame;
  float size;
  int state = 0;
  int height = frame.getScreenHeight();
  int width = frame.getScreenWidth();
  Input input;
  MenuBox** menu = new MenuBox*;
  menu[0] = new MenuBox(width/2,height/3,20,1);
  menu[1] = new MenuBox(width/2,120+height/3,20,2);
  menu[2] = new MenuBox(width/2,240+height/3,20,3);
  menu[3] = new MenuBox(width/2,360+height/3,20,4);
  menu[state]->scale(1.5f);

  for(;;) {
    frame.clearScreen();
    char lastKey = input.getLastKey();
    if(lastKey != '\0') {
      if(lastKey == 'B' && state < 3) {
        state++;
        menu[state]->scale(1.5f);
        menu[state-1]->scale(0.66f);
      }
      if(lastKey == 'A' && state > 0) {
        state--;
        menu[state]->scale(1.5f);
        menu[state+1]->scale(0.66f);
      }
      if(lastKey == '\n') {
        //menu[state]->rotate(90);
        switch (state) {
          case 0 : {
            StartMap();
            break;
          }
          case 1 : {
            StartPlane();
            break;
          }
          default : break;
        }
      }
    }
    for(int j=0;j<4;j++) {
      frame.draw(menu[j]);
    }
    frame.clearBuffer();
    usleep(30000);
  }
  frame.unmapped();
  frame.closeReading();
  return 0;
}
