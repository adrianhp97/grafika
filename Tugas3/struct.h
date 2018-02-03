#ifndef STRUCT_H
#define STRUCT_H

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

#endif