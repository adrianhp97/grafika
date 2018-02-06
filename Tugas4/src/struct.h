#ifndef STRUCT_H
#define STRUCT_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <unistd.h>

typedef struct {
  int fbfd;
  struct fb_var_screeninfo vinfo;
  struct fb_fix_screeninfo finfo;
  long int screensize;
  char *fbp;
} FrameBuffer;

typedef struct {
  int r;
  int g;
  int b;
  int a;
} RGBa;

typedef struct {
  int x;
  int y;
} Coordinate;

typedef struct {
  int x0;
  int y0;
  int x1;
  int y1;
} Line;

typedef struct {
  Line line[20];
  int nLine;
} Alphabet;

#endif