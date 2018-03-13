#include <iostream>
#include <stdio.h>
#include <vector>
#include "MenuActivities.h"
#include "../FrameBuffer.h"
#include "../Color.h"
#include "../Dot.h"
#include "../Plane.h"
#include "../Missile.h"
#include "../People.h"
#include "../Input.h"
#include "../PlaneImage.h"
#include "../View.h"
#include "../CustomShape.h"
#include "../ItbMapImage.h"
#include "Tugas1.h"

#define MAX_MTX 100
#define LETTER_SPACING 51
#define LINE_SPACING 70
#define X_POS 200

int StartCredit() {
    creditTugas();
	return 0;
}

int StartMap() {
  int i=1;
  FrameBuffer frame;
  Input input;
  vector<CustomShape*> shape;
  vector<CustomShape*> shape2;
  string dest;
  for(int i=2;i<82;i++){
    dest = "../data/" + std::to_string(i) + ".txt";
    shape.push_back(readFile(dest));
    shape2.push_back(readFile(dest));
  }
  //for(i=0;i<shape->getNumberOfVertices();i++){
  //  printf("%f %f", shape->getDot(i)->getX(),shape->getDot(i)->getY());
  //}
  float initScale = 3.0f;
  ItbMapImage map(shape, 0.0f, 0.0f, 1.0f);
  ItbMapImage mainMap(shape2, 200.0f, 0.0f, initScale);
  Missile missile(100, 700, 1);
  //Plane plane(683,350, 1);
  PlaneImage planeImage(150,250,0.5f);
  float inp = 1;
  View miniView(&map,0,0,370,423);
  View mainView(&mainMap,380, 0, frame.getScreenWidth()-100, frame.getScreenHeight()-100);
  missile.rotate(90);
  int moveFactor = 5;
  for(;;i++){
    frame.clearScreen();
    char lastKey = input.getLastKey();
    if (lastKey != '\0'){
      mainView.updateClipRelative(0,0,0,0);
      if (lastKey == 'w') {
        mainMap.translate(0, -moveFactor);
      } else if (lastKey == 's') {
        mainMap.translate(0,moveFactor);
      } else if (lastKey == 'd') {
        mainMap.translate(moveFactor,0);
      } else if (lastKey == 'a') {
        mainMap.translate(-moveFactor,0);
      } else if (lastKey == '=') {
        mainMap.scale(1.01f, (mainView.xmax-mainView.xmin)/2, (mainView.ymax - mainView.ymin) /2);
      } else if (lastKey == '-') {
        mainMap.scale(0.99f, (mainView.xmax-mainView.xmin)/2, (mainView.ymax - mainView.ymin) /2);
      } else if (lastKey == 'q') {
          break;
      }
    }
    //for(int i = 0; i<shape.size();i++){
    //  frame.draw(shape.at(i));
    //}
    frame.setViewBorder(&miniView, 255, 255, 255);
    frame.draw(&mainView);
    frame.draw(&miniView);
    frame.clearBuffer();
    usleep(30000);
  }
  frame.unmapped();
  frame.closeReading();
  return 0;
}

int StartPlane() {
  int i=1;
  FrameBuffer frame;
  Input input;
  Missile missile(100, 700, 1);
  Plane plane(683,350, 1);
  missile.rotate(90);
  for(;;i++){
    frame.clearScreen();
    plane.draw(&frame);
    if(!missile.CheckCollision(&frame)){
      missile.rotate(-1, 0, 0);
      frame.draw(&missile);
    } else {
      plane.detachWheel();
    }
    
    char lastKey = input.getLastKey();
    if (lastKey == 'q') break;

    frame.clearBuffer();
    usleep(30000);
  }
  frame.unmapped();
  frame.closeReading();
  return 0;
}

CustomShape* readFile(string fileName) {
  FILE *file;
  file = fopen(fileName.c_str(), "r");

  float x, y;
  int numberOfLines;
  if(file != NULL){
    fscanf(file, "%d", &numberOfLines);
    CustomShape* shape = new CustomShape(1, numberOfLines);
    for(int i = 0; i < numberOfLines; i++){
        fscanf(file, "%f %f", &x, &y);

        shape->setDotCoordinate(i, x, y);
    }
    fclose(file);
    return shape;
  } else {
    printf("NULL\n");
    return new CustomShape;
  }
}

