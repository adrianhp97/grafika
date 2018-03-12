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

using namespace std;

int main(int argc, char* argv[]) {
  int i=1;
  FrameBuffer frame;
  Input input;
  MenuBox menu = new MenuBox(100,100,1,1);
  for(;;) {
    frame.draw(menu);
  }
}
