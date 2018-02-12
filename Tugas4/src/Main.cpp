#include <iostream>
#include "FrameBuffer.h"
#include "Color.h"
#include "Dot.h"
#include "Pesawat/Pilot.h"

using namespace std;

int main() {
  int i=0;
  FrameBuffer frame;
  Pilot pilot(500,500, 0.5);
  //for(;;i++){
    //frame.scale(&pilot, 1.5);
    frame.draw(&pilot);
    //printf("%d\n", i);
  //}
  frame.unmapped();
  frame.closeReading();
  return 0;
}
