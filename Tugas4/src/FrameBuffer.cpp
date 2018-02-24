#include "FrameBuffer.h"

FrameBuffer::FrameBuffer() {
  fbfd = open("/dev/fb0", O_RDWR);
  if (fbfd == -1) {
      perror("Error: cannot open framebuffer device");
      exit(1);
  }

  printf("The framebuffer device was opened successfully.\n");
  checkFixedScreenInformation();
  checkVariableScreenInformation();
  screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;
  mapDeviceToMemory();
}

FrameBuffer::~FrameBuffer() {
  //this->closeReading();
  //delete fbp;
}

bool FrameBuffer::clip(Line* line,float xmin, float ymin, float xmax, float ymax)
{
    float x1 = (*line).getDotSrc()->getX(); float y1 = (*line).getDotSrc()->getY();
    float x2 = (*line).getDotDest()->getX(); float y2 = (*line).getDotDest()->getY();
    int accept = 1;
    int i,j,f=1;
    for(i=0;i<2;i++)
        for(j=0;j<4;j++)
            pixels[i][j]=0;
    if(y1>ymax)
        pixels[0][0]=1;
    if(y1<ymin)
        pixels[0][1]=1;
    if(x1>xmax)
        pixels[0][2]=1;
    if(x1<xmin)
        pixels[0][3]=1;
    if(y2>ymax)
        pixels[1][0]=1;
    if(y2<ymin)
        pixels[1][1]=1;
    if(x2>xmax)
        pixels[1][2]=1;
    if(x2<xmin)
        pixels[1][3]=1;
    for(j=0;j<4;j++)
    {
        if((pixels[0][j]==0)&& (pixels[1][j]==0))
            continue;
        if((pixels[0][j]==1)&& (pixels[1][j]==1))
        {
            f=2;
            break;
        }
        f=3;
    }
    switch(f)
    {
    case 1:
        (*line).getDotDest()->setCoordinate(x2,y2);
        (*line).getDotSrc()->setCoordinate(x1,y1);
        break;
    case 2:
        accept = 0;
        break;
    case 3:
        float xn,yn,xn1,yn1,m;
        m=(y2-y1)/(x2-x1);
        xn=x1;xn1=x2;
        yn=y1;yn1=y2;
        if(pixels[0][0]==1)
        {
            xn=x1+(ymax-y1)/m;
            yn=ymax;
        }
        if(pixels[0][1]==1)
        {
            xn=x1+(ymin-y1)/m;
            yn=ymin;
        }
        if(pixels[0][2]==1)
        {
            yn=y1+(xmax-x1)*m;
            xn=xmax;
        }
        if(pixels[0][3]==1)
        {
            yn=y1+(xmin-x1)*m;
            xn=xmin;
        }
        if(pixels[1][0]==1)
        {
            xn1=x2+(ymax-y2)/m;
            yn1=ymax;
        }
        if(pixels[1][1]==1)
        {
            xn1=x2+(ymin-y2)/m;
            yn1=ymin;
        }
        if(pixels[1][2]==1)
        {
            yn1=y2+(xmax-x2)*m;
            xn1=xmax;
        }
        if(pixels[1][3]==1)
        {
            yn1=y2+(xmin-x2)*m;
            xn1=xmin;
        }
        (*line).getDotSrc()->setCoordinate(xn,yn);
        (*line).getDotDest()->setCoordinate(xn1,yn1);
        break;
      }
      return accept;
}

void FrameBuffer::checkFixedScreenInformation() {
  if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) == -1) {
    perror("Error reading fixed information");
    exit(2);
  }
}

void FrameBuffer::checkVariableScreenInformation() {
  if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
    perror("Error reading variable information");
    exit(3);
  }
}

