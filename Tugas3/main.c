/*
To test that the Linux framebuffer is set up correctly, and that the device permissions
are correct, use the program below which opens the frame buffer and draws a gradient-
filled red square:
retrieved from:
Testing the Linux Framebuffer for Qtopia Core (qt4-x11-4.2.2)
http://cep.xor.aps.anl.gov/software/qt4-x11-4.2.2/qtopiacore-testingframebuffer.html
*/

#include <stdlib.h>
#include <stdio.h>
#include "print.h"
#include "line.h"

int main()
{
    int fbfd = 0;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    long int screensize = 0;
    char *fbp = 0;
    int x = 0, y = 0;
    long int location = 0;

    initiateReading(&fbfd, &vinfo, &finfo);
    screensize = getScreenSize(vinfo, finfo);
    fbp = mapDeviceToMemory(&fbfd, screensize);

    // set memory here

    unmapped(fbp, &screensize);
    closeReading(&fbfd);
    return 0;
}
