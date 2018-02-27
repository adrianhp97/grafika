#ifndef ITBMAPIMAGE_H
#define ITBMAPIMAGE_H

#include <vector>
#include "CustomShape.h"
#include "Image.h"

using namespace std;

class ItbMapImage : public Image {
  public:
		ItbMapImage(vector<CustomShape*>&,float, float, float);
    ~ItbMapImage();
};

#endif
