#ifndef PLANEIMAGE_H
#define PLANEIMAGE_H

#include "Image.h"
#include "Pesawat/Pilot.h"
#include "Pesawat/Wheel.h"
#include "Pesawat/Propeller.h"
#include "Pesawat/Wing.h"
#include "People.h"

class PlaneImage : public Image {
  public:
    PlaneImage(int x, int y, float size);
    ~PlaneImage();
};

#endif
