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

    initiateReading(&frame.fbfd, &frame.vinfo, &frame.finfo);
    frame.screensize = getScreenSize(frame.vinfo, frame.finfo);
    frame.fbp = mapDeviceToMemory(&frame.fbfd, frame.screensize);

    // set memory here

    unmapped(frame.fbp, &frame.screensize);
    closeReading(&frame.fbfd);
    return 0;
}