Credits::Credits() {
  ;
}

/*
	Tugas 1 Grafika
	Kevin Erdiza Yogatama 	- 13515016
	Kukuh Basuki			- 13515025
	Winarto					- 13515061
	Ray Andrew				- 13515073
	Adrian Hartarto			- 13515091
	Martin Lutta			- 13515121
*/
/************ FUNGSI ABSTRAKSI *************/

void SetLine(int grid[50][50], int x0, int y0, int x1, int y1) {
   	int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
  	int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1;
  	int err = (dx>dy ? dx : -dy)/2, e2;

 	for(;;){
		if (grid[x0][y0] == 0)
    		grid[x0][y0] = 1;
    	if (x0==x1 && y0==y1)
			break;
    	e2 = err;
    	if (e2 >-dx) { err -= dy; x0 += sx; }
    	if (e2 < dy) { err += dx; y0 += sy; }
	}
}

void SetLine2(int grid[50][50], int x0, int y0, int x1, int y1) {
   	int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
  	int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1;
  	int err = (dx>dy ? dx : -dy)/2, e2;

 	for(;;){
    	grid[x0][y0] = 2;
    	if (x0==x1 && y0==y1)
			break;
    	e2 = err;
    	if (e2 >-dx) { err -= dy; x0 += sx; }
    	if (e2 < dy) { err += dx; y0 += sy; }
	}
}

void polygonFill(int grid[50][50], int a[20][2], int n) {
	  int i, j, k, dy, dx;
    int x, y, temp;
    int xi[20];
    float slope[20];

    a[n][0] = a[0][0];
    a[n][1] = a[0][1];

    /*- draw polygon -*/
    for (i = 0; i < n; i++) {
		SetLine2(grid, a[i][0], a[i][1], a[i + 1][0], a[i + 1][1]);
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

    for (y = 0; y <= 50; y++) {
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
        SetLine(grid, xi[i], y, xi[i + 1] + 1, y);
        //getch();
      }
    }

}

int clearPixel(char * fbp, long int location) {
    *(fbp + location) = 0;
    *(fbp + location + 1) = 0;
    *(fbp + location + 2) = 0;
    *(fbp + location + 3) = 0;

    return 0;
}

int clearScreen(char * fbp, long int location) {
    int x;
    int y;

    for (y = 100; y < 300; y++) {
        for (x = 100; x < 300; x++) {
            clearPixel(fbp, location);
        }
    }

    return 0;
}

int paintPixel(char * fbp, long int location, int r, int g, int b) {

    *(fbp + location) = b;        // Some blue
    *(fbp + location + 1) = g;     // A little green
    *(fbp + location + 2) = r;    // A lot of red
    *(fbp + location + 3) = 0;      // No transparency

    return 0;
}

void makeDot(int matrix[MAX_MTX][MAX_MTX], int x, int y, int size, int value) {
    int i;
    int j;

    for (i = x; i < x + size; i++) {
        for (j = y; j < y + size; j++) {
            matrix[i][j] = value;
        }
    }
}

void printGrid(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
    int x;
    int y;

    for (x = 0; x < 50; x++) {
        for (y = 0; y < 50; y++) {
            if (grid[x][y] == 1) {
                makeDot(charMatrix, x * 1, y * 1, 1, 1);
            } else if (grid[x][y] == 2) {
				makeDot(charMatrix, x * 1, y * 1, 1, 2);
			}
        }
    }
}

void Set(int grid[50][50], int x, int y) {
    grid[x][y] = 1;
}

void clearGrid(int grid[50][50]) {
    int x;
    int y;
	for (x = 0; x < 50; x++) {
        for (y = 0; y < 50; y++) {
            grid[x][y] = 0;
        }
    }
}

void clearMatrix(int charMatrix[MAX_MTX][MAX_MTX]){
    int x;
    int y;
	for (x = 0; x < MAX_MTX; x++) {
		for (y = 0; y < MAX_MTX; y++) {
			charMatrix[x][y] = 0;
		}
	}
}

/* Cukup tambahin di sini aja, range x & y antara 1 s.d. 15. Di laptopku lebih dari itu segmentation fault */

