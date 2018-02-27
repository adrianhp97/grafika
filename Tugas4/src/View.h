#ifndef VIEW_H
#define VIEW_H

#include "Image.h"

class View : public Image  {
  public:
    View(Image*);
    View(Image*, float xmin, float ymin, float xmax, float ymax);
    ~View();

    void clipImage(Image*, float xmin, float ymin, float xmax, float ymax);
    void updateClip(float xmin, float ymin, float xmax, float ymax);
    void updateClipRelative(float xmin, float ymin, float xmax, float ymax);

    Shape* clipShape(Shape* shape,float xmin, float ymin, float xmax, float ymax);

  protected:
    Image* sourceImage;
    float xmin; float ymin; float xmax; float ymax;
};

#endif