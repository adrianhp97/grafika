#include <iostream>
#include "FrameBuffer.h"
#include "Color.h"
#include "Dot.h"
#include "Plane.h"
#include "Missile.h"
#include "People.h"
#include "Input.h"
#include "PlaneImage.h"

using namespace std;

int main() {
  int i=1;
  FrameBuffer frame;
  Input input;
  Missile missile(100, 700, 1);
  //Plane plane(683,350, 1);
  PlaneImage planeImage(300,175,1);
  missile.rotate(90);
  for(;;i++){
    frame.clearScreen();
    frame.draw(&planeImage);
    planeImage.rotate(1);
    //plane.draw(&frame);
    //printf("last input : %c \n",input.getLastKey());
    /*f(!missile.CheckCollision(&frame)){
      missile.rotate(-1, 0, 0);
      frame.draw(&missile);
    } else {
      //plane.detachWheel();
    }*/
    frame.clearBuffer();
    usleep(30000);
  }
  frame.unmapped();
  frame.closeReading();
  return 0;
}
