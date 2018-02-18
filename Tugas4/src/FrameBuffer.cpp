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

int FrameBuffer::getcode(float x, float y){
	int code = 0;
	if(y < 0) code |=TOP;
	if(y > getScreenHeight()-10) code |=BOTTOM;
	if(x < 0) code |=LEFT;
	if(x > getScreenWidth()) code |=RIGHT;
	return code;
}

bool FrameBuffer::clip(Line* line){
  float x1 = (*line).getDotSrc()->getX(); float y1 = (*line).getDotSrc()->getY();
  float x2 = (*line).getDotDest()->getX(); float y2 = (*line).getDotDest()->getY();
	int outcode1=getcode(x1,y1), outcode2=getcode(x2,y2);
	int accept = 0; 	//decides if line is to be drawn
	while(1){
		float m =(float)(y2-y1)/(x2-x1);
		//Both points inside. Accept line
		if(outcode1==0 && outcode2==0){
			accept = 1;
			break;
		}
		//AND of both codes != 0.Line is outside. Reject line
		else if((outcode1 & outcode2)!=0){
			break;
		}else{
			int x,y;
			int temp;
    //  printf("\n%d %d\n", outcode1, outcode2);
    //  printf("\n\nBefore\nx1:%f y1:%f\nx2:%f y2:%f", x1,y1,x2,y2);
			//Decide if point1 is inside, if not, calculate intersection
			if(outcode1==0)
				temp = outcode2;
			else
				temp = outcode1;
			//Line clips top edge
			if(temp & TOP){
				x = x1 + (getScreenHeight()-10-y1)/m;
				y = getScreenHeight()-10;
			}
			else if(temp & BOTTOM){ 	//Line clips bottom edge
				x = x1+ (0-y1)/m;
				y = 0;
			}else if(temp & LEFT){ 	//Line clips left edge
				x = 0;
				y = y1+ m*(0-x1);
			}else if(temp & RIGHT){ 	//Line clips right edge
				x = getScreenWidth();
				y = y1+ m*(getScreenWidth()-x1);
			}
			//Check which point we had selected earlier as temp, and replace its co-ordinates
			if(temp == outcode1){
				x1 = x;
				y1 = y;
        (*line).getDotSrc()->setCoordinate(x1,y1);
				outcode1 = getcode(x1,y1);
			}else{
				x2 = x;
				y2 = y;
        (*line).getDotDest()->setCoordinate(x2,y2);
				outcode2 = getcode(x2,y2);
			}
      //printf("\nAfter\nx1:%f y1:%f\nx2:%f y2:%f", x1,y1,x2,y2);
		}
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
  if(clip(&line)){
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

void FrameBuffer::translate(Shape* shape,float x, float y) {
  int i;
  for(i = 0; i < (*shape).getNumberOfVertices(); i++){
    (*shape).getDots()[i].setX((float)(*shape).getDot(i).getX()+x);
    (*shape).getDots()[i].setY((float)(*shape).getDot(i).getY()+y);
  }
  (*shape).setCenterCoordinate((*shape).getCenterX()+x,(*shape).getCenterY()+y);
}

void FrameBuffer::scale(Shape* shape,float amount, float xCenter, float yCenter) {
  int i;
  translate(shape, -xCenter, -yCenter);
  for(i = 0; i < (*shape).getNumberOfVertices(); i++){
    (*shape).getDots()[i].setX(((float)(*shape).getDot(i).getX()*amount));
    (*shape).getDots()[i].setY(((float)(*shape).getDot(i).getY()*amount));
  }
  (*shape).setCenterCoordinate((*shape).getCenterX()*amount, (*shape).getCenterY()*amount);
  translate(shape, xCenter, yCenter);
}

void FrameBuffer::scale(Shape* shape,float amount) {
  int i;
  float xTemp = (float)(*shape).getCenterX();
  float yTemp = (float)(*shape).getCenterY();
  translate(shape, -xTemp, -yTemp);
  for(i = 0; i < (*shape).getNumberOfVertices(); i++){
    (*shape).getDots()[i].setX(((float)(*shape).getDot(i).getX()*amount));
    (*shape).getDots()[i].setY(((float)(*shape).getDot(i).getY()*amount));
  }
  translate(shape, xTemp, yTemp);
}

void FrameBuffer::rotate(Shape* shape,double degree, float xCenter, float yCenter) {
  int i;
  double sinTheta = sin(degree*PI/180);
  double cosTheta = cos(degree*PI/180);
  translate(shape, -xCenter, -yCenter);
  for(i = 0; i < (*shape).getNumberOfVertices(); i++){
    double x = (double)(*shape).getDot(i).getX();
    double y = (double)(*shape).getDot(i).getY();
    (*shape).getDots()[i].setX((x*cosTheta) - (y*sinTheta));
    (*shape).getDots()[i].setY((x*sinTheta) + (y*cosTheta));
  }
  translate(shape, xCenter, yCenter);
}

void FrameBuffer::rotate(Shape* shape,double degree) {
  int i;
  double sinTheta = sin(degree*PI/180);
  double cosTheta = cos(degree*PI/180);
  float xTemp = (float)(*shape).getCenterX();
  float yTemp = (float)(*shape).getCenterY();
  translate(shape, -xTemp, -yTemp);
  for(i = 0; i < (*shape).getNumberOfVertices(); i++){
    double x = (double)(*shape).getDot(i).getX();
    double y = (double)(*shape).getDot(i).getY();
    (*shape).getDots()[i].setX((x*cosTheta) - (y*sinTheta));
    (*shape).getDots()[i].setY((x*sinTheta) + (y*cosTheta));
  }
  (*shape).setCenterCoordinate((*shape).getCenterX()*cosTheta - (*shape).getCenterY()*sinTheta, (*shape).getCenterX()*sinTheta + (*shape).getCenterY()*cosTheta);
  translate(shape, xTemp, yTemp);
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
