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
    // printf("%dx%d, %dbpp\n", vinfo.xres, vinfo.yres, vinfo.bits_per_pixel);
    // mapDeviceToMemory(*fbp, &fbfd, screensize);
    fbp = mapDeviceToMemory(&fbfd, screensize);

    x = 100; y = 100;       // Where we are going to put the pixel

    // Figure out where in memory to put the pixel
    for (y = 100; y < 300; y++)
    for (x = 100; x < 300; x++) {

        location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                   (y+vinfo.yoffset) * finfo.line_length;

        if (vinfo.bits_per_pixel == 32) {
            *(fbp + location) = 100;        // Some blue
            *(fbp + location + 1) = 15+(x-100)/2;     // A little green
            *(fbp + location + 2) = 200-(y-100)/5;    // A lot of red
            *(fbp + location + 3) = 0;      // No transparency
    //location += 4;
        } else  { //assume 16bpp
            int b = 10;
            int g = (x-100)/6;     // A little green
            int r = 31-(y-100)/16;    // A lot of red
            unsigned short int t = r<<11 | g << 5 | b;
            *((unsigned short int*)(fbp + location)) = t;
        }

    }
    unmapped(fbp, &screensize);
    closeReading(&fbfd);
    return 0;
}