int SetSolidT(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]){
	clearGrid(grid);
	int a[20][2];
	//x				//y
	a[0][0] = 1;	a[0][1] = 1;
	a[1][0] = 49;	a[1][1] = 1;
	a[2][0] = 49;	a[2][1] = 15;
	a[3][0] = 30;	a[3][1] = 15;
	a[4][0] = 30;	a[4][1] = 49;
	a[5][0] = 18;	a[5][1] = 49;
	a[6][0] = 18;	a[6][1] = 15;
	a[7][0] = 1;	a[7][1] = 15;
	polygonFill(grid, a, 8);

	printGrid(grid, charMatrix);
}


int SetSolidU(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]){
	clearGrid(grid);
	int a[20][2];
	//x				//y
	a[0][0] = 1;	a[0][1] = 1;
	a[1][0] = 10;	a[1][1] = 1;
	a[2][0] = 10;	a[2][1] = 39;
	a[3][0] = 39;	a[3][1] = 39;
	a[4][0] = 39;	a[4][1] = 1;
	a[5][0] = 49;	a[5][1] = 1;
	a[6][0] = 49;	a[6][1] = 49;
	a[7][0] = 1;	a[7][1] = 49;
	polygonFill(grid, a, 8);

	printGrid(grid, charMatrix);
}

int SetSolidN(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]){
	clearGrid(grid);
	int a[20][2];
	//x				//y
	a[0][0] = 1;	a[0][1] = 1;
	a[1][0] = 1;	a[1][1] = 49;
	a[2][0] = 19;	a[2][1] = 49;
	a[3][0] = 19;	a[3][1] = 9;
	a[4][0] = 39;	a[4][1] = 9;
	a[5][0] = 39;	a[5][1] = 49;
	a[6][0] = 49;	a[6][1] = 49;
	a[7][0] = 49;	a[7][1] = 1;
	polygonFill(grid, a, 8);

	printGrid(grid, charMatrix);
}

int SetSolidK(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]){
	clearGrid(grid);
	int a[20][2];
	//x				//y
	a[0][0] = 1;	a[0][1] = 1;
	a[1][0] = 1;	a[1][1] = 49;
	a[2][0] = 19;	a[2][1] = 49;
	a[3][0] = 19;	a[3][1] = 29;
	a[4][0] = 39;	a[4][1] = 49;
	a[5][0] = 49;	a[5][1] = 49;
	a[6][0] = 25;	a[6][1] = 25;
	a[7][0] = 49;	a[7][1] = 1;
	a[8][0] = 39;	a[8][1] = 1;
	a[9][0] = 19;	a[9][1] = 19;
	a[10][0] = 19;	a[10][1] = 1;


	polygonFill(grid, a, 11);

	printGrid(grid, charMatrix);
}

int SetTriangle(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]){
	clearGrid(grid);
	int a[20][2];
	//x				//y
	a[0][0] = 25;	a[0][1] = 1;
	a[1][0] = 49;	a[1][1] = 49;
	a[2][0] = 1;	a[2][1] = 49;
	polygonFill(grid, a, 3);

	printGrid(grid, charMatrix);
}



void Set2(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);
	SetLine(grid, 19, 1, 49, 1);
	SetLine(grid, 28, 1, 9, 49);
	SetLine(grid, 42, 1, 23, 49);
	SetLine(grid, 1, 49, 30, 49);
	printGrid(grid,charMatrix);
	printGrid(grid, charMatrix);
}

void SetA(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);
	SetLine(grid, 1, 49, 25, 1);
	SetLine(grid, 25, 1, 49, 49);
	SetLine(grid, 13, 25, 37, 25);
	printGrid(grid, charMatrix);
}

void SetB(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);
	SetLine(grid, 1, 1, 1, 49);
	SetLine(grid, 1, 1, 49, 13);
	SetLine(grid, 49, 13, 1, 25);
	SetLine(grid, 1, 25, 49, 37);
	SetLine(grid, 49, 37, 1, 49);
	printGrid(grid,charMatrix);
}

void SetD(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);
	SetLine(grid, 1, 1, 1, 49);
	SetLine(grid, 1, 1, 49, 25);
	SetLine(grid, 49, 25, 1, 49);
	printGrid(grid,charMatrix);
}

void SetE(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);
	SetLine(grid, 1, 1, 49, 1);
	SetLine(grid, 1, 1, 1, 49);
	SetLine(grid, 1, 49, 49, 49);
	SetLine(grid, 1, 25, 37, 25);

	printGrid(grid,charMatrix);
}