void FrameBuffer::mapDeviceToMemory() {
  fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
  if (atoi(fbp) == -1) {
      perror("Error: failed to map framebuffer device to memory");
      exit(4);
  }
  printf("The framebuffer device was mapped to memory successfully.\n");
  backbuf = (char *)mmap(0, screensize, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
  if (atoi(backbuf) == -1) {
      perror("Error: failed to map framebuffer device to memory");
      exit(4);
  }
  printf("The backbuffer device was mapped to memory successfully.\n");
}

void FrameBuffer::unmapped() {
  munmap(fbp, screensize);
}

int FrameBuffer::getScreenSize() {
  return vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;
}

int FrameBuffer::getScreenHeight() {
  return vinfo.yres;
}

int FrameBuffer::getScreenWidth() {
  return vinfo.xres;
}

void FrameBuffer::closeReading() {
  close(fbfd);
}

void FrameBuffer::clearBuffer() {
  int copy;
  for (copy=0;copy<screensize;copy++)
  {
    ((char *)(fbp))[copy] = backbuf[copy];
  }
}

void FrameBuffer::draw(Dot pixel) {
  int location = (pixel.getX()+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (pixel.getY()+vinfo.yoffset) * finfo.line_length;
  *(backbuf + location) = pixel.getColor().b;
  *(backbuf + location + 1) = pixel.getColor().g;
  *(backbuf + location + 2) = pixel.getColor().r;
  *(backbuf + location + 3) = pixel.getColor().a;
}

bool FrameBuffer::isPixelClear(Dot pixel) {
  int location = (pixel.getX()+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (pixel.getY()+vinfo.yoffset) * finfo.line_length;

  return (*(backbuf + location) == 0 && *(backbuf + location + 1) == 0 && *(backbuf + location + 2) == 0);
}

void FrameBuffer::draw(Line line) {
  if(clip(&line, 200, 200, vinfo.xres - 200, vinfo.yres-10 - 200)){
    int x0 = line.getDotSrc()->getX(); int x1 = line.getDotDest()->getX();
    int y0 = line.getDotSrc()->getY(); int y1 = line.getDotDest()->getY();
    int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
    int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1;
    int err = (dx>dy ? dx : -dy)/2, e2;

    for(;;){
        Dot pxl(x0,y0,line.getDotSrc()->getColor());
        draw(pxl);
        if (x0==x1 && y0==y1)
        break;
        e2 = err;
        if (e2 >-dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
  }
}

void FrameBuffer::draw(Shape* shape) {
  int i, j, k, dy, dx;
  int x, y, temp;
  int n = (*shape).getNumberOfVertices();
  int a[n][2];
  int xi[n];
  int maxY = 0;
  float slope[n];

  for(i = 0;i < n;i++) {
      a[i][0] = (*shape).getDot(i).getX();
      a[i][1] = (*shape).getDot(i).getY();
      if(maxY < a[i][1])
        maxY = a[i][1];
  }
  a[n][0] = a[0][0];
  a[n][1] = a[0][1];

  /*- draw polygon -*/
  for (i = 0; i < n; i++) {
    draw((*shape).getLine(i));
  }
  //getch();

  for (i = 0; i < n; i++) {
    dy = a[i + 1][1] - a[i][1];
    dx = a[i + 1][0] - a[i][0];
    if (dy == 0) slope[i] = 1.0;
    if (dx == 0) slope[i] = 0.0;
    if ((dy != 0) && (dx != 0)) /*- calculate inverse slope -*/ {
      slope[i] = (float) dx / dy;
    }
  }

  for (y = 0; y <= maxY; y++) {
    k = 0;
    for (i = 0; i < n; i++) {
      if (((a[i][1] <= y) && (a[i + 1][1] > y)) ||
        ((a[i][1] > y) && (a[i + 1][1] <= y))) {
        xi[k] = (int)(a[i][0] + slope[i] * (y - a[i][1]));
        k++;
      }
    }

    for (j = 0; j < k - 1; j++) /*- Arrange x-intersections in order -*/
      for (i = 0; i < k - 1; i++) {
        if (xi[i] > xi[i + 1]) {
          temp = xi[i];
          xi[i] = xi[i + 1];
          xi[i + 1] = temp;
        }
      }
    //setcolor(35);
    for (i = 0; i < k; i += 2) {
      Dot d1(xi[i],y,(*shape).getDot(0).getColor());
      Dot d2(xi[i + 1] + 1, y, (*shape).getDot(0).getColor());
      Line lineTemp(d1,d2);
      draw(lineTemp);
      //getch();
    }
  }
}

void FrameBuffer::draw(Image* image) {
  for(int i = 0; i < image->getNumberOfShapes(); i++) {
    draw(image->getShapePointer(i));
  }
}

void FrameBuffer::clearScreen() {
  int x;
  int y;

  for (y = 0; y < vinfo.yres-10; y++) {
      for (x = 0; x < vinfo.xres; x++) {
        int location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                             (y+vinfo.yoffset) * finfo.line_length;
        *(backbuf + location) = 0;
        *(backbuf + location + 1) = 0;
        *(backbuf + location + 2) = 0;
        *(backbuf + location + 3) = 0;
      }
  }
}
