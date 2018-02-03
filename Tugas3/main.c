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
    Coordinate point1;
    Coordinate point2;
    setCoordinate(&point1, 500, 300);
    setCoordinate(&point1, 500, 100);
    Line line;
    setLineCoordinate(&line, point1, point2);
    makeLine(frame, &line);
    // int x, y;
    // long int location;
    // for (y = 100; y < 300; y++)
    //     for (x = 100; x < 300; x++) {
    //         Coordinate point;
    //         setCoordinate(&point, x, y);
    //         location = getLocation(frame, point);
    //         if (frame.vinfo.bits_per_pixel == 32) {
    //             RGBa color;
    //             setColor(&color, 200-(y-100)/5, 15+(x-100)/2, 100, 0);
    //             paintPixel(frame.fbp, location, color);
    //     //location += 4;
    //         } else  { //assume 16bpp
    //             int b = 10;
    //             int g = (x-100)/6;     // A little green
    //             int r = 31-(y-100)/16;    // A lot of red
    //             unsigned short int t = r<<11 | g << 5 | b;
    //             *((unsigned short int*)(frame.fbp + location)) = t;
    //         }

    //     }

    unmapped(frame.fbp, &frame.screensize);
    closeReading(&frame.fbfd);
    return 0;
}


//gcc main.c line.c color.c coordinate.c initiate.c print.c -o a