void SetG(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);
    SetLine(grid, 1, 1, 49, 1);
	SetLine(grid, 1, 1, 1, 49);
	SetLine(grid, 1, 49, 49, 49);
	SetLine(grid, 49, 49, 49, 25);
	SetLine(grid, 30, 25, 49, 25);

	printGrid(grid,charMatrix);
}

void SetH(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);
	SetLine(grid, 1, 1, 1, 49);
	SetLine(grid, 1, 25, 49, 25);
	SetLine(grid, 49, 1, 49, 49);
    printGrid(grid, charMatrix);
}

void SetI(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);
	SetLine(grid, 1, 1, 49, 1);
	SetLine(grid, 25, 1, 25, 49);
	SetLine(grid, 1, 49, 49, 49);
	printGrid(grid,charMatrix);
}

void SetK(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);
	SetLine(grid, 1, 1, 1, 49);
	SetLine(grid, 1, 25, 49, 1);
	SetLine(grid, 1, 25, 49, 49);
	printGrid(grid,charMatrix);
}

void SetM(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);
	SetLine(grid, 1, 1, 1, 49);
	SetLine(grid, 1, 1, 25, 20);
	SetLine(grid, 25, 20, 49, 1);
	SetLine(grid, 49, 1, 49, 49);

    printGrid(grid, charMatrix);
}

void SetN(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);
	SetLine(grid, 1, 1, 1, 49);
	SetLine(grid, 1, 1, 49, 49);
	SetLine(grid, 49, 49, 49, 1);
    printGrid(grid, charMatrix);
}

void SetO(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);
    SetLine(grid, 1, 25, 25, 1);
	SetLine(grid, 25, 1, 49, 25);
	SetLine(grid, 49, 25, 25, 49);
	SetLine(grid, 1, 25, 25, 49);
	printGrid(grid,charMatrix);
}

void SetL(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);
	SetLine(grid, 1, 1, 1, 49);
	SetLine(grid, 1, 49, 49, 49);

	printGrid(grid,charMatrix);
}

void SetR(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);
	SetLine(grid, 1, 1, 1, 49);
	SetLine(grid, 1, 1, 40, 15);
	SetLine(grid, 40, 15, 1, 30);
	SetLine(grid, 1, 30, 49, 49);

	printGrid(grid,charMatrix);
}

void SetS(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);
    SetLine(grid, 1, 1, 49, 1);
	SetLine(grid, 1, 1, 1, 25);
	SetLine(grid, 1, 25, 49, 25);
	SetLine(grid, 49, 25, 49, 49);
	SetLine(grid, 1, 49, 49, 49);

	printGrid(grid,charMatrix);
}

void SetT(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);
	SetLine(grid, 1, 1, 49, 1);
	SetLine(grid, 25, 1, 25, 49);

	printGrid(grid,charMatrix);
}

void SetU(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);
	SetLine(grid, 1, 1, 1, 49);
	SetLine(grid, 49, 1, 49, 49);
	SetLine(grid, 1, 49, 49, 49);
    printGrid(grid, charMatrix);
}

void SetY(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);
	SetLine(grid, 1, 1, 25, 20);
	SetLine(grid, 25, 20, 49, 1);
	SetLine(grid, 25, 20, 25, 49);
	printGrid(grid,charMatrix);
}

void SetW(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX]) {
	clearGrid(grid);
	SetLine(grid, 1, 1, 13, 49);
	SetLine(grid, 13, 49, 25, 27);
	SetLine(grid, 25, 27, 37, 49);
	SetLine(grid, 37, 49, 49, 1);
    printGrid(grid, charMatrix);
}

void SetV(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX])
{
	clearGrid(grid);

	SetLine(grid, 1, 1, 25, 49);
	SetLine(grid, 25, 49, 49, 1);

	printGrid(grid, charMatrix);
}

void SetV2(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX])
{
	clearGrid(grid);

	SetLine(grid, 1, 25, 49, 1);
	SetLine(grid, 1, 25, 49, 49);
	SetLine(grid, 49, 1, 25, 25);
	SetLine(grid, 49, 49, 25, 25);
	printGrid(grid, charMatrix);
}

