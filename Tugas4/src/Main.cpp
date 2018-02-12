#include <iostream>
#include "FrameBuffer.h"
#include "Color.h"
#include "Dot.h"
#include "Pesawat/Pilot.h"

using namespace std;

int main() {
  int i=1;
  FrameBuffer frame;
  Pilot pilot(600,350, 0.5);
  for(;;i++){
    frame.clearScreen();
    frame.translate(&pilot, 1, 1);
    frame.scale(&pilot, 1.005f);
    frame.rotate(&pilot, 1);
    frame.draw(&pilot);
    usleep(10000);
      //frame.scale(&pilot, 2);
      //frame.draw(&pilot);
    //printf("%d\n", i);
    //printf("%f\n", i*0.01);
  }
  frame.unmapped();
  frame.closeReading();
  return 0;
}
