#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

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
#include "Image.h"

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
    void draw(Image*);
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
    
    int pixels[2][4];
    bool clip(Line*,float, float, float, float);
};

#endif
