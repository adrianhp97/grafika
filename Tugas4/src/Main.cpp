#include <iostream>
#include "FrameBuffer.h"
#include "Color.h"
#include "Dot.h"
#include "Plane.h"
#include "Missile.h"
#include "People.h"
#include "Input.h"
#include "PlaneImage.h"
#include "View.h"

using namespace std;

int main(int argc, char* argv[]) {
  int i=1;
  FrameBuffer frame;
  Input input;
  Missile missile(100, 700, 1);
  //Plane plane(683,350, 1);
  PlaneImage planeImage(250,250,1);
  float inp = atoi(argv[i]);
  View planeView(&planeImage,150,225,350,275);
  missile.rotate(90);
  int moveFactor = inp; 
  for(;;i++){
    frame.clearScreen();
    frame.draw(&planeView);
    char lastKey = input.getLastKey();
    if (lastKey != '\0'){
      planeView.updateClipRelative(0,0,0,0);
      if (lastKey == 'w') {
        planeImage.translate(0, -moveFactor);
      } else if (lastKey == 's') {
        planeImage.translate(0,moveFactor);
      } else if (lastKey == 'd') {
        planeImage.translate(moveFactor,0);
      } else if (lastKey == 'a') {
        planeImage.translate(-moveFactor,0);
      }
    }
    frame.clearBuffer();
    usleep(30000);
  }
  frame.unmapped();
  frame.closeReading();
  return 0;
}
