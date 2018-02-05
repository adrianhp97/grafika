#include <stdlib.h>
#include <stdio.h>
#include "alphabet.h"
#include "struct.h"
#include "initiate.h"
#include "print.h"
#include "color.h"
#include "line.h"

int main(int argc, char** argv)
{
    FrameBuffer frame;

    frame.fbfd = 0;
    frame.screensize = 0;
    frame.fbp = 0;

    initiateReading(&frame.fbfd, &frame.vinfo, &frame.finfo);
    frame.screensize = getScreenSize(frame.vinfo, frame.finfo);
    frame.fbp = mapDeviceToMemory(&frame.fbfd, frame.screensize);

    //set grid, refactor later
    int gridXSize = frame.vinfo.xres;
    int gridYSize = frame.vinfo.yres;
    int grid[gridXSize][gridYSize];

    // set memory here
    /*
    Coordinate point1;
    Coordinate point2;
    setCoordinate(&point1, 500, 300);
    setCoordinate(&point2, 500, 100);
    Line line;
    setLineCoordinate(&line, point1, point2);
    makeLineOnGrid(gridYSize,grid,gridXSize, &line);
    */

    //make alphabet and draw it on the grid
    Alphabet alphabet;
    makeE(&alphabet);
    int i;
    for(i = 0; i < alphabet.nLine; i++) {
        makeLineOnGrid(gridYSize,grid,gridXSize,&(alphabet.line[i]));
    }

    //Draw Grid, refactor later
    RGBa color;
    setColor(&color, 2, 213, 32, 0);
    long int location = 0;

    int j;
    for(i = 0; i < gridXSize; i++) {
        for(j = 0; j < gridYSize; j++) {
            if (grid[i][j] == 1){
                Coordinate point;
                setCoordinate(&point, i, j);
                location = getLocation(frame, point);
                paintPixel(frame.fbp, location, color);
            }
        }
    }

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