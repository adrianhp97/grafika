#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <stdlib.h>
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
    void clearScreen();
    int getScreenSize();
    int getScreenHeight();
    int getScreenWidth();
    void clearBuffer();
    bool isPixelClear(Dot);

  private:
    int fbfd;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    size_t screensize;
    char *fbp;
    char *backbuf;
};

#endif
