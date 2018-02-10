#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

class FrameBuffer {
  public:
    FrameBuffer();
    FrameBuffer(const FrameBuffer&);
    ~FrameBuffer();
    FrameBuffer& operator=(const FrameBuffer&);

    void checkFixedScreenInformation();
    void checkVariableScreenInformation();
    void mapDeviceToMemory();
    void unmapped();
    void closeReading();

    int getScreenSize();

  private:
    int fbfd;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    long int screensize;
    char *fbp;
}

#endif