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
#include "struct.h"
#include "initiate.h"
#include "print.h"
#include "color.h"
#include "line.h"

int main()
{
    FrameBuffer frame;

    frame.fbfd = 0;
    frame.screensize = 0;
    frame.fbp = 0;

    // long int location = 0;

    initiateReading(&frame.fbfd, &frame.vinfo, &frame.finfo);
    frame.screensize = getScreenSize(frame.vinfo, frame.finfo);
    frame.fbp = mapDeviceToMemory(&frame.fbfd, frame.screensize);

    // set memory here

    unmapped(frame.fbp, &frame.screensize);
    closeReading(&frame.fbfd);
    return 0;
}