void SetBullet(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX])
{
	clearGrid(grid);

	SetLine(grid, 13, 20, 25, 1);
	SetLine(grid, 25, 1, 37, 20);
	SetLine(grid, 13, 20, 13, 49);
	SetLine(grid, 37, 20, 37, 49);
	SetLine(grid, 13, 49, 37, 49);
	printGrid(grid, charMatrix);
}

void SetZ(int grid[50][50], int charMatrix[MAX_MTX][MAX_MTX])
{
	clearGrid(grid);

	SetLine(grid, 1, 1, 49, 1);
	SetLine(grid, 49, 1, 1, 49);
	SetLine(grid, 1, 49, 49, 49);

	printGrid(grid, charMatrix);
}

/*****************************************************************/
/* Cukup ubah di bagian Set aja kalau mau nyetak huruf           */
/*****************************************************************/
int Credits::ShowCredits()
{
    int fbfd = 0;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    long int screensize = 0;
    char *fbp = 0;
    char *backbuf = 0;
    int x = 0, y = 0, len = 0;
    long int location = 0;
    int charMatrix[MAX_MTX][MAX_MTX];
	int tugasText[7][MAX_MTX][MAX_MTX];
	int adrianText[15][MAX_MTX][MAX_MTX];
	int kukuhText[12][MAX_MTX][MAX_MTX];
int kevinText[12][MAX_MTX][MAX_MTX];
	int martinText[12][MAX_MTX][MAX_MTX];
	int rayText[10][MAX_MTX][MAX_MTX];
	int winartoText[7][MAX_MTX][MAX_MTX];
	int grid[50][50];

    // Initialize Empty Matrix
	for (len = 0; len < 15; len++) {
		if(len <= 7) {
			clearMatrix(tugasText[len]);
			clearMatrix(winartoText[len]);
		}
		if(len <= 10) {
			clearMatrix(rayText[len]);
		}
		if (len <= 12) {
			clearMatrix(martinText[len]);
clearMatrix(kevinText[len]);
			clearMatrix(kukuhText[len]);
		}
		clearMatrix(adrianText[len]);
	}
    // Initialize Empty Grid
    clearGrid(grid);

    // Open the file for reading and writing
    fbfd = open("/dev/fb0", O_RDWR);
    if (fbfd == -1) {
        perror("Error: cannot open framebuffer device");
        exit(1);
    }
    printf("The framebuffer device was opened successfully.\n");

    // Get fixed screen information
    if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) == -1) {
        perror("Error reading fixed information");
        exit(2);
    }

    // Get variable screen information
    if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
        perror("Error reading variable information");
        exit(3);
    }

    printf("%dx%d, %dbpp\n", vinfo.xres, vinfo.yres, vinfo.bits_per_pixel);

    // Figure out the size of the screen in bytes
    screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;


    // Map the device to memory
    fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
    if (atoi(fbp) == -1) {
        perror("Error: failed to map framebuffer device to memory");
        exit(4);
    }
    printf("The framebuffer device was mapped to memory successfully.\n");

    backbuf = (char *)mmap(0, screensize, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
    if (atoi(backbuf) == -1) {
        perror("Error: failed to map framebuffer device to memory");
        exit(5);
    }
    printf("The framebuffer device was mapped to memory successfully.\n");

    /* Cukup tambahin di sini aja, range x & y antara 1 s.d. 15. Di laptopku lebih dari itu segmentation fault */
	//Tugas 1
	SetSolidT(grid, tugasText[0]);
	SetSolidU(grid, adrianText[1]);

	SetTriangle(grid, kevinText[2]);

	SetSolidN(grid, kukuhText[2]);
	SetSolidK(grid, martinText[2]);

	int i,charLen;
	for(i = vinfo.yres; i > -3*MAX_MTX*1.5; i=i-4) {
        for (y = 0; y < 600; y++){
			int yPosition = (y+i+vinfo.yoffset);
			//printf("yPos = %d\n", yPosition);
			if(yPosition < vinfo.yres-5){
				for (x = 0; x < 1000; x++) {
		            location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
		                        (yPosition) * finfo.line_length;
		            clearPixel(backbuf, location);
		        }
			}
		}
        for (y = 0; y < MAX_MTX; y++){
			int yPosition = (y+i+vinfo.yoffset);
			//Print tugas I
			if(yPosition < vinfo.yres-5) {
				for (charLen = 0; charLen < 1; charLen++) {
				    for (x = X_POS+100; x < X_POS+100+MAX_MTX; x++) {
				        location = ((charLen * LETTER_SPACING) + x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
				                    (yPosition) * finfo.line_length;
				        if (tugasText[charLen][x-X_POS-100][y] == 1) {
				            paintPixel(backbuf, location, 255, 10, 0);
				        } else if (tugasText[charLen][x-X_POS-100][y] == 2) {
				            paintPixel(backbuf, location, 10, 255, 10);
				        }
				    }
				}
			}

			//Print Nama Adrian
			if(yPosition+LINE_SPACING < vinfo.yres-5) {
				for (charLen = 0; charLen < 15; charLen++) {
				    for (x = X_POS; x < X_POS+MAX_MTX; x++) {
				        location = ((charLen * LETTER_SPACING) + x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
				                    (yPosition+LINE_SPACING) * finfo.line_length;
				        if (adrianText[charLen][x-X_POS][y] == 1) {
				            paintPixel(backbuf, location, 200, 20, 20);
				        } else if (adrianText[charLen][x-X_POS][y] == 2) {
				            paintPixel(backbuf, location, 200, 200, 20);
				        }
				    }
				}
			}

			//Print Nama Kukuh
			if(yPosition+2*LINE_SPACING < vinfo.yres-5) {
				for (charLen = 0; charLen < 12; charLen++) {
				    for (x = X_POS; x < X_POS+MAX_MTX; x++) {
				        location = ((charLen * LETTER_SPACING) + x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
				                    (yPosition+2*LINE_SPACING) * finfo.line_length;
				        if (kukuhText[charLen][x-X_POS][y] == 1) {
				            paintPixel(backbuf, location, 200, 140, 100);
				        } else if (kukuhText[charLen][x-X_POS][y] == 2) {
				            paintPixel(backbuf, location, 0, 200, 150);
				        }
				    }
				}
			}

			//Print Nama Kevin
			if(yPosition+3*LINE_SPACING < vinfo.yres-5) {
				for (charLen = 0; charLen < 12; charLen++) {
				    for (x = X_POS; x < X_POS+MAX_MTX; x++) {
				        location = ((charLen * LETTER_SPACING) + x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
				                    (yPosition+3*LINE_SPACING) * finfo.line_length;
				        if (kevinText[charLen][x-X_POS][y] == 1) {
				            paintPixel(backbuf, location, 200, 140, 100);
				        }
				    }
				}
			}

			//Print Nama Martin
			if(yPosition+4*LINE_SPACING < vinfo.yres-5) {
				for (charLen = 0; charLen < 12; charLen++) {
				    for (x = X_POS; x < X_POS+MAX_MTX; x++) {
				        location = ((charLen * LETTER_SPACING) + x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
				                    (yPosition+4*LINE_SPACING) * finfo.line_length;
				        if (martinText[charLen][x-X_POS][y] == 1) {
				            paintPixel(backbuf, location, 100, 150, 150);
				        }
				    }
				}
			}

			//Print Nama Ray
			if(yPosition+5*LINE_SPACING < vinfo.yres-5) {
				for (charLen = 0; charLen < 10; charLen++) {
				    for (x = X_POS; x < X_POS+MAX_MTX; x++) {
				        location = ((charLen * LETTER_SPACING) + x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
				                    (yPosition + 5*LINE_SPACING) * finfo.line_length;
				        if (rayText[charLen][x-X_POS][y] == 1) {
				            paintPixel(backbuf, location, 80, 140, 200);
				        }
				    }
				}
			}

			//Print Nama Winarto
			if(yPosition+6*LINE_SPACING < vinfo.yres-5) {
				for (charLen = 0; charLen < 7; charLen++) {
				    for (x = X_POS; x < X_POS+MAX_MTX; x++) {
				        location = ((charLen * LETTER_SPACING) + x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
				                    (yPosition+6*LINE_SPACING) * finfo.line_length;
				        if (winartoText[charLen][x-X_POS][y] == 1) {
				            paintPixel(backbuf, location, 135, 180, 100);
				        }
				    }
				}
			}
		}


		int copy;
		for (copy=0;copy<screensize;copy++)
		{
			((char *)(fbp))[copy] = backbuf[copy];
		}
       //sleep(1);
    }
    munmap(fbp, screensize);
    close(fbfd);
    return 0;
  }
