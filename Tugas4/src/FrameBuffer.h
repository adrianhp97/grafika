#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H
#define PI 3.14159265

#include <stdlib.h>
#include <math.h>
#include <cstdlib>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>
#include "Dot.h"
#include "Line.h"
#include "Shape.h"

using namespace std;

class FrameBuffer {
  public:
    FrameBuffer();
    //FrameBuffer(const FrameBuffer&);
    ~FrameBuffer();
    //FrameBuffer& operator=(const FrameBuffer&);

    void checkFixedScreenInformation();
    void checkVariableScreenInformation();
    void mapDeviceToMemory();
    void unmapped();
    void closeReading();
	  void draw(Dot);
    void draw(Line);
    void draw(Shape*);
    void translate(Shape* shape,float, float);
    void scale(Shape*, float);
    void rotate(Shape*,double);
    void clearScreen();
    int getScreenSize();

  private:
    int fbfd;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    size_t screensize;
    char *fbp;
};

#endif
